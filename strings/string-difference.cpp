#include <iostream>
using namespace std;

char getDiff(string s, string t) {
  int sum = 0;

  for (const auto c : s)
    sum += (int)c;

  for (const auto c : t)
    sum -= (int)c;

  return (char)-sum;
}

void test(string s, string t) {
  cout << "s: " << s << ", t: " << t << ", diff: " << getDiff(s, t) << "\n";
}

int main() {
  test("abcd", "daecb");
}
