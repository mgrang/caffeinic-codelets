#include <algorithm>
#include <iostream>
using namespace std;

std::pair<int, string> lps(string s) {
  int T[s.length()][s.length()];

  for (int i = 0; i < s.length(); ++i)
    for (int j = 0; j < s.length(); ++j)
      T[i][j] = 0;

  int start = 0;
  int end = s.length();

  while (start < s.length()) {
    int i = 0;
    int j = start;

    while (i < end && j < s.length()) {
      if (i == j)
        T[i][j] = 1;
      else if (s[i] == s[j])
        T[i][j] = 2 + T[i + 1][j - 1];
      else
        T[i][j] = std::max(T[i + 1][j], T[i][j - 1]);

      ++i;
      ++j;
    }
    ++start;
    --end;
  }

  int c[s.length()] = {0};
  int i = 0;
  int j = s.length() - 1;
  while (i <= j && T[i][j]) {
    if (i == j) {
      c[i] = 1;
      break;
    } else if (T[i][j] == T[i + 1][j - 1]) {
      ++i;
      --j;
      continue;
    } else if (T[i][j] == T[i + 1][j]) {
      ++i;
      continue;
    } else if (T[i][j] == T[i][j - 1]) {
      --j;
      continue;
    } else if (T[i][j] == 2 + T[i + 1][j - 1]) {
      c[i] = 1;
      c[j] = 1;
      ++i;
      --j;
      continue;
    }
  }

  string t;
  for (int i = 0; i < s.length(); ++i)
    if (c[i])
      t += s[i];

  return std::make_pair(T[0][s.length() - 1], t);
}

int main() {
  string s = "xzyzaybx";
  cout << "Input: " << s << "\n";

  auto p = lps(s);

  cout << "LPS len: " << p.first << "\n";
  cout << "LPS: " << p.second << "\n";
}
