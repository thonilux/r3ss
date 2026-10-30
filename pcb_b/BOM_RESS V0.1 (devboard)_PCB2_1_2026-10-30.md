# BOM RESS V0.1 (devboard) - PCB2_1

**Tanggal:** 2026-10-30  
**Sumber:** `BOM_RESS V0.1 (devboard)_PCB2_1_2026-10-30.csv`

## Ringkasan

## 🛒 Quick shopping summary

| Info | Total |
|---|---:|
| 🔩 Jenis item BOM asli | **54 jenis** |
| 📦 Total unit komponen per board | **113 pcs** |
| 🏭 Jumlah board produksi | **2 pcs** |
| 📦 Total unit untuk produksi 2 board | **226 pcs** |
| 🏪 Cluster toko | **13 toko/kelompok** |
| ✅ Sudah ada pilihan/link | **sebagian besar item** |
| ⚠️ Substitusi/modifikasi | **beberapa item** |
| ❌ Belum ada link final | **4 item** |

### Status cepat

- ✅ **Sudah ada pilihan:** ESP32, STM32, W5500 stok, ADS1115, DS3231, MAX485 module, 74HC04, LM2596, AMS1117, relay, dioda, resistor, LED, kapasitor, dan induktor.
- 🔄 **Substitusi/modifikasi:** ADS1115, ESP32-1U, AT24C256 module, ADuM1250ARZ, PC817, 1N4148 LL34, terminal 5,08 mm, dan elco 330 uF.
- ❌ **Masih perlu dicari:** ADuM5402WCRWZ-1RL, button SMD 2×3×2,5 mm, header 1×4 pitch 2,54 mm, dan IC AT24C256W SOP-8 langsung.
- 💸 **Strategi ongkir:** prioritaskan SMG Jaya Tronik, Marnov, dan HWThinker karena masing-masing menampung beberapa item.

### 🔁 Multiplier produksi

- Semua jumlah pada tabel belanja adalah kebutuhan **1 board** kecuali jika tertulis lain.
- Untuk produksi **2 board**, kalikan jumlah kebutuhan BOM menjadi **2×**.
- Minimum pembelian toko tetap berlaku. Contoh: listing 10 pcs tetap dibeli 1 paket jika kebutuhan hasil x2 masih ≤10 pcs.
- W5500 stok internal menjadi kebutuhan **2 pcs stok** untuk 2 board.
- Item yang dilepas dari strategi RS485 tetap tidak dibeli: SP3485, resettable fuse, dan TVS.

## 🧾 Audit cart Tokopedia

### 🛒 Validasi cart SMG Jaya Tronik untuk produksi 2 board

> Catatan: jumlah pada screenshot adalah default/minimum order Tokopedia. Tidak perlu dikurangi. Semua qty cart dianggap valid sebagai stok lebih dan tetap checkout sesuai kebijakan minimum order.

| Item cart | Kebutuhan 2 board | Aksi checkout |
|---|---:|---|
| Tantalum 10 uF/25 V | 4 pcs | ✅ Qty 4 sudah pas, tetapi cek package/polaritas |
| Kapasitor 33 pF per 10 pcs | 2 pcs | ✅ Tetap checkout qty 5 karena minimum order/default cart |
| Elco 330 uF/25 V per 5 pcs | 4 pcs | ✅ Qty 1 pack cukup |
| Kapasitor 22 uF per 10 pcs | 8 pcs | ✅ Tetap checkout qty 2 karena minimum order/default cart |
| BAT54S SOT-23 | 8 pcs | ✅ Qty 10 masih cukup |
| LED hijau per 10 pcs | 2 pcs | ✅ Tetap checkout qty 5 karena minimum order/default cart |
| LED merah per 10 pcs | 14 pcs | ✅ Tetap checkout qty 5 karena minimum order/default cart |
| Resistor 56k, 10k, 4,7k, 2,2k, 330, 150, 120, 100 ohm per 10 pcs | 2-10 pcs per nilai | ✅ Tetap checkout sesuai qty cart/minimum order |
| Kapasitor 120 pF | 0 pcs | ❌ Hapus; BOM membutuhkan 33 pF |
| Resistor 0 ohm per 10 pcs | 4 pcs | ✅ Tetap checkout qty 30 karena minimum order/default cart |

### ✅ Pertahankan

| Toko | Item cart | Status terhadap BOM |
|---|---|---|
| Tekno Kreasi Elektronik | AT24C256 module, 1 pcs | Kapasitas sesuai, tetapi modul eksternal; bukan IC SOP-8 langsung |
| Marnov | ESP32-S3-WROOM-1U N16R8, 2 pcs | Sesuai keputusan pembelian untuk 2 board |
| Marnov | ADS1115, 1 pcs | Substitusi yang dipilih untuk item ADC |
| Marnov | LM2596S-5.0, 7 pcs | Part sesuai; BOM hanya butuh 1 pcs, kurangi menjadi 1 pcs |
| HWThinker | STM32F407VGT6 DevEBox, 1 pcs | Sesuai |
| Elekterong2 | DS3231SN, 1 pcs | Sesuai |
| Elekterong2 | ADuM1250ARZ, 1 pcs | Kandidat sesuai fungsi; verifikasi footprint |
| SMG Jaya Tronik | Resistor 0 ohm, 20 pcs | Nilai/package sesuai; BOM hanya butuh 2 pcs |
| Permony Store | Terminal 4-pin 5,08 mm, 1 set | Kandidat konektor; verifikasi pitch 5,08 vs 5,00 mm |

### ❌ Hapus dari cart

| Toko | Item cart | Alasan |
|---|---|---|
| Elekterong2 | AT24C01, 2 pcs | Salah kapasitas; BOM membutuhkan AT24C256. **Hapus.** |
| SMG Jaya Tronik | Kapasitor 120 pF, 5 pcs | BOM membutuhkan 33 pF, bukan 120 pF |
| Marnov | HT7333/HT7333A, 17 pcs | Tidak ada di BOM dan bukan pengganti AMS1117 yang sudah dipilih |
| Toko Rytech | ESP32-C3 | Tidak ada di BOM |
| Toko Rytech | LCD TFT 2,4 inci | Tidak ada di BOM |
| Fortuna Jogja | NRF24L01, OLED, UART-RS485 module | Tidak ada di BOM; RS485 IC sudah ditentukan SP3485 |
| Jaya Tronik lainnya | Item non-BOM lainnya | Jangan checkout untuk proyek PCB ini |

### ⚠️ Catatan cart

- Cart menampilkan **38 item**, tetapi sebagian besar bukan komponen BOM proyek.
- LM2596 cukup **1 pcs**, bukan 7 pcs.
- AT24C01 wajib dihapus. AT24C256 module hanya dipakai jika pemasangan eksternal melalui kabel memang diterima.
- Terminal 4-pin Permony masih perlu verifikasi pitch dan bentuk terhadap PCB.

| Metrik | Nilai |
|---|---:|
| Baris BOM | 54 |
| Total kuantitas komponen | 113 |
| Baris dengan kuantitas 1 | 27 |
| Baris dengan kuantitas 2 | 10 |
| Baris dengan kuantitas 3 | 3 |
| Baris dengan kuantitas 4 | 13 |
| Baris dengan kuantitas 5 | 1 |

