// Program statistika sederhana yang menghitung mean, median, dan modus dari sekumpulan data dengan memanfaatkan iterasi & selection
// Catatan: Hanya menambahkan komentar, tidak mengubah perilaku program.
// Dibuat oleh: Muhammad Fachrizal Giffari
// NIM : 22/504570/TK/55192
// Kelas : A
// Mata Kuliah : Pemrograman Dasar

#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Masukkan data: ";
  if (!(cin >> n) || n <= 0) {
    // Validasi awal agar program tidak lanjut dengan input yang tidak masuk akal
    cout << "Data tidak valid.\n";
  }

  // Penting: untuk bisa dapat median & modus tanpa menyimpan semua data,
  // input harus diberikan dalam urutan non-menurun (terurut naik, boleh sama).
  cout << "Masukkan " << n << " nilai (urut non-menurun agar median/modus valid):\n";

  double sum = 0.0; // akumulator untuk mean

  // Menentukan posisi median dengan indeks 1-based
  // mid1 dan mid2 akan sama untuk n ganjil; untuk n genap median = (a[mid1] + a[mid2]) / 2
  const int mid1 = (n % 2 == 0) ? (n / 2) : ((n + 1) / 2);
  const int mid2 = (n % 2 == 0) ? (n / 2 + 1) : mid1;
  double m1 = 0.0, m2 = 0.0; // penampung nilai median saat streaming input

  // Flag dan variabel bantu untuk cek keterurutan input dan hitung modus via run-length
  bool hasPrev = false, sorted = true; // diasumsikan terurut sampai terbukti sebaliknya
  double prev = 0.0;

  // Pelacakan run nilai yang sama untuk modus
  double curVal = 0.0; // nilai pada run saat ini
  int curCount = 0;    // panjang run saat ini

  double modeVal = 0.0;   // kandidat nilai modus (jika unik)
  int bestCount = 0;      // frekuensi tertinggi yang ditemukan
  int modeCount = 0;      // berapa banyak nilai yang memiliki frekuensi tertinggi (deteksi multi-modus)

  // Baca data satu per satu (single-pass)
  for (int i = 1; i <= n; ++i) {
    double x;
    cin >> x;
    sum += x; // akumulasi untuk mean

    // Ambil nilai median saat indeks input mencapai mid1/mid2
    if (i == mid1) m1 = x;
    if (i == mid2) m2 = x;

    if (!hasPrev) {
      // Inisialisasi run pertama
      hasPrev = true;
      prev = x;
      curVal = x; curCount = 1;
      bestCount = 1; modeVal = x; modeCount = 1;
    } else {
      // Jika input menurun, tandai tidak terurut (median/modus tidak valid tanpa penyimpanan)
      if (x < prev) sorted = false;

      // Perbarui run-length untuk modus
      if (x == curVal) {
        ++curCount; // lanjut run yang sama
      } else {
        // Tutup run sebelumnya, bandingkan dengan best
        if (curCount > bestCount) {
          bestCount = curCount; modeVal = curVal; modeCount = 1;
        } else if (curCount == bestCount) {
          // Ada run lain dengan frekuensi yang sama
          ++modeCount;
        }
        // Mulai run baru
        curVal = x; curCount = 1;
      }
      prev = x;
    }
  }

  // Finalisasi run terakhir (karena loop berakhir tanpa menutup run)
  if (hasPrev) {
    if (curCount > bestCount) {
      bestCount = curCount; modeVal = curVal; modeCount = 1;
    } else if (curCount == bestCount) {
      ++modeCount;
    }
  }

  // Hitung nilai mean & median siap pakai untuk menu
  const double mean = sum / n;
  const double median = (m1 + m2) / 2.0;

  // Menu sederhana berbasis switch-case
  while (true) {
    cout << "\n=== MENU ===\n"
         << "1. Mean\n"
         << "2. Median\n"
         << "3. Modus\n"
         << "0. Keluar\n"
         << "Pilih: ";
    int c;
    if (!(cin >> c)) break; // keluar jika input menu tidak valid

    switch (c) {
      case 0:
        cout << "Selesai.\n";
        return 0;

      case 1:
        // Mean selalu tersedia karena hanya butuh jumlah dan n
        cout << "Mean: " << mean << "\n";
        break;

      case 2:
        // Median hanya valid jika data benar-benar terurut saat input
        if (!sorted) {
          cout << "Median tidak tersedia: data tidak terurut.\n";
        } else {
          cout << "Median: " << median << "\n";
        }
        break;

      case 3:
        // Modus via run-length pada data terurut
        if (!sorted) {
          cout << "Modus tidak tersedia: data tidak terurut.\n";
        } else if (bestCount <= 1) {
          // Semua nilai unik (tidak ada pengulangan)
          cout << "Modus: tidak ada (semua nilai unik)\n";
        } else if (modeCount == 1) {
          // Tepat satu nilai dengan frekuensi tertinggi
          cout << "Modus: " << modeVal << " (frekuensi " << bestCount << ")\n";
        } else {
          // Ada lebih dari satu nilai yang sama-sama paling sering
          cout << "Modus: lebih dari satu nilai dengan frekuensi " << bestCount << "\n";
        }
        break;

      default:
        // Penanganan pilihan menu di luar opsi yang disediakan
        cout << "Pilihan tidak dikenal.\n";
    }
  }

}