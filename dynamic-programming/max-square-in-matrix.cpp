#include <iostream>
#include <vector>
using namespace std;

int maxSquareInMatrix(vector<vector<int>> matrix) {
  int maxSize = 0;
  int n = matrix.size();
  int m = matrix[0].size();
  int T[n][m];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 || j == 0 || matrix[i][j] == 0)
        T[i][j] = matrix[i][j];
      else
        T[i][j] = 1 + std::min(T[i - 1][j - 1],
                               std::min(T[i - 1][j], T[i][j - 1]));
      if (T[i][j] > maxSize)
        maxSize = T[i][j];
    }
  }
  return maxSize;
}

void test(vector<vector<int>> matrix) {
  cout << "Input:\n";
  for (auto rows : matrix) {
    for (auto i : rows)
      cout << i << " ";
    cout << "\n";
  }

  auto res = maxSquareInMatrix(matrix);
  cout << "Max size sub-square matrix: " << res << "x" << res;
  cout << "\n";
}

int main() {
  test({{1, 1, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}});
  test({{1}});
  test({{}});
  test({{1, 0, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}});
  test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  test({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}});
  test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
  test({{0, 0, 1, 1, 1}, {1, 0, 1, 1, 1}, {0, 1, 1, 1, 1}, {1, 0, 1, 1, 1}});
}
