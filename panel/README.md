# Panel RESS

Dokumen utama dipisah menjadi [brainstorming.md](brainstorming.md) dan [bom.md](bom.md).

Lihat kedua file tersebut untuk detail desain dan daftar belanja.

<!-- Arsip requirement lama dipertahankan di bawah. -->

## Status

- **Project:** RESS PCB2_1
- **Versi:** V0.1 devboard
- **Target produksi:** 2 unit
- **Ukuran baseplate:** 47 x 37 cm *(asumsi unit cm; konfirmasi jika maksudnya mm)*
- **Tegangan instalasi:** 220/380 VAC nominal
- **Interpretasi:** 220 VAC fase–netral dan 380 VAC antar-fase
- **Status:** Requirement awal, perlu validasi ukuran mekanik dari PCB aktual

## Tujuan

Membuat panel instalasi high-voltage 220/380 VAC dengan instrumentasi RESS yang sudah dikemas dalam enclosure DIN-rail LK-PLC20. Panel harus memisahkan sisi high-voltage dari enclosure instrumentasi dan kabel low-voltage/control.

## Packaging instrumentasi

Instrumentasi RESS menggunakan box **LK-PLC20** dengan spesifikasi acuan:

| Parameter | Nilai |
|---|---|
| Model | LK-PLC20 |
| Dimensi eksternal | 179 x 108 x 77 mm |
| Material | ABS |
| Mounting | DIN-rail |
| Fungsi | Enclosure PLC kecil, modul kontrol, dan elektronik custom |

Catatan:

- LK-PLC20 digunakan untuk PCB/instrumentasi low-voltage, bukan sebagai pengganti enclosure keselamatan untuk terminal 220/380 VAC.
- Sediakan ruang DIN-rail, clearance kabel, dan akses konektor tanpa membuka area high-voltage.
- Verifikasi dimensi internal LK-PLC20 terhadap PCB, modul MAX485, W5500, terminal, dan kabel sebelum produksi.
- Warna/varian box dapat dipilih hitam atau putih/abu-abu sesuai panel.

## Strategi komponen panel daya

Panel daya 220/380 VAC menggunakan susunan utama berikut:

| Komponen | Jumlah | Fungsi | Parameter yang harus dikunci |
|---|---:|---|---|
| MCB L dan N | 2 pole CHINT, **6 A minimum** | Pemutus/proteksi jalur fase dan netral instrumentasi | Kurva trip, breaking capacity, rating AC, dan kesesuaian kabel |
| SPD L-N | 2 unit, kandidat **275 VAC putih** | Proteksi surge jalur L-N | Pastikan Type 2, Uc 275 VAC, Up, Imax 10-60 kA, konfigurasi grounding |
| Terminal kontaktor | 4 titik/terminal | Distribusi koneksi menuju kontaktor | Penampang kabel, arus, rating 220/380 VAC |
| Kontaktor | 4 unit, kandidat CHINT NXC-40 | Switching beban | **Coil AC220 V**; 3P, 40 A; verifikasi AC-1/AC-3 dan kategori beban |
| EMI filter | 1 unit, kandidat **CW1B-L 6 A** | Reduksi noise conducted pada cabang 220 VAC instrumentasi | Arus nominal, tegangan 220 VAC L-N, skema PE, leakage current; bukan untuk jalur 3-fase 380 VAC |
| PSU DIN-rail | 1 unit, kandidat utama **Mean Well HDR-30-12** | Catu daya low-voltage untuk instrumentasi | Input 220 VAC, output **12 VDC 2 A / 30 W**, isolasi dan kapasitas daya |

### Urutan blok panel

```text
Incoming 220/380 VAC
        |
   MCB L/N
        |
      SPD L-N ---- PE/ground
        |
    EMI filter
        |
   PSU DIN-rail ---- low-voltage instrumentasi LK-PLC20
        |
   Kontak kontaktor x4 ---- beban
```

Catatan desain:

