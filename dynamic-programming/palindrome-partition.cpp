#include <algorithm>
#include <iostream>
using namespace std;

int partition(string s) {
  bool T[s.length()][s.length()];

  int start = 0;
  int end = s.length();

  while (start < s.length()) {
    int i = 0;
    int j = start;

    while (i < end) {
      if (i == j)
        T[i][j] = true;
      else if (s[i] != s[j])
        T[i][j] = false;
      else {
        if (j - i == 1)
          T[i][j] = true;
        else
          T[i][j] = T[i + 1][j - 1];
      }
      ++i;
      ++j;
    }
    ++start;
    --end;
  }

  int count = 0;
  int i = 0;
  int j = s.length() - 1;

  while (i < s.length() && j >= 0) {
    while (T[i][j] == false)
      ++i;

    ++count;
    j = i - 1;
    i = 0;
  }

  return count - 1;
}

void test(string s) {
  cout << "Input: " << s << "\n";
  cout << "Min splits needed: " << partition(s) << "\n";
}

int main() {
  test("xzyzaybx");
  test("aibohphobia");
  test("banana");
  test("malayalam");
  test("abcdef");
  test("aaaaaaaa");
  test("abacadae");
  test("abcbm");
  test("abbcc");
  test("abba");
}
