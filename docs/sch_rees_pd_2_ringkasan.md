# Ringkasan Skematik REES Controller

Sumber: [sch_rees_pd_2.pdf](sch_rees_pd_2.pdf)  
Jumlah halaman PDF: 17  
Identitas pada title block: **REES Controller**, revisi **1.0**, KiCad E.D.A. **10.0.6**.

## 1. Gambaran umum

Dokumen merupakan skematik perangkat keras controller dengan dua prosesor: **STM32F407VGTx** sebagai pusat koneksi periferal kabel dan akuisisi data, serta **ESP32-S3-WROOM-2** yang terhubung ke LoRa, modem EC200, CAN bus, dan konektor layar. Kedua prosesor berkomunikasi melalui UART; STM32 juga mempunyai jalur reset menuju ESP32.

Pembagian fungsi ini disimpulkan dari hubungan antarkomponen pada skematik. Dokumen tidak menjelaskan firmware, protokol aplikasi, atau alur operasi sistem.

Fasilitas utama yang terlihat:

- Tiga kanal RS485 berlabel isolator.
- Ethernet W5500 dan modem eksternal EC200.
- LoRa RFM95W serta CAN bus berbasis MCP2515.
- Empat kanal masukan analog melalui ADS1115 dan pengondisi sinyal.
- Dua masukan digital dengan optocoupler dan dua keluaran relay.
- Flash eksternal, EEPROM, microSD, dan RTC dengan suplai cadangan.
- Konektor TFT untuk STM32 dan ESP32, serta konektor pemrograman/debug.

## 2. Daftar isi per halaman PDF

Nomor berikut mengikuti urutan halaman PDF, karena nomor sheet pada title block tidak selalu sama.

| Halaman | Blok | Isi utama |
| --- | --- | --- |
| 1 | Koneksi periferal | Hubungan STM32, ESP32, catu daya, memori, ADC, RTC, Ethernet, RS485, microSD, TFT, dan I/O. |
| 2 | CPU STM32 | STM32F407VGTx, kristal 8 MHz dan 32,768 kHz, reset, BOOT0, SWD, baterai cadangan, dan pemetaan pin. |
| 3 | CPU ESP32-S3 | ESP32-S3-WROOM-2, UART ke STM32 dan EC200, koneksi SPI ke LoRa/CAN/TFT, serta header pemrograman. |
| 4 | Flash | W25Q128JVS dengan antarmuka SPI dan suplai 3,3 V. |
| 5 | Ethernet | Modul W5500 Mini melalui SPI, dengan sinyal interrupt dan reset. |
| 6 | EEPROM | CAT24C256 melalui I2C, jumper alamat A0/A1/A2, dan write protect. |
| 7 | RTC | DS3231M melalui I2C, suplai VBAT, dan sinyal reset. |
| 8 | ADC eksternal | ADS1115, empat kanal pengondisi sinyal TLV9004, proteksi masukan, dan pembagi tegangan. |
| 9 | Catu daya | Masukan 24 VDC, modul XL4015 menuju 12 V, regulator MIC29302AWU menuju 5 V dan 3,3 V. |
| 10 | MicroSD | Soket microSD yang digunakan dalam mode SPI. |
| 11 | EC200 | Header delapan pin untuk modem eksternal. |
| 12 | RS485 kanal 1 | Modul isolator RS485 dengan terminal A+, B-, dan GND_E. |
| 13 | LoRa | RFM95W, SPI, DIO0/interrupt, reset, konektor antena SMA, dan test point. |
| 14 | CAN bus | MCP2515, kristal 8 MHz, transceiver SN65HVD230D, dan resistor terminasi 120 ohm. |
| 15 | RS485 kanal 2 | Modul isolator RS485 kedua. |
| 16 | RS485 kanal 3 | Modul isolator RS485 ketiga. |
| 17 | Digital I/O | Dua masukan PC817 dan dua relay dengan optocoupler, transistor driver, LED, dan dioda flyback. |

## 3. Arsitektur prosesor dan bus

### STM32F407VGTx

