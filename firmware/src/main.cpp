// GoodWe Grid-tied Inverter Modbus RS485 Reader
// Berdasarkan GoodWe Modbus Protocol & referensi SEMS AIoT RS485 firmware
// Target Platform: ESP32 (PlatformIO / Arduino Core)

#include <Arduino.h>

#define FW_VERSION "1.0.0"

// ============================================================
// Hardware Pin Constants
// ============================================================
static constexpr int kRs485Rx   = 16;  // ESP32 RX2 -> RO Modbus RS485 module
static constexpr int kRs485Tx   = 17;  // ESP32 TX2 -> DI Modbus RS485 module
static constexpr int kRs485DeRe = 4;   // ESP32 GPIO -> DE & RE jumpered (Set -1 jika auto-flow)

// ============================================================
// GoodWe Modbus Communication Constants
// ============================================================
static constexpr uint8_t  kDefaultSlaveId = 247;   // Default GoodWe factory address: 247 (0xF7)
static constexpr uint32_t kBaudRate       = 9600;  // 9600 8N1
static constexpr uint32_t kPollIntervalMs = 3000;  // Polling interval 3 detik

// ============================================================
// Inverter In-Memory Data Model
// ============================================================
enum InverterType : uint8_t {
  INV_UNKNOWN = 0,
  INV_NON_MT  = 1, // SDTG2, MS, DNS, XS (Single-phase / Small Three-phase)
  INV_MT_SMT  = 2  // MT, SMT (Commercial Three-phase)
};

struct InverterData {
  bool         online        = false;
  InverterType type          = INV_UNKNOWN;
  char         serialNo[17]  = "";
  char         deviceType[11]= "";
  uint16_t     workMode      = 0;     // 0: Wait, 1: Normal, 2: Fault
  uint32_t     errorCode     = 0;
  
  // Solar PV Inputs
  float        vPv1          = 0.0f;  // V
  float        vPv2          = 0.0f;  // V
  float        iPv1          = 0.0f;  // A
  float        iPv2          = 0.0f;  // A

  // Grid Output
  float        vAc1          = 0.0f;  // V
  float        vAc2          = 0.0f;  // V
  float        vAc3          = 0.0f;  // V
  float        iAc1          = 0.0f;  // A
  float        iAc2          = 0.0f;  // A
  float        iAc3          = 0.0f;  // A
  float        fAc           = 0.0f;  // Hz

  // Power & Energy
  uint32_t     pAc           = 0;     // W (Active feeding power)
  float        eDay          = 0.0f;  // kWh
  float        eTotal        = 0.0f;  // kWh
  uint32_t     hTotal        = 0;     // Hours
  float        temperature   = 0.0f;  // Deg C

  uint32_t     lastOkMs      = 0;
};

static InverterData invData;
static uint32_t     lastPollMs = 0;

// ============================================================
// Modbus RTU Helpers (Reference: SEMS AIoT main.cpp)
// ============================================================
static uint16_t modbusCrc(const uint8_t* buf, uint8_t len) {
  uint16_t crc = 0xFFFF;
  for (uint8_t i = 0; i < len; i++) {
    crc ^= buf[i];
    for (uint8_t b = 0; b < 8; b++) {
      crc = (crc & 1) ? (crc >> 1) ^ 0xA001 : (crc >> 1);
    }
  }
  return crc;
}

static inline uint16_t bytesToUint16(const uint8_t* b) {
  return ((uint16_t)b[0] << 8) | b[1];
}

static inline int16_t bytesToInt16(const uint8_t* b) {
  return (int16_t)(((uint16_t)b[0] << 8) | b[1]);
}

static inline uint32_t bytesToUint32(const uint8_t* b) {
  return ((uint32_t)b[0] << 24) | ((uint32_t)b[1] << 16) | ((uint32_t)b[2] << 8) | b[3];
}

static void rs485TxEnable(bool enable) {
  if (kRs485DeRe >= 0) {
    digitalWrite(kRs485DeRe, enable ? HIGH : LOW);
  }
}

// Multi-register FC03 (Read Holding Registers) block read
static bool modbusReadRegsBlock(uint8_t slaveId, uint16_t regAddr, uint16_t count, uint8_t* out, uint16_t outLen) {
  const uint16_t byteCount = count * 2;
  if (outLen < byteCount) return false;

  uint8_t req[8];
  req[0] = slaveId;
  req[1] = 0x03;          // FC03
  req[2] = regAddr >> 8;
  req[3] = regAddr & 0xFF;
  req[4] = count >> 8;
  req[5] = count & 0xFF;

  uint16_t crc = modbusCrc(req, 6);
  req[6] = crc & 0xFF;
  req[7] = crc >> 8;

  while (Serial2.available()) Serial2.read(); // flush FIFO

  rs485TxEnable(true);
  Serial2.write(req, 8);
  Serial2.flush();
  rs485TxEnable(false);

  // Expected frame: SlaveId(1) + FC(1) + ByteCount(1) + Data(byteCount) + CRC(2)
  const uint16_t expectedLen = 3 + byteCount + 2;
  uint32_t t = millis();
  while (Serial2.available() < expectedLen && (millis() - t) < 400) {
    delay(1);
  }

  if (Serial2.available() < expectedLen) {
    return false;
  }

  uint8_t resp[256];
  if (expectedLen > sizeof(resp)) return false;
  Serial2.readBytes(resp, expectedLen);

  // Check CRC
  uint16_t rcrc = modbusCrc(resp, expectedLen - 2);
  if (resp[expectedLen - 2] != (rcrc & 0xFF) || resp[expectedLen - 1] != (rcrc >> 8)) {
    return false;
  }

  // Check Slave ID & Function Code
  if (resp[0] != slaveId || resp[1] != 0x03 || resp[2] != byteCount) {
    return false;
  }

  memcpy(out, &resp[3], byteCount);
  return true;
}