## Kelompok komponen utama

- **Kontrol dan komunikasi:** ESP32-S3-WROOM-1, W5500 module, ADUM1250, serta konektor/header.
- **Catu daya:** B0505S-1WR2, LM2596S-5.0, AMS1117-3.3V, induktor 47 uH, dan komponen proteksi daya.
- **RTC dan memori:** DS3231SN# serta AT24C256W-10SI-1.8.
- **Antarmuka pengguna dan penyimpanan:** TF card connector, LED hijau/merah, push button, dan baterai CR1220.
- **I/O dan switching:** relay SRD-05VDC-SL-C, optocoupler PC817X3NSZW, transistor 2N3904, serta konektor 3-pin.
- **Pasif:** resistor, kapasitor, diode, dan ferrite/protection components dalam beberapa nilai dan footprint 0805/SMD.

## Komponen dengan jumlah terbesar

| Komponen | Designator | Qty |
|---|---|---:|
| LED_0805-R | LED1, LED3-LED6 | 5 |
| 4k7 | R15, R16, R25, R26 | 4 |
| PMLL4148L | D11-D14 | 4 |
| 2N3904(SOT-23) | Q1-Q4 | 4 |
| 100 | R12, R47, R54, R55 | 4 |
| SRD-05VDC-SL-C | RLY1-RLY4 | 4 |
| PC817X3NSZW | U21–U23, U25 | 4 |
| ZX-DG01V-5.0-3P5 | U26, U27, U29, U30 | 4 |
| 100nF | C3, C7, C11, C16 | 4 |

## Catatan data

- 25 baris belum memiliki data **Manufacturer**.
- 20 baris belum memiliki data **Supplier**.
- 15 baris belum memiliki data **Manufacturer Part**.
- Supplier yang terisi pada BOM adalah **LCSC**.
- Ringkasan ini mempertahankan isi BOM sumber; data yang kosong tidak diisi atau ditebak.

## Daftar belanja Tokopedia

Gunakan kata kunci berikut saat mencari. Pastikan package dan ukuran sesuai PCB.

### IC, modul, dan catu daya

| Qty | Kata kunci pencarian |
|---:|---|
| 2 | ESP32-S3-WROOM-1U N16R8 - **tetap beli, produk Marnov dipilih untuk 2 board** |
| 2 | W5500 module W5500Mini - **stok tersedia, kebutuhan 2 pcs** |
| 2 | STM32F407VGT6 DevEBox - **produk dipilih** |
| 2 | ADS1115 16-bit ADC - **produk dipilih sebagai substitusi** |
| 2 | DS3231SN SOIC-16 - **produk dipilih** |
| 2 | AT24C256W-10SI SOIC-8 - **kandidat modul AT24C256 tersedia; bukan pemasangan langsung** |
| 2 | ADUM1250WSRZ-RL7 - **kandidat ADuM1250ARZ dipilih, verifikasi footprint** |
| 2 | ADUM5402WCRWZ-1RL - **belum ditemukan** |
| 0 | SP3485EN-L/TR RS485 - **dilepas; diganti modul MAX485 RS485-to-TTL** |
| 0 | 74HC04D SOP-14 - **dilepas dari pembelian; sumber belum terverifikasi** |
| 2 | B0505S-1WR2 isolated DC-DC - **kandidat produk** |
| 2 | LM2596S-5.0 TO-263 - **produk dipilih** |
| 2 | AMS1117-3.3 SOT-223 - **produk dipilih, beli 2 pcs** |
| 2 | CR1220 SMD battery holder - **produk dipilih** |
| 2 | TF card SMD socket TF-15-15 - **produk dipilih** |

### Relay, optocoupler, transistor, konektor, dan switch

| Qty | Kata kunci pencarian |
|---:|---|
| 4 | SRD-05VDC-SL-C relay 5V - **produk dipilih, beli 4 pcs** |
| 4 | PC817X3NSZW optocoupler - **kandidat PC817 DIP-4 sesuai package, verifikasi CTR** |
| 4 | 2N3904 SOT-23 - **produk dipilih, listing 10 pcs; kebutuhan 4 pcs** |
| 2 | button SMD 2x3x2.5 mm |
| 2 | terminal block 2 pin pitch 5.00 mm - **kandidat pitch 5.08 mm, verifikasi PCB** |
| 10 | terminal block 3 pin pitch 5.00 mm - **dipakai untuk MODBUS + pengganti ZX-DG01V, kandidat pitch 5.08 mm; verifikasi PCB** |
| 2 | Phoenix 1890989 terminal 4 pin pitch 5.00 mm - **kandidat pitch 5.08 mm, verifikasi PCB** |
| 4 | ZX-DG01V-5.0-3P5 - **disamakan dengan terminal block 3-pin pitch 5.00 mm** |
| 2 | header pin male 1x4 pitch 2.54 mm |

### Dioda dan proteksi

| Qty | Kata kunci pencarian |
|---:|---|
| 2 | PMLL4148L 115 SOD-80 - **kandidat 1N4148 LL34, verifikasi footprint** |
| 8 | PMLL4148L SOD-80 - **kandidat 1N4148 LL34, total kebutuhan 10 pcs** |
| 8 | BAT54S SOT-23 - **produk dipilih, kebutuhan 8 pcs** |
| 4 | SS34 SMA diode - **produk dipilih, kebutuhan 4 pcs** |
| 0 | SMAJ6.5CA TVS diode - **dilepas; proteksi ditangani/diabaikan pada modul RS485 eksternal** |
| 0 | SMD1812P010TF resettable fuse - **dilepas dari pembelian** |

### Kapasitor

| Qty | Nilai dan package |
|---:|---|
| 2 | 10 uF - **pakai tantalum SMG Jaya Tronik 25 V untuk C24 + C36; cek package/polaritas** |
| 2 | 33 pF SMD 0805 - **produk dipilih, kebutuhan 2 pcs** |
| 20 | 100 nF / 0.1 uF SMD 0805 - **disamakan, produk dipilih; total kebutuhan 20 pcs** |
| 8 | 22 uF SMD 0805 - **produk dipilih, rating 25 V** |
| 4 | 33 uF SMD electrolytic D8 x 10.5 mm - **diganti 330 uF/25 V, batas input 24 V** |

### Resistor SMD 0805

| Qty | Nilai |
|---:|---:|
| 4 | 0 ohm - **produk dipilih, kebutuhan 4 pcs** |
| 8 | 100 ohm - **produk dipilih, kebutuhan 8 pcs** |
| 8 | 120 ohm - **produk dipilih, kebutuhan 8 pcs** |
| 8 | 150 ohm - **produk dipilih, kebutuhan 8 pcs** |
| 2 | 330 ohm - **produk dipilih, kebutuhan 2 pcs** |
| 4 | 560 ohm - **produk dipilih, kebutuhan 4 pcs** |
| 6 | 2.2k ohm - **produk dipilih, kebutuhan 6 pcs** |
| 10 | 4.7k ohm - **produk dipilih, kebutuhan 10 pcs** |
| 6 | 10k ohm - **produk dipilih, kebutuhan 6 pcs** |
| 2 | 56k ohm - **produk dipilih, kebutuhan 2 pcs** |

