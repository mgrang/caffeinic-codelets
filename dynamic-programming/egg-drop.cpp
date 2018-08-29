#include <algorithm>
#include <iostream>
using namespace std;

int egg_drop(int e, int f) {
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

int main() {
  cout << "Eggs Floors Tries\n";
  cout << "1    1      " << egg_drop(1, 1) << "\n";
  cout << "1    2      " << egg_drop(1, 2) << "\n";
  cout << "1    3      " << egg_drop(1, 3) << "\n";
  cout << "1    4      " << egg_drop(1, 4) << "\n";
  cout << "1    5      " << egg_drop(1, 5) << "\n";
  cout << "1    6      " << egg_drop(1, 6) << "\n";

  cout << "2    1      " << egg_drop(2, 1) << "\n";
  cout << "2    2      " << egg_drop(2, 2) << "\n";
  cout << "2    3      " << egg_drop(2, 3) << "\n";
  cout << "2    4      " << egg_drop(2, 4) << "\n";
  cout << "2    5      " << egg_drop(2, 5) << "\n";
  cout << "2    6      " << egg_drop(2, 6) << "\n";

  cout << "4    8      " << egg_drop(4, 8) << "\n";
}
