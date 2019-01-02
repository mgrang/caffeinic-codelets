#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

void swap(vector<char> &V, int i, int j) {
  auto tmp = V[i];
  V[i] = V[j];
  V[j] = tmp;
}

void test(vector<char> V) {
  cout << "Input: ";
  for (const auto c : V)
    cout << c << " ";
  cout << "\n";

  int n = V.size();
  int left = 0;
  int right = n - 1;

  while (left < right) {
    swap(V, left, right);
    ++left;
    --right;
  }

  left = 0;
  right = 0;
  while (right < n) {
    while (right < n && V[right] != ' ')
      ++right;

    --right;

    if (left >= n || right >= n)
      break;

    int i = left;
    int j = right;
    while (i < j) {
      swap(V, i, j);
      ++i;
      --j;
    }

    ++right;
    while (right < n && V[right] == ' ')
      ++right;
    left = right;
  }

  cout << "Output: ";
  for (const auto c : V)
    cout << c << " ";
  cout << "\n";
}

int main() {
  test({'p', 'e', 'r', 'f', 'e', 'c', 't', ' ', 'm', 'a', 'k', 'e', 's', ' ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'});
}
