# Tugas Iterasi & Kombinasi (C++)

Proyek C++ sederhana yang berisi dua program konsol:
- `soal_1`: mencetak n bilangan prima pertama lalu menghitung jumlahnya.
- `soal_2`: menghitung mean, median, dan modus dari data yang diinput pengguna tanpa menggunakan array (hanya `<iostream>`). Median dan modus valid jika data dimasukkan dalam urutan non-menurun (terurut naik, boleh sama).

## Struktur Proyek
- `CMakeLists.txt` — konfigurasi CMake (menggunakan `clang++`, standar C++17, dan meletakkan output ke `bin/`).
- `soal_1.cpp` — logika pencetakan bilangan prima dan penjumlahan deretnya.
- `soal_2.cpp` — program statistika sederhana berbasis menu (switch-case) tanpa array.

## Prasyarat
- Linux
- CMake ≥ 3.16
- Clang++ (compiler C++)
- Standar C++17

Catatan: `CMakeLists.txt` sudah mengatur agar compiler yang digunakan adalah `clang++`, menyalakan peringatan umum (`-Wall -Wextra -Wpedantic`), dan menaruh binary di folder `bin/` dalam direktori build.

## Build
Bangun proyek dengan CMake (out-of-source build direkomendasikan):

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

Hasil build (binary) akan berada di:
- `build/bin/soal_1`
- `build/bin/soal_2`

## Menjalankan

### soal_1 — Deret Bilangan Prima + Jumlahnya
Jalankan program:

```bash
./build/bin/soal_1
```

Contoh interaksi:
```
Berapa banyak bilangan prima yang ingin dicetak? 5
5 deret pertama bilangan prima: 2 3 5 7 11
Jumlah dari deret tersebut: 28
```

Ringkas logika:
- Pengecekan prima dilakukan langsung di dalam `main` (tidak modular).
- Untuk setiap kandidat `num`, pembagian hanya dicek sampai `sqrt(num)`.
- Menggunakan `static_cast<int>` pada batas akar untuk menghindari konversi implisit `double`→`int` dan perbandingan campuran.

### soal_2 — Statistika Sederhana (tanpa array)
Jalankan program:

```bash
./build/bin/soal_2
```

Fitur:
- Input jumlah data lalu masukkan nilai data satu per satu.
- Menu berbasis `switch-case`: 1=Mean, 2=Median, 3=Modus, 0=Keluar.
- Tidak menggunakan array/struktur penyimpanan; perhitungan dilakukan satu lintasan (single-pass) saat input.
- Median dan modus hanya valid jika data dimasukkan dalam urutan non-menurun.

Contoh interaksi (data terurut):
```
Masukkan data: 5
Masukkan 5 nilai (urut non-menurun agar median/modus valid):
1 2 2 4 9

=== MENU ===
1. Mean
2. Median
3. Modus
0. Keluar
Pilih: 1
Mean: 3.6
Pilih: 2
Median: 2
Pilih: 3
Modus: 2 (frekuensi 2)
Pilih: 0
Selesai.
```

Jika data tidak terurut, program akan memberi tahu bahwa Median/Modus tidak tersedia tanpa penyimpanan data.

Ringkas logika:
- Mean: akumulasi jumlah dibagi `n` (selalu tersedia).
- Median: posisi median (`mid1`, `mid2`) diambil saat input masuk (hanya benar jika input terurut).
- Modus: dihitung dengan run-length (menghitung panjang deret nilai yang sama pada input terurut). Jika ada lebih dari satu nilai dengan frekuensi maksimum, program menginformasikan multi-modus.
- Program hanya menggunakan `<iostream>`.

## Catatan Tambahan
- Target CMake: `soal_1` dan `soal_2`. Output binari berada di `bin/` dalam folder build (`build/bin/...`).
- Anda dapat membuka folder proyek ini di CLion; IDE akan mendeteksi CMake dan menyiapkan target otomatis.

