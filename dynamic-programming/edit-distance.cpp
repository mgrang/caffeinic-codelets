#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct {
  int D;
  string E;
} ED;

ED editDistance(string s, string t) {
  int n = s.length();
  int m = t.length();

  string E;
  int D[n + 1][m + 1];

  for (int i = 0; i <= n; ++i)
    D[i][0] = i;

  for (int j = 0; j <= m; ++j)
    D[0][j] = j;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      D[i][j] = std::min(std::min(D[i - 1][j] + 1,
                                  D[i][j - 1] + 1),
                         D[i - 1][j - 1] + (s[i - 1] != t[j - 1]));

      if (i == j) {
        if (s[i - 1] == t[j - 1])
          E += 'M';
        else if (D[i][j] == D[i - 1][j - 1] + 1)
          E += 'S';
        else if (D[i][j] == D[i][j - 1] + 1)
          E += 'D';
        else
          E += 'A';
      }
    }
  }

  int i = n - m;
  int j = m - n;
  while (i-- > 0)
    E += 'D';
  while (j-- > 0)
    E += 'A';

  return ED {D[n][m], E};
}

int main() {
  string s = "algorithm";
  string t = "logarithm";

  cout << "Input strings: " << s << ", " << t << "\n";

  if (s == "" && t == "") {
    cout << "Edit distance: 0\n";
    return 0;
  }

  if (s == "") {
    cout << "Edit distance: " << t.length() << "\n";
    return 0;
  }

  if (t == "") {
    cout << "Edit distance: " << s.length() << "\n";
    return 0;
  }

  ED ed = editDistance(s, t);
  cout << "Edit distance: " << ed.D << "\n";
  cout << "Edit sequence: " << ed.E << "\n";
}
