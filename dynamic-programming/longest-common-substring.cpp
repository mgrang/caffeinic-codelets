#include <iostream>
#include <string>
using namespace std;

typedef struct {
  int len;
  string str;
} LCS;

int lcs_opt(string s, string t) {
  int n = s.length();
  int m = t.length();
  int size = n < m ? n : m;

  int row0[size] = {0};
  int row1[size] = {0};

  int *prev = row0;
  int *curr = row1;

  int maxLen = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] != t[j]) {
        *curr = 0;
        continue;
      }

      *curr = 1;
      if (prev != row0 && prev != row1)
        *curr += *(prev - 1);

      if (*curr > maxLen)
        maxLen = *curr;

      ++curr;
      ++prev;
    }

    int *tmp = curr;
    curr = prev;
    prev = tmp;
  }

  return maxLen;
}

LCS lcs(string s, string t) {
  int n = s.length();
  int m = t.length();

  int T[n + 1][m + 1];

  for (int i = 0; i <= n; ++i)
    T[0][i] = 0;

  for (int i = 0; i <= m; ++i)
    T[i][0] = 0;

  int maxLen = 0;
  int maxi, maxj;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] != t[j - 1]) {
        T[i][j] = 0;
        continue;
      }

      T[i][j] = 1 + T[i - 1][j - 1];

      if (T[i][j] > maxLen) {
        maxLen = T[i][j];
        maxi = i;
        maxj = j;
      }
    }
  }

  string maxStr;
  while (maxi && maxj && T[maxi][maxj]) {
    maxStr = s[maxi - 1] + maxStr;
    --maxi;
    --maxj;
  }

  return LCS {maxLen, maxStr};
}

int main() {
  string s = "typograph";
  string t = "photograph";

  cout << "Input strings: " << s << ", " << t << "\n";
  LCS res = lcs(s, t);
  cout << "LCS len: " << res.len << "\n";
  cout << "LCS str: " << res.str << "\n";

  cout << "LCS optimized len: " << lcs_opt(s, t) << "\n";
}