### LED dan induktor

| Qty | Kata kunci pencarian |
|---:|---|
| 14 | LED merah SMD 0805 - **produk dipilih, kebutuhan 14 pcs** |
| 2 | LED hijau SMD 0805 - **produk dipilih, kebutuhan 2 pcs** |
| 4 | XL-2012SURC - **disamakan dengan LED merah SMD 0805** |
| 2 | induktor 47 uH SMD 12 x 12 mm / GCRH125-470MC - **produk dipilih** |

## Catatan pembelian

- ⏭️ **Kapasitor decoupling RTC di-skip dari pembelian dan dianggap sudah tersedia di stok internal.** Jumlah BOM tetap dipertahankan sebagai referensi perakitan.
## Cluster toko Tokopedia

Gunakan bagian ini untuk menggabungkan pesanan dan menghitung ongkir. Jumlah di bawah adalah kebutuhan BOM, bukan selalu jumlah minimum listing.

## 📋 Tabel belanja per toko

### 💳 Status pembayaran

| Toko | Status | Nominal dibayar | Catatan |
|---|---|---:|---|
| JayaTronik SMG | ✅ **Sudah dibayar** | **Rp185.100** | Pesanan komponen pasif, LED, dioda, dan kapasitor. |
| Marnov | ✅ **Sudah dibayar** | **Rp255.725** | ESP32, ADS1115, 100 nF, induktor, LM2596, dan 1 pcs AMS1117. AMS1117 masih kurang 3 pcs. |
| HWThinker | ✅ **Sudah dibayar** | **Rp347.400** | STM32F407VGT6 DevEBox 1 pcs. Masih kurang 1 pcs untuk produksi 2 board; TF socket di-skip. |
| Elekterong | ✅ **Sudah dibayar** | **Rp258.340** | DS3231SN dan ADuM1250ARZ untuk produksi 2 board. |
| Sellered | ✅ **Sudah dibayar** | **Rp100.350** | B0505S-1W converter, kebutuhan 2 pcs. |
| CNC Store Bandung + ArduinoNano | ✅ **Sudah dibayar** | **Rp175.300** | Relay, modul MAX485, dan holder baterai CR1220. |
| Permony | ✅ **Sudah dibayar** | **Rp100.500** | Terminal block 2-pin, 3-pin, dan 4-pin pitch 5,08 mm. Verifikasi kecocokan PCB tetap diperlukan. |
| **TOTAL sampai 11.13 WIB** |  | **Rp1.422.715** | 7 pembayaran tercatat |

### 🔍 Audit pembayaran JayaTronik

- ✅ **Mayoritas aman:** resistor, LED, BAT54S, kapasitor 33 pF, 22 uF, dan elco 330 uF masuk kebutuhan produksi 2 board atau menjadi stok lebih.
- ⚠️ **120 pF salah item:** ikut terbayar, tetapi tidak dipakai karena BOM membutuhkan 33 pF. Simpan sebagai stok terpisah atau ajukan retur jika memungkinkan.
- ⚠️ **Tantalum 10 uF/25 V:** pastikan Case D/package dan polaritasnya cocok. Jangan pasang ke footprint 0805 tanpa verifikasi.
- ⚠️ **Kapasitor 22 uF/25 V dan elco 330 uF/25 V:** batas input sistem 24 V masih menyisakan margin kecil terhadap spike.
- ✅ Qty berlebih pada cart diterima sebagai minimum order/default toko dan dihitung sebagai stok cadangan.

### 🛒 Audit cart Marnov untuk produksi 2 board

| Item | Qty cart | Kebutuhan 2 board | Status |
|---|---:|---:|---|
| Kapasitor 100 nF 0805 | 20 | 20 | ✅ Pas |
| Induktor 47 uH | 8 | 2 | ⚠️ Berlebih, boleh jadi stok |
| AMS1117-3.3 | 1 | 4 | ❌ Kurang 3 pcs; tambah menjadi 4 pcs |
| ESP32-S3-WROOM-1U | 2 | 2 | ✅ Pas |
| ADS1115 | 2 | 2 | ✅ Pas |
| LM2596S-5.0 | 7 | 2 | ⚠️ Berlebih, boleh jadi stok |
| HT-7333/HT7333A | 17 | 0 | ❌ Hapus; bukan item BOM |

### 🔍 Audit cluster setelah produksi x2

- ⚠️ Qty pada beberapa tabel toko masih ditulis sebagai kebutuhan 1 board. Untuk checkout produksi 2 board, gunakan multiplier 2× kecuali item sudah dibeli/ditampilkan sebagai paket minimum.
- ✅ RS485 sudah dipusatkan ke modul MAX485 CNC Store. SP3485, resettable fuse, dan TVS tidak dibeli.
- ⚠️ AT24C256 masih berupa modul eksternal, bukan IC SOP-8 langsung.
- ⚠️ Terminal block masih pitch 5,08 mm, sedangkan footprint PCB tertulis 5,00 mm.
- ❌ Item cart non-BOM tetap jangan dibeli: AT24C01, HT7333, ESP32-C3, LCD, NRF24L01, OLED, dan modul RS485 tambahan selain MAX485 yang dipilih.

### SMG Jaya Tronik

