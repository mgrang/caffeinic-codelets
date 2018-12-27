#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

void merge(vector<int> &V, int lo, int mid, int hi) {
  vector<int> W;
  int l = lo;
  int h = mid + 1;

  while (l <= mid && h <= hi) {
    V[l] <= V[h]        ?
    W.push_back(V[l++]) :
    W.push_back(V[h++]) ;
  }

  while (l <= mid)
    W.push_back(V[l++]);

  while (h <= hi)
    W.push_back(V[h++]);

  for (auto i : W)
    V[lo++] = i;
}

void mergesort(vector<int> &V, int lo, int hi) {
  if (lo >= hi)
    return;

  int mid = (lo + hi) / 2;
  mergesort(V, lo, mid);
  mergesort(V, mid + 1, hi);
  merge(V, lo, mid, hi);
}

void test(vector<int> V) {
  cout << "Array: ";
  print(V);

  cout << "Sorted array: ";
  mergesort(V, 0, V.size() - 1);
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
