#include <cmath>
#include <iostream>
using namespace std;

const unsigned PRIME = 101;

unsigned getHash(unsigned curr, unsigned power) {
  return curr * pow(PRIME, power);
}

unsigned getHash(unsigned hash, unsigned curr, unsigned power, unsigned first) {
  return (hash - first) / PRIME + getHash(curr, power);
}

int strStr(string haystack, string needle) {
  // Assume empty needle is not in the haystack.
  if (needle.length() == 0)
    return -1;

  // Needle has to be smaller than the haystack.
  if (needle.length() > haystack.length())
    return -1;
  
  unsigned needHash = 0;
  unsigned hayHash = 0;
  unsigned power = 0;
  int i = 0;

  // Calculate hashes for the needle and haystack[0:needle.length()].
  while (i < needle.length()) {
    needHash += getHash(needle[i], power);
    hayHash += getHash(haystack[i], power);
    ++power;
    ++i;
  }

  // We found the needle at index 0.
  if (hayHash == needHash)
    return 0;

  // Calculate rolling hash for the rest of the haystack.
  while (i < haystack.length()) {
    int firstIdx = i - needle.length();
    hayHash = getHash(hayHash, haystack[i], needle.length() - 1, haystack[firstIdx]);

    if (hayHash == needHash)
      return i - needle.length() + 1;

    ++i;
  }
  
  return -1;
}

void test(string s, string t) {
  cout << "Str: " << s << ", Pat: " << t << ", Found at idx: " << strStr(s, t) << "\n";
}

int main() {
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
