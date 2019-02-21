#include <iostream>
#include <vector>
using namespace std;

bool isEditDistanceOne(string s, string t) {
  if (s == t)
    return false;

  if (t.length() > s.length()) {
    auto tmp = s;
    s = t;
    t = tmp;
  }

  int n = s.length();
  int m = t.length();

  if ((n - m) > 1)
    return false;

  int i = 0;
  while (i < m && s[i] == t[i])
    ++i;

  if (i == n)
    return false;

  ++i;
  int j = n == m ? i : i - 1;

  while (i < n && j < m && s[i] == t[j]) {
    ++i;
    ++j;
  }

  return i == n && j == m;
}

void test(string s, string t) {
  cout << "isOneEdit(" << s << ", " << t << "): " << isEditDistanceOne(s, t) << "\n";
}

int main() {
  test("abcd", "abc");
  test("abcd", "abcd");
  test("abcd", "abcde");
  test("abcd", "abxd");
  test("abcd", "fbxd");
  test("", "fbxd");
  test("", "a");
  test("", " ");
}
