#include <iostream>
#include <vector>
using namespace std;

int maxSquareWithSidesOne(vector<vector<int>> matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  std::pair<int, int> T[n][m];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j] == 0)
        T[i][j] = std::make_pair(0, 0);
      else {
        int left = j == 0 ? 0 : (T[i][j - 1]).first;
        int up = i == 0 ? 0 : (T[i - 1][j]).second;
        T[i][j] = std::make_pair(left + 1, up + 1);
      }
    }
  }

  int maxSize = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      int x = T[i][j].first;
      int y = T[i][j].second;

      int currSize = std::min(x, y);
      while (currSize > maxSize) {
        int left = j - currSize + 1;
        if (T[i][left].second < currSize) {
          --currSize;
          continue;
        }

        int up = i - currSize + 1;
        if (T[up][j].first < currSize) {
          --currSize;
          continue;
        }

        maxSize = currSize;

        --currSize;
        if (currSize <= maxSize)
          break;
      }
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

  auto res = maxSquareWithSidesOne(matrix);
  cout << "Max size square matrix: " << res << "x" << res;
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
