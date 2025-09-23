#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cout << "Berapa banyak bilangan prima yang ingin dicetak? ";
  cin >> n;

  if (n <= 1) {
    cout << "Tolong cetak lebih dari 1!" << endl;
    return 0;
  }

  int sum = 0, count = 0, num = 2;

  cout << n << " deret pertama bilangan prima: ";

  while (count < n) {
    bool is_prime = num > 1;
    if (is_prime) {
      const int limit = static_cast<int>(sqrt(num));
      for (int i = 2; i <= limit; ++i) {
        if (num % i == 0) {
          is_prime = false;
          break;
        }
      }
    }

    if (is_prime) {
      cout << num << " ";
      sum += num;
      ++count;
    }
    ++num;
  }

  cout << endl;
  cout << "Jumlah dari deret tersebut: " << sum << endl;
}