| Nama item | Jumlah | Link |
|---|---:|---|
| Resistor 0 ohm 0805 | 4 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-0-ohm-1-8w-per-10-pcs-1729824763364673415) |
| Resistor 100 ohm 0805 | 8 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-100-ohm-per-10-pcs-1729804021246691207) |
| Resistor 120 ohm 0805 | 8 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-120-ohm-per-10-pcs-1729824196566419335) |
| Resistor 150 ohm 0805 | 8 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-150-ohm-per-10-pcs-1729804021247215495) |
| Resistor 330 ohm 0805 | 2 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-330-ohm-per-10-pcs-1729804016407316359) |
| Resistor 560 ohm 0805 | 4 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-560-ohm-per-10-pcs-1729804016407971719) |
| Resistor 2,2k 0805 | 6 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-2-2-kiloohm-2-2k-2-2k-2-2-k-per-10-pcs-1729804021250754439) |
| Resistor 4,7k 0805 | 10 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-4-7-kiloohm-4-7k-4-7k-4-7-k-per-10-pcs-1729804016408758151) |
| Resistor 10k 0805 | 6 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-10-kiloohm-10k-10-k-per-10-pcs-1729804019485738887) |
| Resistor 56k 0805 | 2 pcs | [Link](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-56-kiloohm-56k-56-k-per-10-pcs-1729804021251278727) |
| LED merah 0805 | 14 pcs | [Link](https://www.tokopedia.com/smgjayatronik/led-merah-smd-red-led-0805-per-10-pcs-1729824763341670279) |
| LED hijau 0805 | 2 pcs | [Link](https://www.tokopedia.com/smgjayatronik/led-smd-0805-green-hijau-per-10-pcs-1729864577491896199) |
| BAT54S SOT-23 | 8 pcs | [Link](https://www.tokopedia.com/smgjayatronik/bat54s-l44-sot-23-schottky-diode-1729909048220813191) |
| SS34 SMA | 4 pcs | [Link](https://www.tokopedia.com/smgjayatronik/ss34-1n5822-smd-do-214ac-per-10-pcs-1729829220772710279) |
| Kapasitor 22 uF 0805 | 8 pcs | [Link](https://www.tokopedia.com/smgjayatronik/kapasitor-keramik-smd-0805-25v-22uf-per-10-pcs-1730018213171857287) |
| Kapasitor 33 pF 0805 | 2 pcs | [Link](https://www.tokopedia.com/smgjayatronik/kapasitor-capacitor-smd-0805-50v-33pf-33-pf-per-10-pcs-1729824763356743559) |
| Elco 330 uF/25 V D8 | 4 pcs | [Link](https://www.tokopedia.com/smgjayatronik/kapasitor-elco-smd-330uf-25v-8-x-10-5-mm-per-5-pcs-1729898120915027847) |
| Kapasitor tantalum 10 uF/25 V untuk C24 + C36 | 4 pcs | [Link](https://www.tokopedia.com/smgjayatronik/capacitor-kapasitor-tantalum-smd-25v-10uf) |

### Marnov

| Nama item | Jumlah | Link |
|---|---:|---|
| ESP32-S3-WROOM-1U N16R8 | 2 pcs | [Link](https://www.tokopedia.com/marnov/esp32-s3-wroom-1u-u-antena-pigtail-n16r8-chip-wroom-16mb-flash-8mb-psram-esp32s3-aiot) |
| ADS1115 | 2 pcs | [Link](https://www.tokopedia.com/marnov/ads1115-16-bit-adc-4-channel-programmable-gain-amplifier-ads-1115-1731271119828453342) |
| LM2596S-5.0 | 2 pcs | [Link](https://www.tokopedia.com/marnov/lm2596s-5-0v-chip-ic-lm2596-fix-5v-3a-step-down) |
| AMS1117-3.3 | 4 pcs | [Link](https://www.tokopedia.com/marnov/ams1117-3-3v-voltage-regulator-ams-1117-1pcs-1ce32) |
| Induktor 47 uH 12 x 12 mm | 2 pcs | [Link](https://www.tokopedia.com/marnov/induktor-smd-47uh-inductor-power-0-047mh-47000nh-12mm-x-12mm-1732301235496519617) |
| Kapasitor 100 nF/0,1 uF 0805 | 20 pcs | [Link](https://www.tokopedia.com/marnov/capacitor-0805-100nf-smd-kapasitor-100-nf-104-4000-reels-rol-reels-1731026101934196702) |

### HWThinker

| Nama item | Jumlah | Link |
|---|---:|---|
| STM32F407VGT6 DevEBox | 1 pcs | [Link](https://www.tokopedia.com/hwthinker/devebox-stm32f407vgt6-stm32f4-f407-stm32-sd-slot-development-board-cortex-m4-1731604961438041160) |
| TF/micro-SD socket SMD | 0 pcs | **dilewati sementara** |

### Elekterong

| Nama item | Jumlah | Link |
|---|---:|---|
| DS3231SN SOP-16 | 2 pcs | [Link](https://www.tokopedia.com/elekterong/ds3231sn-ds3231-ds3231s-sop-16-new-original-mantaff) |
| ADuM1250ARZ SOP-8 | 2 pcs | [Link](https://www.tokopedia.com/elekterong/adum1250arz-adum1250-1250arz-sop-8-new-original-mantaff) |

### Sellered

| Nama item | Jumlah | Link |
|---|---:|---|
| B0505S-1W converter | 2 pcs | [Link](https://www.tokopedia.com/sellered/b0505s-1w-5v-to-5v-converter-dc-dc-power-module-converter-b0505s-1w) |

### ArduinoNano

| Nama item | Jumlah | Link |
|---|---:|---|
| Holder baterai CR1220 SMD | 2 pcs | [Link](https://www.tokopedia.com/arduinonano/cr1220-battery-button-coin-cell-holder-cr-1220-1216-socket-smd-case) |

### CNC Store Bandung

| Nama item | Jumlah | Link |
|---|---:|---|
| Relay SRD-05VDC-SL-C 5 V | 8 pcs | [Link](https://www.tokopedia.com/cncstorebandung/cnc-relay-songle-5v-10a-srd-05vdc-sl-c-5-pin-5p) |
| Modul MAX485 RS485-to-TTL | 2 pcs | [Link](https://www.tokopedia.com/cncstorebandung/max485-module-rs-485-ttl-to-serial-uart-ttl-converter-module-arduino) |

### Permony

| Nama item | Jumlah | Link |
|---|---:|---|
| Terminal block 2-pin 5,08 mm | 2 pcs | [Link](https://www.tokopedia.com/permony/terminal-blok-2pin-5-08mm-elbow-kf2edg-2p-pcb-connector-1-set-lurus) |
| Terminal block 3-pin 5,08 mm | 10 pcs | [Link](https://www.tokopedia.com/permony/terminal-block-blok-3pin-5-08mm-3-pin-5-08-mm-kf2edg-lurus-7b0ee) |
| Terminal block 4-pin 5,08 mm | 2 pcs | [Link](https://www.tokopedia.com/permony/terminal-blok-4pin-5-08mm-elbow-kf2edg-4p-pcb-connector-1-set-4-pin-lurus-9ef00) |

### Stok tersedia

| Nama item | Jumlah | Link |
|---|---:|---|
| W5500 module W5500Mini | 1 pcs | Stok internal, tidak perlu checkout |

### ❌ Jangan checkout dari cart

| Nama item | Alasan |
|---|---|
| AT24C01 | Salah kapasitas; harus AT24C256 |
| Kapasitor 120 pF | BOM membutuhkan 33 pF |
| HT7333 | Tidak ada di BOM |
| ESP32-C3, LCD, NRF24L01, OLED, modul UART-RS485 | Bukan item BOM PCB2 |

### 1. SMG Jaya Tronik

- Resistor 0805: 0 ohm (2), 100 ohm (4), 120 ohm (4), 150 ohm (4), 330 ohm (1), 560 ohm (2), 2,2k (3), 4,7k (5), 10k (3), 56k (1).
- LED merah 0805 (7), LED hijau 0805 (1), BAT54S SOT-23 (4), SS34 SMA (2), kapasitor 22 uF 0805 (4), kapasitor 33 pF 0805 (1), elco 330 uF/25 V D8 x 10,5 mm (2).
- Substitusi: elco 330 uF menggantikan 33 uF; batas input maksimal 24 V.

### 2. Marnov

- ESP32-S3-WROOM-1U N16R8 (2), LM2596S-5.0 (2), 74HC04D (2), AMS1117-3.3 (4), induktor 47 uH 12 x 12 mm (2).
- Substitusi: ESP32 varian 1U membutuhkan antena eksternal. Kapasitor 100 nF 0805 dari Marnov dipilih.

### 3. HWThinker

- STM32F407VGT6 DevEBox (1) dan TF/micro-SD socket SMD (1).

### 6. Elekterong

- DS3231SN SOP-16 (1) dan ADuM1250ARZ SOP-8 sebagai kandidat pengganti ADUM1250WSRZ-RL7.

### 8. Sellered

- B0505S-1W sebagai kandidat. Listing berupa modul, jadi perlu dicocokkan dengan footprint B0505S-1WR2.

### 9. ArduinoNano

- Holder baterai CR1220 SMD (1).

### 10. CNC Store Bandung

- Relay SRD-05VDC-SL-C 5 V (4).

### 12. Permony

- Terminal block 2-pin, 3-pin, dan 4-pin, semua kandidat pitch 5,08 mm.
- Substitusi: BOM meminta pitch 5,00 mm. Terminal 3-pin dipakai untuk total 5 posisi, yaitu MODBUS dan pengganti 4 konektor ZX-DG01V.

- Substitusi: package SMB lebih besar dari SMA, sehingga perlu modifikasi pad/kawat dan pemeriksaan short.

### 14. Item belum tersedia

- ADUM5402WCRWZ-1RL.
- Button SMD 2 x 3 x 2,5 mm.
- Header 1 x 4 pitch 2,54 mm.
- IC EEPROM AT24C256W-10SI-1.8 SOP-8 langsung. Modul AT24C256 tidak dianggap pemasangan langsung.

## Prioritas penggabungan pesanan

1. Gabungkan resistor, LED, dioda kecil, dan kapasitor 0805 ke SMG Jaya Tronik bila stok tersedia.
2. Gabungkan ESP32, LM2596, AMS1117, 74HC04, dan induktor di Marnov.
3. Gabungkan STM32 dan socket TF di HWThinker.
4. Pesan terminal Permony hanya setelah pitch 5,08 mm dikonfirmasi cocok dengan PCB.
5. Pesan item belum tersedia setelah part number dan footprint dikonfirmasi.

- LED merah SMD 0805 dipakai juga untuk menggantikan `XL-2012SURC` RX/TX. Total kebutuhan LED merah menjadi **7 pcs**, sehingga 1 listing 10 pcs mencukupi.
- **Catatan umum komponen 0805:** jika item BOM mencantumkan footprint `0805`, gunakan halaman pencarian SMG Jaya Tronik berikut untuk mencari nilai yang sesuai: [SMG Jaya Tronik - pencarian komponen 0805](https://www.tokopedia.com/smgjayatronik/product?q=2k2%26srp_component_id=02.01.00.00%26srp_page_id=3284559%26srp_page_title=JayaTronik%20Smg%26navsource=shop). Nilai resistor/kapasitor tetap harus dicocokkan dengan BOM.
- Kandidat terminal block 2-pin dari Permony: [Tokopedia Permony - KF2EDG-2P pitch 5.08 mm](https://www.tokopedia.com/permony/terminal-blok-2pin-5-08mm-elbow-kf2edg-2p-pcb-connector-1-set-lurus?extParam=ivf%3Dfalse%26keyword%3Dterminal%2Bblock%2B2%2Bpin%2Bpitch%2B5.00%2Bmm%26search_id%3D20261030021003C042F4DB68F2342DEQU7%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D10%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Pitch 5.08 mm berbeda dari BOM 5.00 mm dan bentuknya elbow/siku, jadi ukur jarak lubang PCB sebelum checkout.
- Kandidat terminal block 3-pin dari Permony: [Tokopedia Permony - KF2EDG 3-pin pitch 5.08 mm](https://www.tokopedia.com/permony/terminal-block-blok-3pin-5-08mm-3-pin-5-08-mm-kf2edg-lurus-7b0ee?extParam=src%3Dshop%26whid%3D3676926%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Pitch 5.08 mm berbeda dari BOM 5.00 mm, jadi verifikasi jarak lubang PCB sebelum checkout.
- Kebutuhan `ZX-DG01V-5.0-3P5` disamakan dengan terminal block 3-pin pitch 5.00 mm. Total pembelian terminal 3-pin menjadi **5 pcs**.
- 1N4148/LL4148 dari SMG Jaya Tronik dipilih sebagai kandidat pengganti PMLL4148L: [Tokopedia SMG Jaya Tronik - 1N4148 LL34](https://www.tokopedia.com/smgjayatronik/1n4148-ll4148-4148-in4148-smd-ll34-per-10-pcs-1729817228991498119?extParam=ivf%3Dfalse%26keyword%3Dpmll4148l%2B115%2Bsod-80%26search_id%3D20261030021357F8C1F23D6A8D8D12AKTI%26src%3Dsearch). Listing 10 pcs, sedangkan kebutuhan total 5 pcs. Verifikasi diameter/panjang body, footprint SOD-80/LL34, marking cathode, dan arah pemasangan.
- BAT54S SOT-23 dari SMG Jaya Tronik dipilih sebanyak 4 pcs: [Tokopedia SMG Jaya Tronik - BAT54S](https://www.tokopedia.com/smgjayatronik/bat54s-l44-sot-23-schottky-diode-1729909048220813191?extParam=ivf%3Dfalse%26keyword%3Dbat54s%2Bsot-23%26search_id%3D202610300215025C774A62CDFCB51C5DED%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D13%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result).
- SS34 SMA/DO-214AC dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - SS34 SMA](https://www.tokopedia.com/smgjayatronik/ss34-1n5822-smd-do-214ac-per-10-pcs-1729829220772710279?extParam=ivf%3Dfalse%26keyword%3Dss34%2Bsma%2Bdiode%26search_id%3D2026103002152854972DCC5802690E6XKH%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D14%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Listing 10 pcs, kebutuhan BOM 2 pcs.
- Strategi RS485 diubah: resettable fuse dan TVS dilepas dari pembelian. Gunakan modul MAX485 eksternal dari CNC Store Bandung: [Tokopedia CNC Store Bandung - MAX485 RS485-to-TTL](https://www.tokopedia.com/cncstorebandung/max485-module-rs-485-ttl-to-serial-uart-ttl-converter-module-arduino). Modul ini tidak dipasang pada footprint SP3485 PCB; hubungkan melalui UART/TTL dan jalur RS485 eksternal.
- 74HC04D tidak dibeli; diasumsikan tersedia dari board RS485-to-TTL. **Verifikasi fisik board terlebih dahulu**, karena modul MAX485 umum biasanya hanya berisi transceiver MAX485 dan komponen pasif, tanpa IC 74HC04.
- Karena modul MAX485 sudah memiliki transceiver sendiri, SP3485EN-L/TR pada PCB perlu dianggap **tidak dipakai** bila jalur RS485 benar-benar dipindahkan seluruhnya ke modul eksternal.
- Link kapasitor SMG Jaya Tronik ditolak: listing `10 pF`, sedangkan BOM membutuhkan `10 uF` SMD 0805. Jangan checkout link tersebut.
- Link SMG Jaya Tronik `1 uF` juga ditolak: nilainya masih tidak sesuai dengan kebutuhan `10 uF` SMD 0805.
- Resistor SMD 0805 0 ohm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 0 ohm 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-0-ohm-1-8w-per-10-pcs-1729824763364673415?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs, kebutuhan BOM 2 pcs.
- Resistor SMD 0805 100 ohm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 100 ohm 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-100-ohm-per-10-pcs-1729804021246691207?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs, kebutuhan BOM 4 pcs.
- Resistor SMD 0805 120 ohm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 120 ohm 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-120-ohm-per-10-pcs-1729824196566419335?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs, kebutuhan BOM 4 pcs.
- Resistor SMD 0805 150 ohm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 150 ohm 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-150-ohm-per-10-pcs-1729804021247215495?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs, kebutuhan BOM 4 pcs.
- Resistor SMD 0805 330 ohm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 330 ohm 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-330-ohm-per-10-pcs-1729804016407316359?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs, kebutuhan BOM 1 pcs.
- Resistor SMD 0805 560 ohm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 560 ohm 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-560-ohm-per-10-pcs-1729804016407971719?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs, kebutuhan BOM 2 pcs.
- Resistor SMD 0805 10 kOhm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 10k 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-10-kiloohm-10k-10-k-per-10-pcs-1729804019485738887?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs, kebutuhan BOM 3 pcs.
- Resistor SMD 0805 56 kOhm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 56k 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-56-kiloohm-56k-56-k-per-10-pcs-1729804021251278727?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs, kebutuhan BOM 1 pcs.
- LED merah SMD 0805 dari SMG Jaya Tronik dipilih sebanyak 5 pcs: [Tokopedia SMG Jaya Tronik - LED merah 0805](https://www.tokopedia.com/smgjayatronik/led-merah-smd-red-led-0805-per-10-pcs-1729824763341670279?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs.
- LED hijau SMD 0805 dari SMG Jaya Tronik dipilih sebanyak 1 pcs: [Tokopedia SMG Jaya Tronik - LED hijau 0805](https://www.tokopedia.com/smgjayatronik/led-smd-0805-green-hijau-per-10-pcs-1729864577491896199?extParam=src%3Dshop%26whid%3D2594462%26aff_unique_id%3D%26channel%3Dothers%26chain_key%3D). Listing 10 pcs.
- LED biru, kuning, dan putih dari link yang dikirim tidak masuk BOM saat ini, sehingga tidak perlu dibeli kecuali ada perubahan desain.
- Induktor SMD 47 uH ukuran 12 x 12 mm dari Marnov dipilih: [Tokopedia Marnov - induktor 47 uH](https://www.tokopedia.com/marnov/induktor-smd-47uh-inductor-power-0-047mh-47000nh-12mm-x-12mm-1732301235496519617?extParam=ivf%3Dfalse%26keyword%3D47%2Buh%2Bsmd%2B12%2Bx%2B12%2Bmm%2B%2F%2Bgcrh125-470mc%26search_id%3D2026103002320840008B9A5380FC2DFDON%26src%3Dsearch).
- Link elco SMG Jaya Tronik ditolak: listing `330 uF`, sedangkan BOM membutuhkan `33 uF` SMD D8 x 10,5 mm.
- Kandidat elco 33 uF dari PutryPower: [Tokopedia PutryPower - Nichicon 33 uF D6.5 x 8 mm](https://www.tokopedia.com/putrypower/10pcs-nichicon-d6-5x8mm-33uf-v-35v-elko-smd-kapasitor-elco-solid-1731304353992640425?extParam=ivf%3Dfalse%26keyword%3D33%2Buf%2Bsmd%2Belectrolytic%2Bd8%2Bx%2B10.5%2Bmm%26search_id%3D202610300232545C774A62CDFCB511BVLF%26src%3Dsearch). Nilai 33 uF sesuai dan listing 10 pcs, tetapi diameter/tinggi lebih kecil daripada footprint BOM D8 x 10,5 mm. Verifikasi jarak pad, polaritas, dan kestabilan mekanik sebelum membeli 2 pcs.
- 330 uF/25 V dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - elco SMD 330 uF 25 V](https://www.tokopedia.com/smgjayatronik/kapasitor-elco-smd-330uf-25v-8-x-10-5-mm-per-5-pcs-1729898120915027847?extParam=ivf%3Dfalse%26keyword%3D33%2Buf%2Bsmd%2Belectrolytic%2Bd8%2Bx%2B10.5%2Bmm%26search_id%3D202610300232545C774A62CDFCB511BVLF%26src%3Dsearch). Listing 5 pcs, kebutuhan BOM 2 pcs. Batas input ditetapkan maksimal 24 V; hindari lonjakan/transien di atas rating 25 V.
- Kapasitor tantalum 10 uF/25 V dari SMG Jaya Tronik dipilih untuk C24 + C36: [Tokopedia SMG Jaya Tronik - tantalum 10 uF 25 V](https://www.tokopedia.com/smgjayatronik/capacitor-kapasitor-tantalum-smd-25v-10uf?extParam=ivf%3Dfalse%26keyword%3D10uf%2Bsmd%26search_id%3D20261030031158F8C1F23D6A8D8D1FAZN1%26src%3Dsearch%26t_id%3D1793321566134%26t_st%3D11%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Kebutuhan 2 pcs. Pastikan package sesuai footprint dan pasang polaritas dengan benar.
- Catatan tegangan: 25 V hanya aman secara nominal sampai 24 V tanpa margin spike. Jika C24 langsung terhubung ke input 24 V, kapasitor 35/50 V lebih aman.
- Kapasitor SMD 0805 33 pF/50 V dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - kapasitor 33 pF 0805](https://www.tokopedia.com/smgjayatronik/kapasitor-capacitor-smd-0805-50v-33pf-33-pf-per-10-pcs-1729824763356743559?extParam=ivf%3Dfalse%26keyword%3D33%2Bpf%2Bsmd%2B0805%26search_id%3D2026103002421101386BD6D8E091198Y8Y%26src%3Dsearch). Listing 10 pcs, kebutuhan BOM 1 pcs.
- Kapasitor 100 nF/0,1 uF SMD 0805 dari Marnov dipilih untuk seluruh kebutuhan: [Tokopedia Marnov - kapasitor 100 nF 0805](https://www.tokopedia.com/marnov/capacitor-0805-100nf-smd-kapasitor-100-nf-104-4000-reels-rol-reels-1731026101934196702?extParam=ivf%3Dfalse%26keyword%3D100nf%2B0805%26search_id%3D20261030030930147D8854E763C52482G1%26src%3Dsearch). Total kebutuhan 10 pcs; listing berupa reel.
- Kapasitor keramik SMD 0805 22 uF/25 V dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - kapasitor 22 uF 0805](https://www.tokopedia.com/smgjayatronik/kapasitor-keramik-smd-0805-25v-22uf-per-10-pcs-1730018213171857287?extParam=ivf%3Dfalse%26keyword%3D22%2Buf%2Bsmd%2B0805%26search_id%3D20261030024327F8C1F23D6A8D8D2B6CYZ%26src%3Dsearch). Listing 10 pcs, kebutuhan BOM 4 pcs. Rating 25 V memiliki margin kecil pada jalur 24 V; pastikan tidak ada spike.
- Resistor SMD 0805 2,2 kOhm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 2.2k 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-2-2-kiloohm-2-2k-2-2k-2-2-k-per-10-pcs-1729804021250754439?extParam=ivf%3Dfalse%26keyword%3D2.2k%2Bohm%2B0805%26search_id%3D20261030024351147D8854E763C501AQYN%26src%3Dsearch). Listing 10 pcs, kebutuhan BOM 3 pcs.
- Resistor SMD 0805 4,7 kOhm dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - resistor 4.7k 0805](https://www.tokopedia.com/smgjayatronik/resistor-smd-0805-4-7-kiloohm-4-7k-4-7k-4-7-k-per-10-pcs-1729804016408758151?extParam=ivf%3Dfalse%26keyword%3D4.7k%2Bohm%2Bohm%2B0805%26search_id%3D20261030024419BEED13602B9B0E118883%26src%3Dsearch). Listing 10 pcs, kebutuhan BOM 5 pcs.
- Kandidat terminal block 4-pin dari Permony: [Tokopedia Permony - KF2EDG 4-pin pitch 5.08 mm](https://www.tokopedia.com/permony/terminal-blok-4pin-5-08mm-elbow-kf2edg-4p-pcb-connector-1-set-4-pin-lurus-9ef00?extParam=ivf%3Dfalse%26keyword%3Dphoenix%2B1890989%2Bterminal%2B4%2Bpin%2Bpitch%2B5.00%2Bmm%26search_id%3D2026103002121901386BD6D8E0913E72WX%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D12%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Pitch 5.08 mm berbeda dari BOM 5.00 mm, jadi verifikasi jarak lubang PCB sebelum checkout.

- `4K7` dan `4k7` berarti nilai yang sama, yaitu 4.7k ohm.
- Untuk resistor dan kapasitor, pilih ukuran **0805**, bukan 0603 atau 1206.
- Pastikan relay memiliki coil **5V**.
- Pastikan `SS34` menggunakan package **SMA** dan `PMLL4148L` menggunakan **SOD-80**.
- ESP32 yang dibutuhkan adalah varian **ESP32-S3-WROOM-1 N16R8**.
- Komponen pasif sebaiknya dibeli ekstra 10-20% untuk mengantisipasi kerusakan atau kehilangan saat soldering.
- W5500 module sudah tersedia dalam stok, sehingga kebutuhan pembelian W5500 dapat dikurangi 1 unit.
- AMS1117-3.3V dari Marnov dipilih sebanyak 2 pcs: [Tokopedia Marnov - AMS1117-3.3V](https://www.tokopedia.com/marnov/ams1117-3-3v-voltage-regulator-ams-1117-1pcs-1ce32?extParam=ivf%3Dfalse%26keyword%3Dams1117-3.3%26search_id%3D20261030011849F8C1F23D6A8D8D16F020%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D4%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dgoods_search%26t_sm%3D%26t_spt%3Dsearch_result).
- STM32F407VGT6 DevEBox dipilih dari HWThinker: [Tokopedia HWThinker - DeveBox STM32F407VGT6](https://www.tokopedia.com/hwthinker/devebox-stm32f407vgt6-stm32f4-f407-stm32-sd-slot-development-board-cortex-m4-1731604961438041160?t_id=1793321566134%26t_st=9%26t_pp=cart%26t_efo=cart%26t_ef=goods_search%26t_sm=%26t_spt=cart).
- ADS1115 16-bit ADC dipilih dari Marnov: [Tokopedia Marnov - ADS1115 4-channel](https://www.tokopedia.com/marnov/ads1115-16-bit-adc-4-channel-programmable-gain-amplifier-ads-1115-1731271119828453342).
- DS3231SN SOP-16 dipilih dari Elekterong: [Tokopedia Elekterong - DS3231SN](https://www.tokopedia.com/elekterong/ds3231sn-ds3231-ds3231s-sop-16-new-original-mantaff).
- AT24C01 SOP-8 dari Elekterong: [Tokopedia Elekterong - AT24C01](https://www.tokopedia.com/elekterong/new-original-at24c01-24c01-eeprom-sop-8-mantafff).
- ADuM1250ARZ SOP-8 dari Elekterong: [Tokopedia Elekterong - ADuM1250ARZ](https://www.tokopedia.com/elekterong/adum1250arz-adum1250-1250arz-sop-8-new-original-mantaff).
- SP3485EN-L/TR dari Syalis Electrical: [Tokopedia Syalis Electrical - SP3485EN-L/TR](https://www.tokopedia.com/syalis-electrical/sp3485en-l-tr-sp3485een-ic-rs485-rs422-sop-8-pengganti-max3485esa-syalis-1734266263423124860).
- 74HC04D dari Marnov: [Tokopedia Marnov - 74HC04D](https://www.tokopedia.com/marnov/74hc04-smd-ttl-7404-74ls04-hex-inverting-gate-logic-74hc04d?extParam=ivf%3Dfalse%26keyword%3D74hc04d%26search_id%3D20261030011713147D8854E763C5191Y4V%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D1%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dgoods_search%26t_sm%3D%26t_spt%3Dsearch_result).
- B0505S-1W dari Sellered: [Tokopedia Sellered - B0505S-1W converter](https://www.tokopedia.com/sellered/b0505s-1w-5v-to-5v-converter-dc-dc-power-module-converter-b0505s-1w?extParam=ivf%3Dfalse%26keyword%3Db0505s%26search_id%3D20261030011737147D8854E763C53A338N%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D2%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result).
- LM2596S-5.0 dari Marnov: [Tokopedia Marnov - LM2596S-5.0](https://www.tokopedia.com/marnov/lm2596s-5-0v-chip-ic-lm2596-fix-5v-3a-step-down?extParam=ivf%3Dfalse%26keyword%3Dlm2596s-5.0%26search_id%3D202610300118281543843A4723ED0F1670%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D3%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dgoods_search%26t_sm%3D%26t_spt%3Dsearch_result).

### Catatan AT24C01 versus AT24C256W

- BOM membutuhkan `AT24C256W-10SI-1.8`, yaitu EEPROM **256 Kbit**.
- Produk pada link adalah `AT24C01`, yaitu EEPROM **1 Kbit**.
- Keduanya sama-sama keluarga EEPROM I2C dan package SOP-8, tetapi kapasitas memorinya berbeda jauh. AT24C01 hanya boleh dipakai jika firmware dan kebutuhan penyimpanan memang cukup 1 Kbit.
- Untuk penggantian langsung sesuai BOM, cari `AT24C256W-10SI-1.8` atau `24C256 1.8V SOP-8`.
- Kandidat lain: [Tokopedia Tekno Kreasi Elektronik - AT24C256 I2C module](https://www.tokopedia.com/tekno-kreasi-elektronik/at24c256-2ecl-iic-i2c-serial-interface-port-eeprom-memory-module?extParam=ivf%3Dfalse%26keyword%3Dat24c256w-10si-1.8%26search_id%3D20261030011323F8C1F23D6A8D8D3BFHUF%26src%3Dsearch%26t_id%3D1793321566134%26t_st%3D10%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dgoods_search%26t_sm%3D%26t_spt%3Dsearch_result).
- Modul tersebut sesuai kapasitas 24C256, tetapi **bukan pengganti langsung** karena memiliki PCB modul, header, dan kemungkinan regulator/pull-up. Verifikasi tegangan kerja, alamat I2C, serta apakah modul dapat dipasang di luar PCB melalui kabel.

### Catatan tindakan

- **HAPUS AT24C01 dari daftar pembelian. Jangan checkout produk AT24C01 dari Elekterong.** Kapasitasnya hanya 1 Kbit dan tidak sesuai dengan kebutuhan `AT24C256W` pada BOM.
- ADuM1250ARZ memiliki fungsi yang sama dengan `ADUM1250WSRZ-RL7` pada BOM, tetapi suffix part/package dapat berbeda. Sebelum checkout, minta foto marking dan drawing package, lalu cocokkan dengan footprint PCB `SOIC-8_L4.9-W4.0-P1.27-LS6.0-BL`.
- `ADUM5402WCRWZ-1RL` belum ditemukan di pencarian Tokopedia dan belum ditandai aman untuk dibeli.
- Kata kunci alternatif: `ADuM5402 WSOIC-16`, `ADUM5402WCRWZ`, `ADUM5402 isolated DC DC`, atau `ADuM5402 digital isolator 5V`.
- Jangan mengganti dengan ADuM5401, ADuM5403, modul isolator umum, atau DC-DC isolator biasa tanpa verifikasi fungsi, jumlah kanal, tegangan, dan footprint `WSOIC-16`.
- Listing B0505S-1W terlihat sebagai modul converter. BOM membutuhkan `B0505S-1WR2` dengan footprint `PWRM-TH_B0505S-1WR2`. Verifikasi apakah yang dikirim adalah IC/komponen through-hole, bukan modul PCB, sebelum checkout.

### Catatan ADS1115

- BOM awal menulis `ADS1155`, sedangkan produk yang dipilih adalah `ADS1115`.
- ADS1115 adalah ADC 16-bit 4-channel dengan programmable gain amplifier dan antarmuka I2C.
- Perlakukan sebagai **substitusi**, bukan kecocokan part number langsung. Verifikasi alamat I2C, pinout, tegangan suplai, footprint/modul, dan kompatibilitas firmware sebelum pemasangan.

## Kandidat produk Tokopedia yang ditemukan

### ESP32-S3-WROOM-1U U Antena Pigtail N16R8

| Item | Detail |
|---|---|
| Status | **Dipilih untuk pembelian** |
| Harga pada halaman | Rp68.000 per buah |
| Stok yang ditampilkan | 269 buah |
| Varian | ESP32-S3-WROOM-1U, N16R8, 16 MB Flash, 8 MB PSRAM |
| Penjual | Marnov, Kota Bandung |
| Rating | 5,0 dari 5,0, 19 rating |
| Link | [Tokopedia Marnov - ESP32-S3-WROOM-1U N16R8](https://www.tokopedia.com/marnov/esp32-s3-wroom-1u-u-antena-pigtail-n16r8-chip-wroom-16mb-flash-8mb-psram-esp32s3-aiot?extParam=ivf%3Dfalse%26keyword%3Desp32-s3-wroom-1+n16r8%26search_id%3D20261030010714147D8854E763C53501Z4%26src%3Dsearch) |

**Keputusan pembelian:** Produk ini ditetapkan sebagai pengganti BOM untuk ESP32. BOM mencantumkan `ESP32-S3-WROOM-1(N16R8)`, sedangkan produk yang dipilih adalah `ESP32-S3-WROOM-1U`. Sufiks **1U** berarti antena eksternal melalui konektor/pigtail, bukan antena PCB bawaan.

Sebelum checkout, tanyakan kepada penjual:

1. Apakah modul benar-benar varian **N16R8**.
2. Apakah footprint dan posisi pin sama dengan `ESP32-S3-WROOM-1` pada PCB.
3. Apakah sudah termasuk antena eksternal dan kabel pigtail.
4. Apakah varian tanpa antena eksternal atau varian `WROOM-1` tersedia.

Untuk pembelian ini, siapkan dan gunakan antena eksternal serta kabel pigtail sesuai konektor modul. Jangan mengandalkan antena PCB bawaan. Pastikan area clearance antena eksternal tidak tertutup logam atau enclosure.
- Holder baterai CR1220 SMD dari ArduinoNano dipilih: [Tokopedia ArduinoNano - CR1220 SMD holder](https://www.tokopedia.com/arduinonano/cr1220-battery-button-coin-cell-holder-cr-1220-1216-socket-smd-case?extParam=ivf%3Dfalse%26keyword%3Dcr1220%2Bsmd%26search_id%3D20261030011914ED57D5A221CE5101AF8T%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D5%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_goods%26t_sm%3D%26t_spt%3Dsearch_result).
- TF/micro-SD socket SMD dari HWThinker dipilih: [Tokopedia HWThinker - micro SD card socket](https://www.tokopedia.com/hwthinker/micro-sd-card-sdcard-reader-adapter-connector-tf-slot-socket-pcb-push?extParam=ivf%3Dfalse%26keyword%3Dtf%2Bcard%2Bsmd%2Bsocket%2Btf-15-15%26search_id%3D202610300119395C774A62CDFCB5014CHW%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D6%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result).
- Relay Songle SRD-05VDC-SL-C dari CNC Store Bandung dipilih sebanyak 4 pcs: [Tokopedia CNC Store Bandung - SRD-05VDC-SL-C](https://www.tokopedia.com/cncstorebandung/cnc-relay-songle-5v-10a-srd-05vdc-sl-c-5-pin-5p?extParam=ivf%3Dfalse%26keyword%3Dsrd-05vdc-sl-c%26search_id%3D20261030020527F8C1F23D6A8D8D2BBP4A%26src%3Dsearch).
- PC817 DIP dari Marnov: [Tokopedia Marnov - PC817 DIP 4-pin](https://www.tokopedia.com/marnov/pc817-817-pc817c-dip-optocoupler-photocoupler-4-pin-1733458584786143169?extParam=ivf%3Dfalse%26keyword%3Dpc817x3nszw%26search_id%3D20261030020607147D8854E763C53B7J42%26src%3Dsearch%26t_id%3D1793323039784%26t_st%3D8%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result).
- Package listing sudah sesuai dengan footprint BOM `DIP-4_L6.4-W4.6-P2.54-LS7.6-BL`. Pastikan CTR, tegangan isolasi, dan konfigurasi pin PC817C sesuai kebutuhan rangkaian sebelum membeli 4 pcs.
- MMBT3904/2N3904 SOT-23 dari SMG Jaya Tronik dipilih: [Tokopedia SMG Jaya Tronik - MMBT3904](https://www.tokopedia.com/smgjayatronik/mmbt3904-2n3904-smd-sot23-1am-per-10-pcs-1729892126757848967?extParam=ivf%3Dfalse%26keyword%3D2n3904%2Bsot-23%26search_id%3D20261030020740ED57D5A221CE513B8JFJ%26src%3Dsearch). Listing dijual per 10 pcs, sehingga 1 paket mencukupi kebutuhan 4 pcs.
