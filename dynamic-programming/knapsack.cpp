#include <algorithm>
#include <iostream>
using namespace std;

std::pair<int, std::vector<int>>
knapsack(int target, std::vector<int> wts, std::vector<int> vals) {
  int T[wts.size() + 1][target + 1];

  for (int i = 0; i <= wts.size(); ++i) {
    for(int j = 0; j <= target; ++j) {
      if (i == 0 || j == 0)
        T[i][j] = 0;

      else if (j < wts[i - 1])
        T[i][j] = T[i - 1][j];

      else
        T[i][j] = std::max(T[i - 1][j],
                           vals[i - 1] + T[i - 1][j - wts[i - 1]]);
    }
  }

  std::vector<int> items;
  int i = wts.size();
  int j = target;
  while (i && j && T[i][j]) {
    if (T[i][j] == vals[i - 1] + T[i - 1][j - wts[i - 1]]) {
      items.insert(items.begin(), wts[i - 1]);
      j -= wts[i - 1];
    }
    --i;
  }

  return std::make_pair(T[wts.size()][target], items);
}

int main() {
  int target = 6;
  std::vector<int> wts = {1, 3, 4, 5};
  std::vector<int> vals = {1, 4, 5, 7};

  auto k = knapsack(target, wts, vals);

  cout << "Max val: " << k.first << "\n";
  cout << "Wts.: ";
  for (auto w : k.second)
    cout << w << " ";
  cout << "\n";
}
