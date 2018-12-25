#include <algorithm>
#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

double getMedian(vector<int> &a, vector<int> &b) {
  int n = a.size();
  int m = b.size();
  int mn = (n + m + 1) / 2;

  if (m < n) {
    int tmp = n;
    n = m;
    m = tmp;

    a.swap(b);
  }

  int left = 0;
  int right = n;

  while (left >= 0 && right <= n) {
    int idxA = (left + right) / 2;
    int idxB = mn - idxA;
  
    int leftA = idxA ? a[idxA - 1] : std::numeric_limits<int>::min();
    int rightA = (idxA < n) ? a[idxA] : std::numeric_limits<int>::max();
  
    int leftB = b[idxB - 1];
    int rightB = b[idxB];

    if (leftA <= rightB && leftB <= rightA) {
      return ((m + n) % 2) ? std::max(leftA, leftB) :
             double (std::max(leftA, leftB) + std::min(rightA, rightB)) / 2;
    }
  
    if (leftA > rightB)
      right = idxA - 1;
    else left = idxA + 1;
  }

  return std::numeric_limits<int>::min();
}

void test(vector<int> a, vector<int> b) {
  cout << "Array A: ";
  print(a);
  cout << "Array B: ";
  print(b);
  cout << "Median: " << getMedian(a, b) << "\n";
  cout << "-----------------------------------------------\n";
}

int main() {
  test({1, 2, 3, 4, 5, 6}, {10, 20, 30});
  test({1, 3, 8, 9, 15}, {7, 11, 18, 19, 21, 25});
  test({3, 5, 7, 9, 11, 16}, {23, 26, 31, 35});
}
