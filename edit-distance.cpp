#include <iostream>
#include <string>
using namespace std;

int EditDistance(string s, string t) {
  int n = s.length();
  int m = t.length();

  int D[n][m];
  for (int i = 0; i < n; ++i)
    D[i][0] = i;

  for (int j = 0; j < m; ++j)
    D[0][j] = j;

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      D[i][j] = std::min(std::min(D[i - 1][j] + 1,
                                  D[i][j - 1] + 1),
                         D[i - 1][j - 1] + (s[i] != t[j]));
    }
  }

  return D[n - 1][m - 1];
}

int main() {
  string s = "algorithm";
  string t = "logarithm";

  cout << "### Input strings: " << s << ", " << t << "\n";
  cout << "### Edit distance: " << EditDistance(s, t) << "\n";
}