// ============================================================
// GoodWe Inverter Polling Logic
// ============================================================

// Baca Serial Number (Reg 512, 8 reg) & Device Type (Reg 528, 5 reg)
static bool readInverterInfo(uint8_t slaveId) {
  uint8_t buf[16];

  // Serial Number: 512 (0x0200) -> 8 registers (16 bytes ASCII)
  if (modbusReadRegsBlock(slaveId, 512, 8, buf, sizeof(buf))) {
    memcpy(invData.serialNo, buf, 16);
    invData.serialNo[16] = '\0';
  } else {
    return false;
  }

  delay(60); // RS485 bus settling

  // Device Type: 528 (0x0210) -> 5 registers (10 bytes ASCII)
  if (modbusReadRegsBlock(slaveId, 528, 5, buf, 10)) {
    memcpy(invData.deviceType, buf, 10);
    invData.deviceType[10] = '\0';
  }

  return true;
}

// Polling model Non-MT (SDTG2, MS, DNS, XS) -> Registers 544..566 (23 registers)
static bool pollNonMTSeries(uint8_t slaveId) {
  uint8_t buf[46]; // 23 registers * 2 bytes

  if (!modbusReadRegsBlock(slaveId, 544, 23, buf, sizeof(buf))) {
    return false;
  }

  auto getU16 = [&](uint16_t reg) -> uint16_t {
    uint16_t offset = (reg - 544) * 2;
    return bytesToUint16(&buf[offset]);
  };

  auto getU32 = [&](uint16_t reg) -> uint32_t {
    uint16_t offset = (reg - 544) * 2;
    return bytesToUint32(&buf[offset]);
  };

  invData.errorCode   = getU32(544);
  invData.eTotal      = getU32(546) * 0.1f;
  invData.hTotal      = getU32(548);
  invData.vPv1        = getU16(550) * 0.1f;
  invData.vPv2        = getU16(551) * 0.1f;
  invData.iPv1        = getU16(552) * 0.1f;
  invData.iPv2        = getU16(553) * 0.1f;
  invData.vAc1        = getU16(554) * 0.1f;
  invData.vAc2        = getU16(555) * 0.1f;
  invData.vAc3        = getU16(556) * 0.1f;
  invData.iAc1        = getU16(557) * 0.1f;
  invData.iAc2        = getU16(558) * 0.1f;
  invData.iAc3        = getU16(559) * 0.1f;
  invData.fAc         = getU16(560) * 0.01f;
  invData.pAc         = getU16(563);
  invData.workMode    = getU16(564);
  invData.temperature = getU16(565) * 0.1f;
  invData.eDay        = getU16(566) * 0.1f;

  invData.type        = INV_NON_MT;
  invData.online      = true;
  invData.lastOkMs    = millis();
  return true;
}

// Polling model MT / SMT (Three-phase Commercial) -> Registers 768..788 (21 registers) & 850 (2 registers)
static bool pollMTSeries(uint8_t slaveId) {
  uint8_t buf[42]; // 21 registers * 2 bytes

  if (!modbusReadRegsBlock(slaveId, 768, 21, buf, sizeof(buf))) {
    return false;
  }

  auto getU16 = [&](uint16_t reg) -> uint16_t {
    uint16_t offset = (reg - 768) * 2;
    return bytesToUint16(&buf[offset]);
  };

  auto getU32 = [&](uint16_t reg) -> uint32_t {
    uint16_t offset = (reg - 768) * 2;
    return bytesToUint32(&buf[offset]);
  };

  invData.vPv1        = getU16(768) * 0.1f;
  invData.vPv2        = getU16(769) * 0.1f;
  invData.iPv1        = getU16(770) * 0.1f;
  invData.iPv2        = getU16(771) * 0.1f;
  invData.vAc1        = getU16(772) * 0.1f;
  invData.vAc2        = getU16(773) * 0.1f;
  invData.vAc3        = getU16(774) * 0.1f;
  invData.iAc1        = getU16(775) * 0.1f;
  invData.iAc2        = getU16(776) * 0.1f;
  invData.iAc3        = getU16(777) * 0.1f;
  invData.fAc         = getU16(778) * 0.01f;
  invData.workMode    = getU16(782);
  invData.temperature = getU16(783) * 0.1f;
  invData.errorCode   = getU32(784);
  invData.eTotal      = getU32(786) * 0.1f;
  invData.hTotal      = getU32(788);

  delay(60); // RS485 bus settling

  // Baca Daya Output MT/SMT: Register 850 (U32)
  uint8_t pBuf[4];
  if (modbusReadRegsBlock(slaveId, 850, 2, pBuf, sizeof(pBuf))) {
    invData.pAc = bytesToUint32(pBuf);
  }

  // Baca E-Day MT/SMT: Register 800 (U16)
  uint8_t edBuf[2];
  if (modbusReadRegsBlock(slaveId, 800, 1, edBuf, sizeof(edBuf))) {
    invData.eDay = bytesToUint16(edBuf) * 0.1f;
  }

  invData.type     = INV_MT_SMT;
  invData.online   = true;
  invData.lastOkMs = millis();
  return true;
}

