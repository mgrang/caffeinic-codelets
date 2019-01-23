#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

vector<vector<int>> spiral(int n) {
  vector<vector<int>> V(n, vector<int>(n));

  int i = 0, j = 0, val = 1;

  while (n > 0) {
    int count = n;
    while (n > 0 && count--)
      V[i][j++] = val++;

    i++;
    j--;
    n--;

    count = n;
    while (n > 0 && count--)
      V[i++][j] = val++;

    i--;
    j--;

    count = n;
    while (n > 0 && count--)
      V[i][j--] = val++;

    i--;
    j++;
    n--;

    count = n;
    while (n > 0 && count--)
      V[i--][j] = val++;

    i++;
    j++;
  }

  return V;
}

void test(int n) {
  auto arr = spiral(n);

  cout << "n: " << n << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr[i][j] < 10)
        cout << "0";
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "----------------------------------------------------\n";
}

int main() {
  test(0);
  test(1);
  test(2);
  test(3);
  test(4);
  test(5);
  test(6);
  test(7);
  test(8);
  test(10);
}
