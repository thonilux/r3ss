# BOM Panel RESS

| Komponen | Jumlah | Spesifikasi / catatan | Link |
|---|---:|---|---|
| MCB instrumentasi | 1 | CHINT NXB 2P 6 A, 6 kA | [Tokopedia](https://www.tokopedia.com/chint-electric-official/mcb-chint-nxb-2p-6ka-6a-10a-16a-20a-25a-32a-40a-2p-6a) |
| MCB beban kontaktor | 0 tambahan | **Sudah tersedia di masing-masing PCB beban kontaktor** | Verifikasi rating dan koordinasi dengan kabel/suplai panel |
| Proteksi coil kontrol | 1 | **MCB CHINT EB 1P 1 A**, khusus jalur coil AC220 V dan switch/relay | Verifikasi rating 220/230 VAC, breaking capacity, serta arus coil total | [Tokopedia Taesolo](https://www.tokopedia.com/taesolo/chint-mcb-eb-1p-1a) |
| SPD L-N | 2 | 1P+N, Uc 275 VAC, Type 2; verifikasi Imax dan PE/N | [Fugastore](https://www.tokopedia.com/fugastore/surge-arrester-spd-ac-1p-n-10ka-60ka-b-385v-275v-protector-1732239704118363808) |
| EMI filter | 1 | FXSM CW1B-L, pilih varian **6 A**, cabang 220 VAC instrumentasi | [FXSM](https://www.tokopedia.com/fxsm/emi-filter-noise-filter-1-phase-cw1b-l-040-cw1b-3a-6a-10a-l-040-1734441481791046769) |
| PSU DIN-rail | 1 | Mean Well HDR-30-12, 12 VDC 2 A / 30 W | [Magna Automation](https://www.tokopedia.com/magnaautomation/mean-well-meanwell-hdr-30-12-30w-12vdc-2a-industrial-din-rail-psu) |
| PSU alternatif | 1 | HDR-15-12, 12 VDC 1,25 A / 15 W | [ArduinoID](https://www.tokopedia.com/arduinoid/din-rail-dc-power-supply-industrial-hdr-15-12-12v-1-25a-15w-psu-switching-untuk-panel-automation-plc-1736007483357168792) |
| Kontaktor | 4 | CHINT NXC-40, 3P 40 A, coil AC220 V; verifikasi AC-1/AC-3 | [Selektrik](https://www.tokopedia.com/selektrik/kontaktor-chint-nxc-9-12-18-25-32-40-50-65-85-100a-3p-ac220v-380v-nxc-40-ac220v-fb4e0) |
| Terminal panel | **4 buah × 3P = 12 posisi** | Kebutuhan minimum 11 posisi: 2 titik input **L/N** + 1 titik **GND kontrol** + 2 titik × 4 kontaktor (**COM + satu output: NO atau NC**) | 1 posisi cadangan. [Tokopedia Centrale Electrind - EWIG IN-30BK 3P 50 A](https://www.tokopedia.com/centralelectrind/terminal-block-din-rail-ewig-in-30bk-3p-50a) |
| Bus distribusi panel | 3 unit warna | Kuning = PE/G bus; biru = N bus; merah = L keluaran MCB coil 1 A | [Tokopedia Sahabat Jaya - UKK distribution box](https://www.tokopedia.com/sahabatjaya1/distribution-box-din-rail-terminal-block-ukk-80a-125a-160a-250a-400a-500a-1731539263140562515) |

## Catatan bus

- Sediakan juga distribusi **L terlindungi setelah MCB 2P 6 A** untuk dua cabang: EMI filter/PSU dan MCB coil 1 A.
- Jika terminal keluaran MCB 6 A langsung dipakai ke EMI filter, gunakan terminal/jumper ber-rating sesuai sebagai titik cabang ke MCB 1 A; jangan membuat bus L sebelum MCB.
- Bus merah setelah MCB 1 A hanya untuk rangkaian coil/switch kontrol, bukan untuk PSU.

## Catatan

- PSU 12 V perlu regulator untuk rail 5 V/3,3 V RESS.
- EMI filter 1-fase bukan untuk jalur beban 3-fase 380 VAC.
- Semua rating dan wiring wajib diverifikasi sebelum instalasi.
