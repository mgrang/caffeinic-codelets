#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void getCombinations(string s) {
  int n = pow(2, s.length());
  unordered_set<string> strSet;

  for (int i = 0; i < n; ++i) {
    int bits = i;
    int idx = s.length() - 1;
    string t;

    while (bits) {
      if (bits & 1)
        t += s[idx];

      bits = bits >> 1;
      --idx;
    }

    if (!strSet.count(t)) {
      strSet.insert(t);
      cout << "{" << t << "} ";
    }
  }
}

void test(string s) {
  cout << "Str: " << s << "\nPermutations: ";
  getCombinations(s);
  cout << "\n----------------------------------------\n";
}

int main() {
  test("");
  test("a");
  test("abc");
  test("aaa");
  test("abcd");
}
