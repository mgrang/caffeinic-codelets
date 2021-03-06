#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int lcs(string s, string t) {
  int n = s.length();
  int m = t.length();

  int T[n + 1][m + 1];

  for (int i = 0; i <= n; ++i)
    T[i][0] = 0;

  for (int i = 0; i <= m; ++i)
    T[0][i] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      T[i][j] = (s[i] == t[j]) ?
                1 + T[i - 1][j - 1] :
                std::max(T[i - 1][j], T[i][j - 1]);
    }
  }
  return T[n][m];
}

void test(string s, string t) {
  cout << "LCS between " << s << " and " << t
       << " is: " << lcs(s, t) << "\n";
}

int main() {
  test("logarithm", "algorithm");
  test("abcde", "acde");
  test("photography", "typography");
  test("abcd", "xyz");
  test("aaaaaaaaaaaaa", "a");
  test("ababa", "babab");
}