// Cetak hasil pembacaan ke Serial Console
static void printInverterSummary() {
  const char* modeStr = "Unknown";
  if (invData.workMode == 0) modeStr = "Wait / Self-Test";
  else if (invData.workMode == 1) modeStr = "Normal Generation";
  else if (invData.workMode == 2) modeStr = "Fault";

  Serial.println("\n================ GOODWE TELEMETRY ================");
  Serial.printf("Status       : %s (Last OK: %lu ms ago)\n", invData.online ? "ONLINE" : "OFFLINE", millis() - invData.lastOkMs);
  if (strlen(invData.serialNo) > 0) {
    Serial.printf("Serial No    : %s | Model: %s\n", invData.serialNo, invData.deviceType);
  }
  Serial.printf("Type Detected: %s\n", invData.type == INV_NON_MT ? "Non-MT (SDTG2/MS/DNS/XS)" : "MT / SMT");
  Serial.printf("Work Mode    : %u [%s] | Error Code: 0x%08X\n", invData.workMode, modeStr, invData.errorCode);
  Serial.printf("Internal Temp: %.1f deg C\n", invData.temperature);
  Serial.println("--- SOLAR PV INPUT ---");
  Serial.printf("PV1: %.1f V  |  %.1f A  (%.0f W)\n", invData.vPv1, invData.iPv1, invData.vPv1 * invData.iPv1);
  Serial.printf("PV2: %.1f V  |  %.1f A  (%.0f W)\n", invData.vPv2, invData.iPv2, invData.vPv2 * invData.iPv2);
  Serial.println("--- AC GRID OUTPUT ---");
  Serial.printf("V Grid (L1/L2/L3) : %.1f V / %.1f V / %.1f V\n", invData.vAc1, invData.vAc2, invData.vAc3);
  Serial.printf("I Grid (L1/L2/L3) : %.1f A / %.1f A / %.1f A\n", invData.iAc1, invData.iAc2, invData.iAc3);
  Serial.printf("Frequency         : %.2f Hz\n", invData.fAc);
  Serial.println("--- POWER & ENERGY ---");
  Serial.printf("Active Power (Pac): %u W\n", invData.pAc);
  Serial.printf("Energy Today      : %.1f kWh\n", invData.eDay);
  Serial.printf("Total Generation  : %.1f kWh  (Total: %u Hours)\n", invData.eTotal, invData.hTotal);
  Serial.println("==================================================\n");
}

static void pollInverter() {
  // Coba baca info mesin jika belum terbaca
  if (strlen(invData.serialNo) == 0) {
    readInverterInfo(kDefaultSlaveId);
    delay(100);
  }

  // Coba polling model Non-MT terlebih dahulu
  bool ok = pollNonMTSeries(kDefaultSlaveId);
  if (!ok) {
    delay(100);
    // Jika gagal, coba polling model MT/SMT
    ok = pollMTSeries(kDefaultSlaveId);
  }

  if (ok) {
    printInverterSummary();
  } else {
    invData.online = false;
    Serial.printf("[Modbus RTU] Timeout / Response Error from Slave ID %u\n", kDefaultSlaveId);
  }
}

// ============================================================
// Setup & Main Loop
// ============================================================
void setup() {
  Serial.begin(115200);
  delay(1000);

  if (kRs485DeRe >= 0) {
    pinMode(kRs485DeRe, OUTPUT);
    digitalWrite(kRs485DeRe, LOW); // Default listening mode
  }

  // Inisialisasi Hardware Serial2 ESP32 (8N1)
  Serial2.begin(kBaudRate, SERIAL_8N1, kRs485Rx, kRs485Tx);

  Serial.println("\n------------------------------------------------");
  Serial.println(" GoodWe Modbus RS485 Inverter Reader initialized ");
  Serial.printf(" Serial2 pins: RX=%d, TX=%d, DE/RE=%d\n", kRs485Rx, kRs485Tx, kRs485DeRe);
  Serial.printf(" Modbus RTU : Baud=%d, SlaveId=%d (0x%02X)\n", kBaudRate, kDefaultSlaveId, kDefaultSlaveId);
  Serial.println("------------------------------------------------\n");
}

void loop() {
  uint32_t now = millis();
  if (now - lastPollMs >= kPollIntervalMs) {
    lastPollMs = now;
    pollInverter();
  }
}