- Jumlah dan fungsi SPD harus dikonfirmasi terhadap sistem 1-fase/3-fase dan skema PE/N yang digunakan. Untuk sistem 3-fase, konfigurasi SPD tidak boleh diasumsikan hanya dua unit L-N.
- MCB netral harus mengikuti aturan instalasi setempat dan tidak boleh memutus N secara terpisah jika standar sistem mensyaratkan pemutusan serentak.
- MCB instrumentasi ditetapkan awal sebagai **CHINT 2P 6 A**, dengan L dan N diputus serentak. Rating 6 A adalah rating MCB, bukan target konsumsi instrumentasi.
- Untuk PSU/instrumentasi, kurva B atau C ditentukan dari arus inrush PSU. Jangan memilih kurva hanya berdasarkan nama merek.
- Kandidat produk: [Tokopedia CHINT Electric Official - NXB 2P 6 A 6 kA](https://www.tokopedia.com/chint-electric-official/mcb-chint-nxb-2p-6ka-6a-10a-16a-20a-25a-32a-40a-2p-6a?extParam=ivf%3Dfalse%26keyword%3Dmcb%2B2p%26search_id%3D2026103005161904F5B96522DC7E27BFHJ%26src%3Dsearch%26t_id%3D1793337388887%26t_st%3D1%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result).
- SPD kandidat Fugastore: [Surge Arrester SPD AC 1P+N 275 V](https://www.tokopedia.com/fugastore/surge-arrester-spd-ac-1p-n-10ka-60ka-b-385v-275v-protector-1732239704118363808?extParam=ivf%3Dfalse%26keyword%3Dspd%2B1p%2Bn%26search_id%3D20261030051857BEED13602B9B0E258OA8%26src%3Dsearch%26t_id%3D1793337388887%26t_st%3D2%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Kebutuhan **2 unit**. Pastikan label menyatakan Uc 275 VAC, Type 2, Imax minimal 10 kA, indikator status, dan terminal PE/N yang sesuai.
- Kontaktor, terminal, EMI filter, SPD, dan MCB wajib memiliki rating yang sesuai 220/380 VAC dan beban aktual.
- PSU DIN-rail harus ditempatkan di sisi low-voltage setelah proteksi dan filter, dengan pemisahan kabel dari jalur beban.
- Semua komponen logam panel wajib dibonding ke PE. Gunakan barrier dan duct kabel terpisah untuk HV dan kontrol.
- Kandidat kontaktor: [Tokopedia Selektrik - CHINT NXC-40 3P AC220 V](https://www.tokopedia.com/selektrik/kontaktor-chint-nxc-9-12-18-25-32-40-50-65-85-100a-3p-ac220v-380v-nxc-40-ac220v-fb4e0?extParam=ivf%3Dfalse%26keyword%3Dkontaktor%2B40a%26search_id%3D2026103005222304F5B96522DC7E32A86K%26src%3Dsearch%26t_id%3D1793337388887%26t_st%3D5%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Kebutuhan **4 unit**. Coil AC220 V harus dipastikan sesuai strategi kontrol; jika coil dikendalikan dari PSU low-voltage, pilih coil 24 VDC sebagai gantinya.
- Kandidat EMI filter: [Tokopedia FXSM - CW1B-L 040, varian 3/6/10 A](https://www.tokopedia.com/fxsm/emi-filter-noise-filter-1-phase-cw1b-l-040-cw1b-3a-6a-10a-l-040-1734441481791046769?extParam=ivf%3Dfalse%26keyword%3Demi%2Bfilter%26search_id%3D2026103005282201386BD6D8E09134EOGC%26src%3Dsearch%26t_id%3D1793337388887%26t_st%3D6%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Pilih **varian 6 A** untuk cabang instrumentasi 220 VAC setelah MCB 6 A; verifikasi label 250 VAC atau lebih, terminal L/N/PE, dan arus leakage.
- Kandidat PSU: [Tokopedia ArduinoID - DIN-rail HDR-15-12, 12 VDC 1,25 A / 15 W](https://www.tokopedia.com/arduinoid/din-rail-dc-power-supply-industrial-hdr-15-12-12v-1-25a-15w-psu-switching-untuk-panel-automation-plc-1736007483357168792?extParam=ivf%3Dfalse%26keyword%3Dpsu%2Bdinrail%2B12v%26search_id%3D202610300530395C774A62CDFCB503CT55%26src%3Dsearch%26t_id%3D1793337388887%26t_st%3D7%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Output 12 V tidak langsung menggantikan rail 5 V/3,3 V; verifikasi kebutuhan beban dan sediakan regulator DC-DC/LDO yang sesuai.
- Kandidat utama PSU: [Tokopedia Magna Automation - Mean Well HDR-30-12, 12 VDC 2 A / 30 W](https://www.tokopedia.com/magnaautomation/mean-well-meanwell-hdr-30-12-30w-12vdc-2a-industrial-din-rail-psu?extParam=ivf%3Dfalse%26keyword%3Dmeanwell%2B12v%2Bdinrail%26search_id%3D202610300534211543843A4723ED35ABCL%26src%3Dsearch%26t_id%3D1793337388887%26t_st%3D10%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result). Dipilih karena margin daya lebih besar; tetap perlu regulator 5 V/3,3 V untuk RESS.
- Alternatif ekonomis: [ArduinoID HDR-15-12, 12 VDC 1,25 A / 15 W](https://www.tokopedia.com/arduinoid/din-rail-dc-power-supply-industrial-hdr-15-12-12v-1-25a-15w-psu-switching-untuk-panel-automation-plc-1736007483357168792?extParam=ivf%3Dfalse%26keyword%3Dpsu%2Bdinrail%2B12v%26search_id%3D202610300530395C774A62CDFCB503CT55%26src%3Dsearch%26t_id%3D1793337388887%26t_st%3D7%26t_pp%3Dsearch_result%26t_efo%3Dsearch_pure_goods_card%26t_ef%3Dsearch_result%26t_sm%3D%26t_spt%3Dsearch_result).

## Komponen yang harus diakomodasi

- PCB RESS PCB2_1: 2 unit produksi.
- ESP32-S3-WROOM-1U N16R8 dengan antena eksternal/pigtail.
- STM32F407VGT6 DevEBox: 1 unit tahap awal, target akhir 2 unit.
- Modul MAX485 RS485-to-TTL eksternal.
- Modul W5500: stok internal.
- Relay SRD-05VDC-SL-C 5 V.
- Terminal block 2-pin, 3-pin, dan 4-pin.
- Slot micro-SD/TF, jika fitur ini diaktifkan kembali.
- Holder baterai CR1220.

## Antarmuka panel

Panel harus menyediakan ruang atau bukaan untuk:

- Input power/Vin.
- Terminal MODBUS/RS485.
- Terminal I/O 3-pin dan 4-pin.
- RJ45/W5500 atau konektor Ethernet terkait.
- Akses micro-SD/TF jika dipasang.
- LED indikator merah dan hijau.
- Antena eksternal ESP32 dan kabel pigtail.
- Lubang servis untuk reset/boot bila tombol berada di PCB.

## Konstruksi mekanik

- Bentuk: panel/enclosure tertutup dengan baseplate dan cover yang dapat dikunci.
- Material: gunakan enclosure/panel yang sesuai untuk instalasi listrik. Jangan mengandalkan akrilik atau 3D print tanpa verifikasi rating isolasi, flame rating, dan ketahanan mekaniknya.
- Semua komponen high-voltage dan terminal harus terlindung dari sentuhan langsung.
- Sediakan strain relief untuk kabel eksternal.
- Sediakan ventilasi bila relay, regulator, atau converter menghasilkan panas.
- Jangan menutup atau menekan area antena ESP32.
- Pisahkan jalur/kabel power dari area antena dan jalur sinyal sensitif.
- Gunakan spacer/standoff PCB yang sesuai lubang mounting aktual.

## Keselamatan high-voltage

- Panel ditujukan untuk instalasi listrik **220/380 VAC**.
- Semua komponen sisi daya harus memiliki rating yang sesuai untuk sistem 220/380 VAC, termasuk terminal, relay, fuse/MCB, kabel, gland, barrier, dan enclosure.
- Jangan menganggap rating 24 VDC pada kapasitor atau modul kontrol sebagai rating sisi 220/380 VAC.

- Pisahkan kompartemen high-voltage dari kompartemen low-voltage/control.
- Gunakan barrier isolasi fisik antara terminal high-voltage dan PCB/control.
- Gunakan gland/strain relief kabel yang sesuai diameter dan rating kabel.
- Sediakan titik PE/grounding panel dan bonding bagian logam sesuai standar instalasi yang berlaku.
- Sediakan penandaan **HIGH VOLTAGE**, label terminal, arah aliran, dan peringatan bahaya.
- Gunakan cover/dead-front sehingga bagian bertegangan tidak dapat tersentuh saat cover dibuka sebagian.
- Sediakan pemutus utama, isolator, atau emergency disconnect sesuai desain sistem.
- Pastikan fuse, breaker, relay, terminal, kabel, dan enclosure memiliki rating tegangan serta arus yang sesuai beban.
- Jangan menempatkan kabel high-voltage sejajar rapat dengan kabel komunikasi/sensor tanpa pemisah.
- Kabel high-voltage dan low-voltage harus menggunakan jalur masuk/keluar yang berbeda.
- Pengujian insulation, continuity PE, polarity, dielectric withstand, dan fungsi proteksi wajib dilakukan oleh personel kompeten sebelum energisasi.
- Jangan melakukan servis saat panel bertegangan. Terapkan lockout/tagout dan verifikasi tidak bertegangan sebelum menyentuh bagian dalam.

## Kontrol manual service

- Strategi kontrol kontaktor memakai **coil AC220 V**.
- Relay Songle di PCB RESS hanya mengendalikan coil kontaktor melalui kontaknya.
- Tambahkan switch manual **ON-OFF** atau **HAND-OFF-AUTO** untuk service.
- Switch harus memiliki rating minimal 250 VAC dan rating sesuai beban induktif coil.
- Gunakan interlock agar mode manual dan otomatis tidak saling backfeed.
- Sediakan fuse/MCB kecil khusus rangkaian coil dan label `MANUAL`, `AUTO`, `OFF`, serta `DANGER 220 VAC`.
- Semua terminal dan switch harus terlindung dari sentuhan langsung.

## Dimensi dan data yang wajib diukur

Parameter berikut belum boleh diasumsikan dan harus diambil dari PCB/assembly aktual:

| Parameter | Nilai |
|---|---|
| Panjang PCB | TBD |
| Lebar PCB | TBD |
| Posisi dan diameter lubang mounting | TBD |
| Tinggi komponen tertinggi | TBD |
| Posisi semua terminal/konektor | TBD |
| Arah keluar kabel | TBD |
| Ukuran modul MAX485 dan W5500 | TBD |
| Area clearance antena ESP32 | TBD |
| Ukuran box final | PCB + clearance TBD |

## Baseplate

- Ukuran dasar: **47 x 37 cm**.
- Box/panel, posisi PCB, jalur kabel, dan lubang mounting harus ditempatkan di dalam area baseplate ini.
- Sisakan area tepi untuk baut, dinding box, terminal kabel, dan radius tekuk kabel.

## Clearance minimum awal

- Clearance sisi PCB ke dinding box: minimal 3 mm.
- Clearance komponen tinggi ke cover: minimal 5 mm dari komponen tertinggi.
- Clearance konektor dan kabel: minimal 10 mm dari dinding/cover.
- Clearance antena eksternal: mengikuti antena yang dipilih dan tidak tertutup logam.
- Jangan menempatkan logam di dekat area antena ESP32.
- Clearance dan creepage high-voltage harus ditentukan dari tegangan kerja, kategori instalasi, polusi lingkungan, material isolasi, dan standar yang digunakan. Nilai final wajib diverifikasi secara engineering, bukan diasumsikan dari angka minimum umum.

## Catatan desain penting

- Modul MAX485 adalah pengganti transceiver RS485 onboard. Box harus menyediakan lokasi modul atau jalur kabelnya.
- SP3485, resettable fuse, dan TVS tidak dibeli pada strategi produksi saat ini.
- Terminal yang tersedia memiliki pitch 5,08 mm, sedangkan footprint PCB tertulis 5,00 mm. Verifikasi sebelum mengunci dimensi bukaan panel.
- Kapasitor dan komponen modifikasi tidak boleh mengganggu cover atau spacer.
- Desain harus dapat dibuka untuk debugging, penggantian modul, dan pengukuran.
- Jalur high-voltage tidak boleh melewati area PCB/control kecuali sudah ada barrier dan routing yang tervalidasi.

## Output yang diharapkan

- Gambar layout panel atas dan bawah.
- Gambar posisi lubang mounting dan konektor.
- Model 3D atau gambar kerja box.
- File produksi sesuai metode yang dipilih: DXF/STL/STEP atau gambar 2D berdimensi.
- Daftar ukuran final dan checklist verifikasi sebelum produksi.

## Acceptance checklist

- [ ] PCB terpasang tanpa menekan komponen.
- [ ] Cover dapat ditutup tanpa menyentuh ESP32, relay, kapasitor, atau konektor.
- [ ] Semua terminal dapat dipasang dan dilepas.
- [ ] Antena ESP32 memiliki clearance yang cukup.
- [ ] Modul MAX485 dapat diakses atau diganti.
- [ ] Jalur kabel memiliki strain relief.
- [ ] Tidak ada bagian bertegangan yang mudah tersentuh.
- [ ] Kompartemen high-voltage dan low-voltage terpisah secara fisik.
- [ ] PE/grounding panel, barrier, gland, fuse/breaker, dan label high-voltage sudah diverifikasi.
- [ ] Clearance/creepage sudah dihitung sesuai standar dan tegangan kerja.
- [ ] Uji keselamatan listrik dilakukan sebelum panel diberi tegangan.
- [ ] Box lolos uji pasang untuk 2 unit produksi.
