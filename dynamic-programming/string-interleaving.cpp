#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool checkInterleave(string s, string t, string u) {
  bool P[s.length() + 1][t.length() + 1];
  P[0][0] = true;

  for (int i = 1; i <= s.length(); ++i) {
    if (u[i - 1] == s[i - 1])
      P[i][0] = P[i - 1][0];
    else
      P[i][0] = false;
  }

  for (int j = 1; j <= t.length(); ++j) {
    if (u[j - 1] == t[j - 1])
      P[0][j] = P[0][j - 1];
    else
      P[0][j] = false;
  }

  for (int i = 1; i <= s.length(); ++i) {
    for (int j = 1; j <= t.length(); ++j) {
      if (u[i + j - 1] == s[i - 1])
        P[i][j] = P[i - 1][j];
      else if (u[i + j - 1] == t[j - 1])
        P[i][j] = P[i][j - 1];
      else
        P[i][j] = false;
    }
  }

  return P[s.length()][t.length()];
}

void test(string s, string t, string u) {
  cout << "Input: " << s << ", " << t << ", " << u
       << "\nOutput: "
       << (checkInterleave(s, t, u) ?
          "TRUE\n" : "FALSE\n");
}

int main() {
  test("aab", "axy", "aaxaby");
  test("aab", "axy", "abaaxy");
  test("XXY", "XXZ", "XXZXXXY"); 
  test("XY" ,"WZ" ,"WZXY"); 
  test ("XY", "X", "XXY"); 
  test ("YX", "X", "XXY"); 
  test ("XXY", "XXZ", "XXXXZY"); 
}
