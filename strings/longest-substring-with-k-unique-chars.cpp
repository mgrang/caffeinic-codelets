#include <deque>
#include <iostream>
#include <unordered_map>
using namespace std;

string getSubstr(string s, int k) {
  if (k == 0)
    return s;

  int maxLen = 1, maxIdx = 0, lastChange = -1, currLen = 1;

  unordered_map<char, bool> Map;
  Map[s[0]] = true;

  std::deque<char> Q;
  Q.push_back(s[0]);

  for (int i = 1; i < s.length(); ++i) {
    char c = s[i];

    if (c == s[i - 1]) {
      ++currLen;
      if (currLen > maxLen) {
        maxLen = currLen;
        maxIdx = i;
      }
      continue;
    }

    if (Map.count(c) && Map[c]) {
      ++currLen;
      if (currLen > maxLen) {
        maxLen = currLen;
        maxIdx = i;
      }
      lastChange = i;
      continue;
    }

    if (Q.size() < k) {
      Map[c] = true;
      Q.push_back(c);

      ++currLen;
      if (currLen > maxLen) {
        maxLen = currLen;
        maxIdx = i;
      }
      lastChange = i;
      continue;
    }

    Map[Q.front()] = false;
    Q.pop_front();

    Map[c] = true;
    Q.push_back(c);

    if (lastChange == -1)
      lastChange = i;

    currLen = currLen - lastChange + 1;
    if (currLen > maxLen) {
      maxLen = currLen;
      maxIdx = i;
    }
    lastChange = i;
  }

  if (k > Map.size())
    return "-";
  return s.substr(maxIdx - maxLen + 1, maxLen);
}

void test(string s, int k) {
  cout << "s: " << s << ", k: " << k << ", substr: " << getSubstr(s, k) << "\n";
}

int main() {
  test("aabbbcbbcbbaba", 0);
  test("aabbbcbbcbbaba", 1);
  test("aabbbcbbcbbaba", 2);
  test("aabbbcbbcbbaba", 3);
  test("aabbbcbbcbbaba", 4);
}
