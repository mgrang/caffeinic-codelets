#include <iostream>
#include <vector>
using namespace std;

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' ||
         c == 'o' || c == 'u';
}

string reverseVowels(string s) {
  if (s.length() <= 1)
    return s;

  int i = 0;
  int j = s.length() - 1;

  while (i < j) {
    while (i < j && !isVowel(s[i]))
      ++i;

    while (i < j && !isVowel(s[j]))
      --j;

    if (i < j) {
      auto tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }

    ++i;
    --j;
  }
  return s;
}

void test(string s) {
  cout << "str: " << s << ", rev vowels: " << reverseVowels(s) << "\n";
}

int main() {
  test("hello");
  test("leetcode");
  test("");
  test("rhythm");
  test("aeiou");
  test("a");
  test("ae");
  test("aei");
  test("aeiouyaeiou");
}
