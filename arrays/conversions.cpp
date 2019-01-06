#include <algorithm>
#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

int convertToInt(string s) {
  int pow = 1;
  int res = 0;
  while (s.length()) {
    res += (s.back() - '0') * pow;
    s.pop_back();
    pow *= 10;
  }
  return res;
}

string convertToStr(int i) {
  string res;
  while (i) {
    res += (i % 10) + '0';
    i /= 10;
  }
  std::reverse(res.begin(), res.end());
  return res;
}

void test(string s, int i) {
  int res1 = convertToInt(s);
  cout << s << " to int is: " << res1 << "\n";

  string res2 = convertToStr(i);
  cout << i << " to str is: " << res2 << "\n";
}

int main() {
  test("123", 123);
}
