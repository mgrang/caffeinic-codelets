#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

void insertionSort(vector<int> &V) {
  for (int i = 1; i < V.size(); ++i) {
    int val = V[i];
    int j = i - 1;

    while (j >= 0 && V[j] > val) {
      V[j + 1] = V[j];
      --j;
    }

    V[++j] = val;
  }
}

void test(vector<int> V) {
  cout << "Array: ";
  print(V);

  cout << "Sorted array: ";
  insertionSort(V);
  print(V);
  cout << "--------------------------------------------\n";
}

int main() {
  test({1, 2, 3, 4, 5, 6, 7, 8});
  test({1, 2, 3, 4, 5, 6, 7, 8, 9});
  test({8, 7, 6, 5, 4, 3, 2, 1});
  test({9, 8, 7, 6, 5, 4, 3, 2, 1});
  test({1, 8, 3, 6, 5, 4, 7, 2, 9});
  test({1, 2, 3, 4, 4, 3, 2, 1});
  test({8, 2, 1, 3, 7, 6, 9, 4, 5});
  test({1});
  test({2, 1});
  test({3, 1, 2});
  test({});
  test({1, 1, 1, 1, 1});
  test({40, 2, 10, 100, 76, 32, 8});
  test({2, 3, 1, 4, 5, 1, 1, 1, 1});
  test({6, 7, 8, 1, 2, 3, 4, 5});
}
