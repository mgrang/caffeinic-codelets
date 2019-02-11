#include <iostream>
#include <vector>
using namespace std;

bool isValid(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

void visit(vector<vector<int>> &V, int i, int j,
           vector<vector<bool>> &visited) {
  int n = V.size();
  int m = V[0].size();

  if (!isValid(i, j, n, m))
    return;

  if (!V[i][j])
    return;

  if (visited[i][j])
    return;

  visited[i][j] = true;

  visit(V, i+1, j,   visited);
  visit(V, i-1, j,   visited);
  visit(V, i,   j+1, visited);
  visit(V, i,   j-1, visited);
}

int countIslands(vector<vector<int>> &V) {
  int n = V.size();
  int m = V[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m));

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (V[i][j] && !visited[i][j]) {
        visit(V, i, j, visited);
        ++count;
      }
    }
  }
  return count;
}

void test(vector<vector<int>> V) {
  cout << "Input:\n";
  for (const auto row : V) {
    for (const auto item : row)
      cout << item << " ";
    cout << "\n";
  }
  cout << "No. of islands: " << countIslands(V) << "\n";
  cout << "---------------------\n";
}

int main() {
  test({{1, 1, 1, 1, 0}, {1, 1, 0, 1, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 0, 0}});
  test({{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}});
  test({{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}});
  test({{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}});
  test({{1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}});
}
