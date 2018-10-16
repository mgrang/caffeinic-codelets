#include <iostream>
#include <vector>
using namespace std;

int traverse(vector<vector<int>> matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  int T[n][m];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (i == 0 || j == 0)
        T[i][j] = 1;
      else
        T[i][j] = T[i - 1][j] + T[i][j - 1];
  }

  return T[n - 1][m - 1];
}

void test(vector<vector<int>> matrix) {
  cout << "Input:\n";
  for (auto rows : matrix) {
    for (auto i : rows)
      cout << i << " ";
    cout << "\n";
  }

  cout << "Total way to traverse matrix: " << traverse(matrix);
  cout << "\n";
}

int main() {
  test({{1, 1, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}});
  test({{1}});
  test({{}});
  test({{1, 0, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}});
  test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  test({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}});
}
