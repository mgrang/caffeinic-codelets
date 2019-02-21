#include <iostream>
using namespace std;

void lookAndSay(int k) {
  string s = "1";
  cout << s << "\n";

  while (--k) {
    char x = s[0];
    int i = 0;
    int count = 0;
    string res;

    while (true) {
      while (i < s.length() && s[i] == x) {
        ++i;
        ++count;
      }
      res += std::to_string(count) + x;

      if (i >= s.length())
        break;

      count = 1;
      x = s[i];
      ++i;
    }

    cout << res << "\n";
    s = res;
  }
}

void test(int k) {
  lookAndSay(k);
}

int main() {
  test(10);
}
