// Program dengan C++ memanfaatkan kombinasi antara Iterasi & Selection untuk mencetak deret bilangan Prima serta menjumlahkan deretnya
// Catatan: Hanya menambahkan komentar, tidak mengubah perilaku program.
// Dibuat oleh: Muhammad Fachrizal Giffari
// NIM : 22/504570/TK/55192
// Kelas : A
// Mata Kuliah : Pemrograman Dasar

#include <iostream>
#include <cmath> // library untuk fungsi sqrt

using namespace std;

int main() {
  // Minta input jumlah bilangan prima yang ingin dicetak
  int n;
  cout << "Berapa banyak bilangan prima yang ingin dicetak? ";
  cin >> n;

  // Validasi input sederhana
  if (n <= 1) {
    cout << "Tolong cetak lebih dari 1!" << endl;
    return 0;
  }

  // sum: akumulasi jumlah bilangan prima
  // count: berapa banyak bilangan prima yang sudah dicetak
  // num: kandidat bilangan yang akan dicek keprimaannya
  int sum = 0, count = 0, num = 2;

  cout << n << " deret pertama bilangan prima: ";

  // Ulangi sampai terkumpul n bilangan prima
  while (count < n) {
    // Anggap awalnya prima jika num > 1
    bool is_prime = num > 1;

    if (is_prime) {
      // Batas pemeriksaan cukup sampai akar kuadrat dari num
      // static_cast<int> untuk membulatkan ke bawah dan menghindari perbandingan int vs double
      const int limit = static_cast<int>(sqrt(num));

      // Cek apakah num punya pembagi di rentang [2, limit]
      for (int i = 2; i <= limit; ++i) {
        if (num % i == 0) {
          // Jika ada pembagi, berarti bukan bilangan prima
          is_prime = false;
          break; // Tidak perlu lanjut cek
        }
      }
    }

    if (is_prime) {
      // Jika prima, cetak dan tambahkan ke jumlah serta tambah hitungan
      cout << num << " ";
      sum += num;
      ++count;
    }

    // Coba kandidat berikutnya
    ++num;
  }

  // Baris baru setelah daftar bilangan prima
  cout << endl;

  // Tampilkan jumlah dari semua bilangan prima yang dicetak
  cout << "Jumlah dari deret tersebut: " << sum << endl;
}