STM32 terhubung ke ADC, RTC, EEPROM, Ethernet, flash, microSD, tiga RS485, TFT, serta I/O digital. Skematik menyediakan SWD untuk pemrograman/debug dan BOOT0 dengan resistor pull-down. Suplai analog VDDA menggunakan ferrite bead; pin VCAP memiliki kapasitor tersendiri.

Pemetaan penting yang terbaca pada halaman CPU:

| Fungsi | Pin STM32 / sinyal |
| --- | --- |
| UART ke ESP32 | PA2 = ESP32_TX, PA3 = ESP32_RX |
| RS485-1 | PD8 = TX, PD9 = RX, PD0 = DE/RE |
| RS485-2 | PA9 = TX, PA10 = RX, PD1 = DE/RE |
| RS485-3 | PC6 = TX, PC7 = RX, PB0 = DE/RE |
| SPI bersama | PB3 = SCK, PB4 = MISO, PB5 = MOSI |
| Pemilihan periferal SPI | PA15 = flash CS, PB12 = W5500 CS, PA4 = microSD CS, PB8 = TFT CS |
| I2C | PB6 = SCL, PB7 = SDA |
| ADC alert | PA1 |
| Ethernet | PC4 = interrupt, PC5 = reset |
| TFT | PB9 = DC, PB10 = reset |
| Digital I/O pada sheet utama | PA5 = IN_0, PA6 = IN_1, PC0 = OUT_0, PC1 = OUT_1 |
| Reset ESP32 | PC3 |
| Reset RTC | PC13 |
| SWD | PA13 = SWDIO, PA14 = SWCLK |

Nama TX/RX di atas mengikuti label sheet STM32. Pada integrasi firmware, cocokkan arah sinyal dengan pin penerima/pengirim di sheet ESP32.

### ESP32-S3-WROOM-2

ESP32 terhubung ke STM32 melalui GPIO17/18 dengan label ESP_TX_STM32 dan ESP_RX_STM32. LoRa, CAN controller, dan TFT berbagi jalur SPI, dengan chip select masing-masing. Modem EC200 menggunakan UART serta jalur PWR_KEY, reset, dan sleep. Tersedia header pemrograman TX, RX, BOOT0, 3,3 V, GND, dan reset.

## 4. Akuisisi analog dan digital

### Empat masukan analog

Setiap kanal analog mempunyai urutan rangkaian berupa fuse berlabel 15 V/0,5 A, resistor seri 100 ohm/2 W, TVS SMBJ5.0A, pembagi resistor 175 kohm dan 75 kohm, kapasitor filter 0,1 uF, lalu buffer TLV9004 sebelum masuk ADS1115. ADS1115 memakai I2C dan menyediakan keluaran ALERT/RDY ke STM32.

Secara ideal, pembagi tersebut menghasilkan sekitar **0,30 kali tegangan masukan** sebelum mempertimbangkan resistor seri dan pengaruh komponen lain. Nilai ini tidak menetapkan rentang masukan aman; batas sebenarnya perlu ditentukan dari seluruh rangkaian dan spesifikasi komponen.

### Dua masukan digital

Masukan menggunakan PC817 dengan resistor pembatas, LED indikator, dan pull-up pada sisi logika 3,3 V. Jumper menyediakan pilihan koneksi VIN atau +12 V. Penamaan blok menyebut isolasi, tetapi pemisahan ground dan konfigurasi jumper perlu diperiksa pada desain lengkap untuk memastikan batas isolasinya.

### Dua keluaran relay

OUT_0 dan OUT_1 menggerakkan optocoupler PC817, transistor SS8050, serta relay RP818005 dengan koil 5 V. Masing-masing kanal memiliki LED indikator dan dioda M7 untuk menekan tegangan balik koil. Kontak relay dibawa ke konektor tiga pin.

## 5. Komunikasi dan penyimpanan

