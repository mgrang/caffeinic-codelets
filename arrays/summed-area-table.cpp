#include <iostream>
#include <vector>
using namespace std;

using Vec = vector<vector<int>>;

int getSum(Vec &V, int tli, int tlj, int rbi, int rbj) {
  int n = V.size();
  int m = V[0].size();
  Vec S(n, vector<int>(m));

  for (int i = 0 ; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      S[i][j] = V[i][j];

      if (i == 0 && j == 0)
        continue;

      if (i == 0)
        S[i][j] += S[i][j - 1];
      else if (j == 0)
        S[i][j] += S[i - 1][j];
      else
        S[i][j] += S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1];
    }
  }

  int sum = S[rbi][rbj];
  if (tli)
    sum -= S[tli - 1][rbj];
  if (tlj)
    sum -= S[rbi][tlj - 1];
  if (tli && tlj)
    sum += S[tli - 1][tlj - 1];
  return sum;
}

void test(Vec V, int tli, int tlj, int rbi, int rbj) {
  cout << "Input:\n";
  for (const auto row : V) {
    for (const auto i : row)
      cout << i << " ";
    cout << "\n";
  }
  auto sum = getSum(V, tli, tlj, rbi, rbj);
  cout << "Sum between (" << tli << ", " << tlj << ") and (" << rbi << ", " << rbj << "): " << sum;
  cout << "\n-------------------------------------------------------------------\n";
}

int main() {
  test({{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}}, 2, 1, 4, 3);
  test({{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}}, 0, 0, 1, 1);
}
