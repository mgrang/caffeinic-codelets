#include <iostream>
#include <vector>
using namespace std;

void swap(string &s, int i, int j) {
  char tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
}

void permute(string &s, int left, int right) {
  if (left == right) {
    cout << s << " ";
    return;
  }

  for (int i = left; i <= right; ++i) {
    swap(s, left, i);
    permute(s, left + 1, right);
    swap(s, left, i);
  }
}

void test(string s) {
  cout << "Str: " << s << "\nPermutations: ";
  permute(s, 0, s.length() - 1);
  cout << "\n----------------------------------------\n";
}

int main() {
  test("");
  test("a");
  test("abc");
  test("abcdefghijklmnopqrstuvwxyz");
}
