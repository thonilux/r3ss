# GoodWe Modbus RTU

Ekstraksi dari `GoodWe Modbus Protocol of Inverter - Grid-tied MTG2/SMT/SDTG2/MS/DNS/XS series (Customer Version)`, versi dokumen 2024-10-22.

## Parameter komunikasi

- Mode: Modbus RTU
- Baud rate: `9600 bps`
- Format byte: 8 data bit, 1 start bit (`0`), 1 stop bit (`1`), least-significant bit first
- Alamat perangkat: `1-247`; default sebelum pengiriman: `247`
- Function code `03H`: membaca satu atau beberapa register berurutan
- Function code `10H`: menulis satu data; waktu RTC harus ditulis bersama
- Register memakai alamat desimal pada dokumen

## Format frame

### Read Holding Register (`03H`)

Request:

```text
[Device Address] [03H] [Register Address Hi] [Register Address Lo]
[Register Count Hi] [Register Count Lo] [CRC Lo] [CRC Hi]
```

Normal response:

```text
[Device Address] [03H] [Byte Count] [Data ...] [CRC Lo] [CRC Hi]
```

### Write Multiple Registers (`10H`)

Request:

```text
[Device Address] [10H] [Register Address Hi] [Register Address Lo]
[Register Count Hi] [Register Count Lo] [Byte Count] [Data ...]
[CRC Lo] [CRC Hi]
```

Successful response:

```text
[Device Address] [10H] [Register Address Hi] [Register Address Lo]
[Register Count Hi] [Register Count Lo] [CRC Lo] [CRC Hi]
```

CRC-16 dihitung mulai byte pertama sampai byte sebelum CRC low byte. Urutan transmisi checksum adalah CRC low byte lalu CRC high byte.

## Tipe data dan hak akses

| Tipe | Keterangan |
|---|---|
| `U16` | unsigned 16-bit |
| `S16` | signed 16-bit |
| `U32` | unsigned 32-bit; high word di depan, low word di belakang |
| `S32` | signed 32-bit; high word di depan, low word di belakang |
| `RO` | read-only |
| `WO` | write-only |
| `RW` | read/write |
| `STR` | string ASCII |

Nilai aktual = nilai register dibagi `10^SF Gain`, kecuali dinyatakan lain.

## Register konfigurasi dan kontrol

| Address | Name | R/W | Type | Len | SF | Unit | Range / catatan |
|---:|---|---|---|---:|---:|---|---|
| 0 | Power on voltage | RW | U16 | 1 | 10 | V | 60.0-600.0 |
| 1 | Reconnect time | RW | U16 | 1 | 1 | s | 0-1200 |
| 2 | Lower limit of grid voltage | RW | U16 | 1 | 10 | V | 0.15 Vn-1 Vn |
| 3 | Upper limit of grid voltage | RW | U16 | 1 | 10 | V | 1 Vn-1.36 Vn |
| 4 | Lower limit of grid frequency | RW | U16 | 1 | 100 | Hz | 45.00-60.00 |
| 5 | Upper limit of grid frequency | RW | U16 | 1 | 100 | Hz | 50.00-65.00 |
| 16 | Device RTC Year/Month | RW | U16 | 1 | 1 | - | MSB=year, LSB=month |
| 17 | Device RTC Day/Hour | RW | U16 | 1 | 1 | - | MSB=day, LSB=hour |
| 18 | Device RTC Minute/Second | RW | U16 | 1 | 1 | - | MSB=minute, LSB=second |
| 256 | Active power adjust | RW | U16 | 1 | 1 | % | 0-100; single-phase write-only dan tidak menyimpan |
| 257 | PF reactive power adjust | RW | U16 | 1 | 1 | - | 1-20 atau 80-100; single-phase write-only |
| 258 | Reactive power adjust | RW | S32 | 2 | 1 | Var | -60% Pn sampai 60% Pn; single-phase tidak mendukung |
| 262 | ARP limit adjust range | WO | S16 | 1 | 1 | % | high byte=marge, low byte=instruction ID |
| 265 | Reactive power adjust | RW | S16 | 1 | 1 | % | -60 sampai 60; single-phase tidak mendukung |
| 267 | Export power limit communication timeout | RW | U16 | 1 | - | s | 1-65535; SMT saja |
| 288 | Power On / allow on-grid self-test | WO | U16 | 1 | 1 | - | tulis `0` untuk aktif |
| 289 | Power Off / disallow on-grid self-test | WO | U16 | 1 | 1 | - | tulis `0` untuk aktif |
| 290 | Restart | WO | U16 | 1 | 1 | - | tulis `0` untuk aktif |
| 291 | On-grid export power limit switch | RW | U16 | 1 | 1 | - | 0=off, 1=on; SDTG2/SMT |
| 292 | ARP power percentage | RW | U16 | 1 | 1 | % | 0-100; SDTG2/SMT |
| 293 | Active control adjust | RW | U16 | 1 | 10 | % | 0-100.0; MT, ARM 11 |
| 312 | Shadow mode switch | RW | U16 | 1 | 1 | - | 0=off, 1=on |
| 512 | Device serial number | RO | STR | 8 | 1 | - | ASCII, 16 byte |
| 528 | Device type | RO | STR | 5 | 1 | - | ASCII |

