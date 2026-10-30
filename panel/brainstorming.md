# Brainstorming Panel RESS

## Konteks

- Panel instalasi high-voltage 220/380 VAC.
- Baseplate **47 x 37 cm**.
- Enclosure/panel: **ABS transparan** untuk inspeksi visual.
- Instrumentasi RESS berada di box DIN-rail LK-PLC20 (acuan 179 x 108 x 77 mm).
- Pisahkan fisik jalur HV dari low-voltage/control.

## Strategi blok

```text
Incoming 220/380 VAC
  -> cabang instrumentasi: MCB 2P 6 A -> SPD/EMI -> PSU DIN-rail -> LK-PLC20
  -> cabang beban: MCB/fuse kontaktor sesuai beban -> kontak utama kontaktor -> beban
  -> cabang kontrol: fuse/MCB kecil -> switch service -> coil kontaktor AC220 V
```

## Kontrol dan keselamatan

- Empat kontaktor memakai coil AC220 V; relay Songle PCB mengendalikan coil.
- MCB beban sudah tersedia di masing-masing PCB beban kontaktor. Tidak perlu membeli MCB beban tambahan di panel ini; tetap verifikasi rating, kabel, dan koordinasi proteksinya.
- Jalur coil AC220 V juga diberi proteksi kontrol tersendiri dengan rating berdasarkan arus coil.
- Tambahkan interlock agar manual dan otomatis tidak backfeed.
- Gunakan barrier/dead-front, PE bonding, gland, strain relief, dan duct HV terpisah.
- ABS transparan bukan pengganti barrier/dead-front; bagian bertegangan tetap harus tidak dapat tersentuh dari luar.
- Verifikasi clearance/creepage, PE, polaritas, isolasi, dan proteksi sebelum energisasi.
- Servis hanya setelah lockout/tagout dan verifikasi bebas tegangan.

## Hal yang harus dikunci

- Dimensi PCB, lubang mounting, terminal, arah kabel, dan clearance antena.
- Konfigurasi SPD untuk sistem aktual.
- Rating AC-1/AC-3 kontaktor terhadap beban.
- Regulator 12 V ke 5 V/3,3 V dan total daya.
