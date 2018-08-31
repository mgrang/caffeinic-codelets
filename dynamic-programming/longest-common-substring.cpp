#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int lcs(string s, string t) {
  int n = s.length();
  int m = t.length();

  int T[n + 1][m + 1];

  for (int i = 0; i <= n; ++i)
    T[0][i] = 0;

  for (int i = 0; i <= m; ++i)
    T[i][0] = 0;

  string str, maxStr;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        if (s[i - 2] == t[j - 2]) {
          T[i][j] = 1 + T[i - 1][j - 1];
        }
        else
          T[i][j] = 1;
      }
      else
        T[i][j] = std::max(T[i - 1][j], T[i][j - 1]);
    }
  }

  return T[n][m];
}

int main() {
  string s = "typograph";
  string t = "photograph";

  cout << "Input strings: " << s << ", " << t << "\n";
  cout << "LCS length: " << lcs(s, t) << "\n";
}