## Register telemetri umum (544-566)

| Address | Name | Type | Len | SF | Unit | Catatan |
|---:|---|---|---:|---:|---|---|
| 544 | Error message | U32 | 2 | 1 | - | lihat tabel error |
| 546 | Total feed energy to grid | U32 | 2 | 10 | kWh | total energi |
| 548 | Total feeding hours | U32 | 2 | 1 | h | total waktu |
| 550-551 | Vpv1/Vpv2 input voltage | U16 | 1 | 10 | V | PV2 tidak untuk single-MPPT |
| 552-553 | Ipv1/Ipv2 input current | U16 | 1 | 10 | A | PV2 tidak untuk single-MPPT |
| 554-556 | Vac1/Vac2/Vac3 phase voltage | U16 | 1 | 10 | V | phase L1/L2/L3 |
| 557-559 | Iac1/Iac2/Iac3 phase current | U16 | 1 | 10 | A | phase L1/L2/L3 |
| 560-562 | Fac1/Fac2/Fac3 frequency | U16 | 1 | 100 | Hz | phase L1/L2/L3 |
| 563 | Pac L / inverter output power | U16 | 1 | 1 | W | non-MT/SMT |
| 564 | Work mode | U16 | 1 | 1 | - | 0=wait, 1=normal, 2=fault |
| 565 | Inverter internal temperature | U16 | 1 | 10 | °C | - |
| 566 | E-Day / daily generation | U16 | 1 | 10 | kWh | energi hari ini |

## Register telemetri MT/SMT (768-896)

| Address | Name | Type | Len | SF | Unit / catatan |
|---:|---|---|---:|---:|---|
| 768-771 | Vpv1/Vpv2, Ipv1/Ipv2 | U16 | 1 | 10 | V atau A |
| 772-774 | Vac1/Vac2/Vac3 | U16 | 1 | 10 | V, phase L1-L3 |
| 775-777 | Iac1/Iac2/Iac3 | U16 | 1 | 10 | A, phase L1-L3 |
| 778-780 | Fac1/Fac2/Fac3 | U16 | 1 | 100 | Hz |
| 782 | Work mode | U16 | 1 | 1 | 0=wait, 1=normal, 2=fault |
| 783 | Inverter internal temperature | U16 | 1 | 10 | °C |
| 784 | Error message | U32 | 2 | 1 | failure description |
| 786 | Total feed energy to grid | U32 | 2 | 10 | kWh |
| 788 | Total feeding hours | U32 | 2 | 1 | h |
| 790 | Firmware version DSP | U16 | 1 | 1 | - |
| 791 | Warning code | U16 | 1 | 1 | - |
| 793 | Function status bits | U16 | 1 | 1 | lihat Table 8-3 |
| 796-797 | BUS/NBUS voltage | U16 | 1 | 10 | V |
| 799 | Safety code | U16 | 1 | 1 | - |
| 800 | Daily power generation | U16 | 1 | 10 | kWh |
| 804/806 | Vpv5/Vpv6 | U16 | 1 | 10 | V; SMT50/60K |
| 805/807 | Ipv5/Ipv6 | U16 | 1 | 10 | A; SMT50/60K |
| 814 | Power factor | S16 | 1 | 1000 | -; SMT saja |
| 827-829 | RTC Year:Month, Date:Hour, Minute:Second | U16 | 1 | 1 | byte tinggi/rendah |
| 830 | Manufacture ID | U16 | 1 | 1 | - |
| 831 | Wireless signal strength | U16 | 1 | 1 | % |
| 850 | Feeding power | U32 | 2 | 1 | W |
| 852 | Firmware version ARM | U16 | 1 | 1 | - |
| 853 | GPRS burn-in mode | U16 | 1 | 1 | 0x00=normal |
| 855-858 | Vpv3/Vpv4/Ipv3/Ipv4 | U16 | 1 | 10 | V atau A |
| 859-874 | PV string current 1-16 | U16 | 1 | 10 | A |
| 879 | PID & SPD status | U16 | 1 | 1 | lihat Table 8-6 |
| 880 | Output control state | U16 | 1 | 1 | Jepang: 0=unprotected, 1=protected |
| 886 | Power factor | U16 | 1 | 1000 | MT/SDTG2 |
| 893 | AC reactive power | S32 | 2 | 1000 | kVar; MT/SMT/SDTG2 |
| 895 | ISO detection value | U16 | 1 | 1 | K |
| 896 | Leak current value | U16 | 1 | 1 | mA |

