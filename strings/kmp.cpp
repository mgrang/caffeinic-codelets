#include <cmath>
#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {
  // Assume empty needle is not in the haystack.
  if (needle.length() == 0)
    return -1;

  // Needle has to be smaller than the haystack.
  if (needle.length() > haystack.length())
    return -1;

  int match[needle.length()];
  int i = 1;
  int j = 0;
  match[0] = 0;

  while (i < needle.length()) {
    if (needle[i] != needle[j])
      j = 0;

    if (needle[i] == needle[j]) {
      match[i] = j + 1;
      ++j;
    } else
      match[i] = 0;

    ++i;
  }

  int h = haystack.length();
  int n = needle.length();
  i = 0;
  j = 0;

  while (i < h) {
    while (i < h && j < n && needle[j] == haystack[i]) {
      ++i;
      ++j;
    }

    if (j == n)
      return i - n;

    while (j > 0) {
      if (j == match[j])
        j = 0;
      else j = match[j];

      if (needle[match[j]] == haystack[i])
        break;
    }

    if (needle[j] == haystack[i])
      ++j;

    ++i;
  }

  return -1;
}

void test(string s, string t) {
  cout << "Str: " << s << ", Pat: " << t << ", Found at idx: " << strStr(s, t) << "\n";
}

int main() {
  test("aaabaaaa", "aaaa");
  test("mississippi", "sipp");
  test("mississippi", "misS");
  test("mississippi", "mis");
  test("mississippi", "iss");
  test("mississippi", "pi");
  test("mississippi", "mississippi");
  test("m", "mississippi");
  test("m", "m");
  test("m", "");
  test("", "");
}
