#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

int binarySearch(vector<int> &V, int k, int left, int right) {
  cout << "Inside Binary Search\n";

  if (!V.size())
    return -1;

  if (k < V[0] || k > V[V.size() - 1])
    return -1;

  int mid = (left + right) / 2;
  if (V[mid] == k)
    return mid;

  if (left == right)
    return -1;

  if (V[mid] < k)
    return binarySearch(V, k, mid, right);

  return binarySearch(V, k, left, mid);
}

void test(vector<int> V, int k) {
  cout << "Array: ";
  print(V);

  cout << "Found " << k << " at idx: " << binarySearch(V, k, 0, V.size()) << "\n";
  cout << "--------------------------------------------\n";
}

int main() {
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 0);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 7);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 8);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 11);
  test({1}, 0);
  test({1}, 1);
  test({1}, 2);
  test({}, 1);
  test({1, 2, 2, 3, 4, 4, 5}, 2);
  test({1, 2, 2, 3, 4, 4, 5}, 4);
  test({1, 1, 1, 1, 1, 1, 2}, 1);
  test({1, 1, 1, 1, 1, 1, 2}, 2);
  test({1, 2, 2, 2, 2, 2, 2}, 1);
}
