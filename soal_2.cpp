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
    cout << "Data tidak valid.\n";
    return 0;
  }

  cout << "Masukkan " << n << " nilai (urut non-menurun agar median/modus valid):\n";

  double sum = 0.0;

  // Indeks median (1-based)
  int mid1 = (n % 2 == 0) ? (n / 2) : ((n + 1) / 2);
  int mid2 = (n % 2 == 0) ? (n / 2 + 1) : mid1;
  double m1 = 0.0, m2 = 0.0;

  // Pelacakan keterurutan dan modus (run-length)
  bool hasPrev = false, sorted = true;
  double prev = 0.0;

  double curVal = 0.0;
  int curCount = 0;

  double modeVal = 0.0;   // satu nilai modus (jika unik)
  int bestCount = 0;      // frekuensi tertinggi
  int modeCount = 0;      // jumlah nilai yang mencapai frekuensi tertinggi (untuk deteksi multi-modus)

  for (int i = 1; i <= n; ++i) {
    double x;
    cin >> x;
    sum += x;

    if (i == mid1) m1 = x;
    if (i == mid2) m2 = x;

    if (!hasPrev) {
      hasPrev = true;
      prev = x;
      curVal = x; curCount = 1;
      bestCount = 1; modeVal = x; modeCount = 1;
    } else {
      if (x < prev) sorted = false;
      if (x == curVal) {
        ++curCount;
      } else {
        if (curCount > bestCount) { bestCount = curCount; modeVal = curVal; modeCount = 1; }
        else if (curCount == bestCount) { ++modeCount; }
        curVal = x; curCount = 1;
      }
      prev = x;
    }
  }

  // Finalisasi run terakhir untuk modus
  if (hasPrev) {
    if (curCount > bestCount) { bestCount = curCount; modeVal = curVal; modeCount = 1; }
    else if (curCount == bestCount) { ++modeCount; }
  }

  const double mean = sum / n;
  const double median = (m1 + m2) / 2.0;

  while (true) {
    cout << "\n=== MENU ===\n"
         << "1. Mean\n"
         << "2. Median\n"
         << "3. Modus\n"
         << "0. Keluar\n"
         << "Pilih: ";
    int c;
    if (!(cin >> c)) break;

    switch (c) {
      case 0:
        cout << "Selesai.\n";
        return 0;

      case 1:
        cout << "Mean: " << mean << "\n";
        break;

      case 2:
        if (!sorted) {
          cout << "Median tidak tersedia: data tidak terurut.\n";
        } else {
          cout << "Median: " << median << "\n";
        }
        break;

      case 3:
        if (!sorted) {
          cout << "Modus tidak tersedia: data tidak terurut.\n";
        } else if (bestCount <= 1) {
          cout << "Modus: tidak ada (semua nilai unik)\n";
        } else if (modeCount == 1) {
          cout << "Modus: " << modeVal << " (frekuensi " << bestCount << ")\n";
        } else {
          cout << "Modus: lebih dari satu nilai dengan frekuensi " << bestCount << "\n";
        }
        break;

      default:
        cout << "Pilihan tidak dikenal.\n";
    }
  }

}