## Register tambahan

| Address | Name | R/W | Type | Len | SF | Unit / catatan |
|---:|---|---|---|---:|---:|---|
| 1000, 1002, 1004 | Current R/S/T phase size | RO | U32 | 2 | 10 | A; MT/SMT Korea |
| 1006, 1008, 1010 | Current R/S/T phase voltage | RO | U32 | 2 | 10 | V; MT/SMT Korea |
| 1012 | 3-phase effective power | RO | U32 | 2 | 10 | kW; MT/SMT Korea |
| 1014 | 3-phase ineffective power | RO | U32 | 2 | 10 | kW; MT/SMT Korea |
| 1016 | 3-phase power factor | RO | S32 | 2 | 1000 | -; MT/SMT Korea |
| 1018 | Frequency | RO | U32 | 2 | 10 | Hz; MT/SMT Korea |
| 1020 | Status Flag 1 | RO | U32 | 2 | 1 | bit 1=working, bit 2=CB, bit 3=operation mode |
| 2000 | PF | WR | S16 | 1 | 1000 | MT saja |
| 2001 | Work and mode | WR | U16 | 1 | 1 | 0=separate, 2=power rate, 5=Q(V) |
| 2002 | Reactive power adjust | WR | S16 | 1 | 10 | -600 sampai 600 % |
| 2003 | Active control adjust | WR | U16 | 1 | 10 | 0-100.0 % |
| 30115/30116/30117 | Phase voltage AB/BC/CA | RO | U16 | 1 | 10 | V; SMT/SDTG2 |
| 30133 | AC apparent power | RO | U32 | 2 | 1000 | kVA; SMT/SDTG2 |
| 30137 | Input general power | RO | S32 | 2 | 1000 | kW; SMT/SDTG2 |
| 32086 | Efficiency | RO | U16 | 1 | 100 | %; SMT/SDTG2 |
| 37207 | Run Flag 7 | RO | U16 | 1 | 1 | bit field; SMT/SDTG2 |

## Bit status penting

### Function Status Bits (register 793)

- Bit 15: High impedance flag
- Bit 14: Ground fault flag (`1=NG`, `0=OK`)
- Bit 12: Battery activation (ES)
- Bit 11: Export power limit (ES)
- Bit 10: EMS mode (ES)
- Bit 9: Auto battery management (ES)
- Bit 8: Meter (`1=OK`, `0=NG`)
- Bit 7: MPPT shadow scan
- Bit 3: Power limit function
- Bit 2: Burn-in mode
- Bit 1: LVRT
- Bit 0: Anti-islanding function

### Run Flag 7 (register 37207)

- Bit 6 (`0x40`): Fault
- Bit 4 (`0x10`): Self-reducing grid connection
- Bit 3 (`0x08`): Grid connection with power limitation/derating
- Bit 2 (`0x04`): Normal grid connection
- Bit 1 (`0x02`): Grid connection
- Bit 0 (`0x01`): Standby

## Contoh frame

Semua byte ditulis heksadesimal dan CRC dikirim low byte lebih dahulu.

### Set active power 50%

Request:

```text
F7 10 01 00 00 01 02 00 32 18 E1
```

Response:

```text
F7 10 01 00 00 01 14 A3
```

### Read active power setting

Request:

```text
F7 03 01 00 00 01 91 60
```

Response untuk nilai 50:

```text
F7 03 02 00 32 F1 84
```

### Read feeding power (register 850-851)

Request:

```text
F7 03 03 52 00 02 71 08
```

Response `1110 W`:

```text
F7 03 04 00 00 04 56 EE C2
```

### Set reactive power 3220 Var (register 258)

Request:

```text
F7 10 01 02 00 02 04 00 00 0C 94 66 C2
```

### Set PF +0.9 (register 257)

Request:

```text
F7 10 01 01 00 01 02 00 5A 18 DE
```

Nilai `90` merepresentasikan PF `+0.9`.

## Catatan kompatibilitas

Beberapa register hanya berlaku untuk model tertentu. Catatan model pada tabel harus dipatuhi; register yang tidak didukung dapat mengembalikan error atau tidak berdampak. Rentang aktual dapat berbeda menurut model dan hasil frame write dari inverter menjadi acuan akhir.
