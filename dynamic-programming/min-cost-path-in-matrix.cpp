#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

std::pair<int, vector<int>>
minCostPath(vector<vector<int>> matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  int T[n][m];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      T[i][j] = matrix[i][j];

      if (i == 0 && j == 0)
        continue;

      if (i == 0)
        T[i][j] += T[i][j - 1];
      else if (j == 0)
        T[i][j] += T[i - 1][j];
      else
        T[i][j] += std::min(T[i - 1][j], T[i][j - 1]);
    }
  }

  vector<int> P;
  int i = n - 1;
  int j = m - 1;
  while (n && m && i >= 0 || j >= 0) {
    P.insert(P.begin(), matrix[i][j]);
    if (i == 0 && j == 0)
      break;
    if (i == 0) --j;
    else if (j == 0) --i;
    else if (matrix[i - 1][j] < matrix[i][j - 1]) --i;
    else --j;
  }

  return std::make_pair(T[n - 1][m - 1], P);
}

void test(vector<vector<int>> matrix) {
  cout << "Input:\n";
  for (auto rows : matrix) {
    for (auto i : rows)
      cout << i << " ";
    cout << "\n";
  }

  auto res = minCostPath(matrix);
  cout << "Min cost path: " << res.first;
  cout << "\nMin path:\n";
  for (auto i : res.second)
    cout << i << " ";
  cout << "\n";
}

int main() {
  test({{1, 3, 5, 8}, {4, 2, 1, 7}, {4, 3, 2, 3}});
  test({{1}});
  test({{}});
  test({{1, 0, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}});
  test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  test({{4, 0, 6, 7}, {1, 3, 0, 2}, {0, 2, 4, 8}, {9, 0, 3, 1}});
}
