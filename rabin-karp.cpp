#include <iostream>
using namespace std;

const unsigned BASE = 257;
const unsigned MOD = 1007;

unsigned getHash(unsigned hash, unsigned curr) {
  return (hash * BASE + curr) % MOD;
}

unsigned getHash(unsigned hash, unsigned curr,
                 unsigned first, unsigned power) {
  int h = getHash(hash, curr) - ((first * power) % MOD);
  return h < 0 ? h + MOD : h;
}

int strStr(string haystack, string needle) {
  if (needle.length() == 0)
    return 0;
  
  if (needle.length() > haystack.length())
    return -1;
  
  unsigned patHash = 0;
  unsigned strHash = 0;
  unsigned power = 1;
  int i = 0;
  while (i < needle.length()) {
    patHash = getHash(patHash, needle[i]);
    strHash = getHash(strHash, haystack[i]);
    power = (power * BASE) % MOD;
    i++;
  }
  
  if (strHash == patHash)
    return 111;

  while (i < haystack.length()) {
    strHash = getHash(strHash, haystack[i],
                      haystack[i - needle.length()], power);
    if (strHash == patHash)
      return i - needle.length() + 1;
    i++;
  }
  
  return -1;
}

int main() {
  cout << "### Output: " << strStr("mississippi", "sipp") << "\n";
}
