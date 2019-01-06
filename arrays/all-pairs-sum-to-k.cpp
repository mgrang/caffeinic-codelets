#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "util.h"
using namespace std;

void test(vector<int> V, int k) {
  unordered_map<int, int> M;
  vector<std::pair<int, int>> res;

  for (const auto i : V) {
    if (M.count(k - i) && M[k - i]) {
        res.push_back(std::make_pair(i, k - i));
        M[k - i] -= 1;
    }
    M[i] += 1;
  }

  for (const auto &pair : res)
    cout << "(" << pair.first << ", " << pair.second << ") ";
  cout << "\n";
}

int main() {
  test({1, 3, 2, 2, 5, 6, 7, 4}, 5);
}
