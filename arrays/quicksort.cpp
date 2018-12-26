#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

int partition(vector<int> &V, int lo, int hi) {
  int pivot = V[hi];
  int i = lo;

  for (int j = lo; j < hi; ++j) {
    if (V[j] < pivot) {
      if (i < j)
        swap(V, i, j);
      ++i;
    }
  }

  // i is now pointing to an element greater than pivot. So swap it with pivot.
  swap(V, i, hi);
  return i;
}

void quicksort(vector<int> &V, int lo, int hi) {
  if (lo >= hi)
    return;

  int p = partition(V, lo, hi);
  quicksort(V, lo, p - 1);
  quicksort(V, p + 1, hi);
}

void test(vector<int> V) {
  cout << "Array: ";
  print(V);

  cout << "Sorted array: ";
  quicksort(V, 0, V.size() - 1);
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
