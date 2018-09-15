#include <algorithm>
#include <iostream>
using namespace std;

int eggDrop(int e, int f) {
  int T[e + 1][f + 1];

  for (int j = 0; j <= f; ++j)
    T[1][j] = j;

  for (int i = 2; i <= e; ++i) {
    for (int j = 1; j <= f; ++j) {
      if (i >= j) {
        T[i][j] = T[i - 1][j];
        continue;
      }

      T[i][j] = std::numeric_limits<int>::max();
      for (int k = 1; k <= j; ++k) {
        int tries = 1 + std::max(T[i - 1][k - 1], T[i][j - k]);
        if (tries < T[i][j])
          T[i][j] = tries;
      }
    }
  }

  return T[e][f];
}

void test(int e, int f) {
  cout << "eggs: " << e
       << ", floors: " << f
       << ", tries: " << eggDrop(e, f)
       << "\n";
}

int main() {
  test(1, 1);
  test(1, 2);
  test(1, 3);
  test(1, 4);
  test(1, 5);
  test(1, 6);
  test(2, 1);
  test(2, 2);
  test(2, 3);
  test(2, 4);
  test(2, 5);
  test(2, 6);
  test(4, 8);
}
