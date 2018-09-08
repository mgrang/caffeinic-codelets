// Manacher's algorithm.

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string normalize(string s) {
  string t = "#";
  for (auto c : s)
    t += c + string("#");
  return t;
}

std::pair<int, string> lps(string s) {
  string t = normalize(s);
  int P[t.length()];
  P[0] = P[t.length() - 1] = 0;

  int maxLen = std::numeric_limits<int>::min();
  string maxStr;

  int i = 1;
  while (i < t.length()) {
    int currLen = 0;

    int left = i;
    int right = i;

    string currStr;
    if (t[i] != '#')
      currStr = t[i];

    while (left > 0 && right < t.length() && t[--left] == t[++right]) {
      ++currLen;
      if (t[left] != '#') {
        currStr.insert(currStr.begin(), t[left]);
        currStr += t[right];
      }
    }

    P[i] = currLen;

    if (currLen > maxLen) {
      maxLen = currLen;
      maxStr = currStr;
    }
  
    if (currLen < 2) {
      ++i;
      continue;
    }

    left = i - 1;
    right = i + 1;
    int rightEdge = i + currLen;

    while (right <= rightEdge) {
      int diff =  rightEdge - right;

      if (P[left] == diff)
        break;

      P[right] =  (P[left] < diff) ? P[left] : diff;

      --left;
      ++right;     
    }

    i = right;
  }

  return std::make_pair(maxLen, maxStr);;
}

int main() {
  string s = "aibohphobia";
  cout << "Input: " << s << "\n";

  std::pair<int, string> res = std::make_pair(0, "");
  if (s.length())
    res = lps(s);

  cout << "LPS len: " << res.first << "\n";
  cout << "LPS str: " << res.second << "\n";
}