| Antarmuka | Komponen / koneksi | Keterangan |
| --- | --- | --- |
| Ethernet | W5500 Mini | SPI ke STM32, interrupt dan reset terpisah. |
| RS485 | Tiga modul berlabel isolator | Terhubung ke UART STM32; terminal lapangan A+, B-, GND_E. Detail internal modul tidak diberikan. |
| LoRa | RFM95W | SPI ke ESP32, DIO0 sebagai interrupt, reset, dan antena SMA. |
| CAN | MCP2515 + SN65HVD230D | SPI ke ESP32, kristal 8 MHz, keluaran CANH/CANL, terminasi 120 ohm melalui jumper. |
| Modem | Header EC200 | GND, TX, RX, PWR_KEY, 5 V, reset, sleep; satu pin tidak digunakan. |
| Flash | W25Q128JVS | Memori SPI eksternal pada STM32. |
| EEPROM | CAT24C256 | I2C, alamat dan write protect dapat dikonfigurasi dengan jumper. |
| MicroSD | Soket microSD | Mode SPI; jalur SDIO pada STM32 tidak digunakan pada koneksi utama. |
| RTC | DS3231M | I2C, VBAT, serta jalur reset ke STM32. |

## 6. Catu daya

Alur daya yang digambar adalah **24 VDC -> 12 V -> 5 V dan 3,3 V**. Tahap 24 V ke 12 V menggunakan modul XL4015, dilengkapi dioda, fuse, resistor seri, TVS, kapasitor, dan indikator LED.

Tahap 12 V ke 5 V serta 12 V ke 3,3 V memakai **MIC29302AWU** dengan pembagi resistor pengatur keluaran. Walaupun judul blok menyebut buck converter, komponen tersebut merupakan regulator linear; evaluasi disipasi panas diperlukan sesuai arus beban. PDF tidak mencantumkan anggaran daya maupun hasil pengukuran tegangan.

Sheet utama menyediakan jumper suplai untuk sejumlah periferal serta test point pada rail daya. Baterai pada sheet STM32 memasok jalur VBAT melalui BAT54C; jalur VBAT juga dibawa ke RTC eksternal.

## 7. Catatan konsistensi dokumen

Temuan berikut adalah hal yang perlu diverifikasi, bukan kesimpulan bahwa perangkat pasti gagal:

1. **Judul ADC tidak konsisten:** halaman 8 bertuliskan "EXTERNAL 12 BIT ADC", sedangkan IC yang digambar adalah ADS1115, yaitu ADC 16 bit.
2. **Judul regulator tidak sesuai jenis komponen:** dua blok berjudul buck converter memakai MIC29302AWU, regulator linear.
3. **Nomor sheet berbeda dari urutan PDF:** microSD berlabel 11/17 dan halaman terakhir berlabel 18/17, sementara berkas hanya berisi 17 halaman. Ringkasan ini selalu memakai nomor halaman PDF.
4. **Sheet hierarkis I/O perlu dicocokkan:** sheet utama menunjukkan port VIN pada blok I/O, sedangkan halaman rangkaian I/O menggunakan label VIN. Hubungan akhirnya perlu diperiksa pada file KiCad/netlist.
5. **RS485 perlu pemeriksaan antarsheet:** sheet utama menampilkan sinyal RE/DE, sedangkan detail modul hanya menunjukkan VIN, TX, RX, GND, A+, B-, dan GND_E. Dukungan kontrol arah oleh modul belum jelas dari PDF.
6. **Suplai RS485 perlu dikonfirmasi:** sheet utama menghubungkan +5 V ke port bernama 3V3_RS1/2/3. Kesesuaian tegangan bergantung pada modul sebenarnya.
7. **I2C perlu pemeriksaan pull-up:** pull-up SDA/SCL tidak tampak jelas pada halaman yang disajikan; periksa apakah tersedia di PCB atau modul.
8. **Bagian ADC belum terhubung ke sumber sinyal pada sheet utama:** port AIN0-AIN3 ditandai tidak tersambung di tingkat atas. Pastikan rute konektor masukan pada desain sumber sesuai maksudnya.

## 8. Batas ringkasan

Ringkasan dibuat dengan membaca visual seluruh 17 halaman karena PDF tidak memiliki lapisan teks yang dapat diekstrak. Skematik menunjukkan rancangan koneksi perangkat keras, tetapi tidak menyertakan BOM lengkap, layout PCB, kode firmware, pengaturan bus, protokol aplikasi, atau hasil pengujian. Nilai komponen dan koneksi akhir sebaiknya dirujuk kembali ke skematik asli sebelum implementasi atau perubahan perangkat keras.
