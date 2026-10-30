# RESS BMS ⚡🔋

> Workspace buat ngoprek BMS/inverter pakai ESP32, Modbus, dan PCB. Basically: listrik, kabel, dan sedikit chaos 😎🛠️

## Folder tour 🗺️

| Folder | Isi |
|---|---|
| `firmware/` | Semua project PlatformIO: source, library, include, test, config |
| `goodwee/` | Dokumentasi dan referensi Modbus RTU GoodWe |
| `sungrow/` | Dokumentasi dan tool komunikasi Sungrow |
| `docs/` | Dokumen skematik dan catatan teknis |
| `hardware/` | Gambar PCB, Gerber, overlay, dan board reference |
| `tools/` | Script bantu pengolahan dokumen |
| `junk/` | ZIP/archive yang lagi di-parkir 🗃️ |
| `tmp/` | File sementara |
| `temp_pages/` | Hasil ekstraksi/render halaman sementara |

## Firmware mode 🚀

Buka folder `firmware/` sebagai project PlatformIO. Config utama ada di:

```text
firmware/platformio.ini
```

Run dari root workspace:

```powershell
pio run -d firmware
pio run -d firmware -t upload
pio device monitor -d firmware
```

## Sungrow Modbus TCP 🌐

Scanner read-only ada di sini:

```text
sungrow/tcp-scan.py
```

Contoh:

```powershell
python sungrow/tcp-scan.py 192.168.1.100 --unit 1 --start 0 --end 100 --function 3 --verbose
```

Scanner cuma baca pakai function code `03`/`04`. No write command, no drama 🙅‍♂️📡

## Heads-up ⚠️

Register wajib dicocokkan dengan model + firmware inverter. Jangan kirim command write sebelum register dan permission-nya verified. Safety first, always ⚡🧯
