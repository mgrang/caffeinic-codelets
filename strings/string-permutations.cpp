#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void swap(string &s, int i, int j) {
  char tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
}

void permute(string &s, int left, int right, unordered_set<string> &strSet) {
  if (left == right && !strSet.count(s)) {
    strSet.insert(s);
    cout << s << " ";
    return;
  }

  for (int i = left; i <= right; ++i) {
    swap(s, left, i);
    permute(s, left + 1, right, strSet);
    swap(s, left, i);
  }
}

void test(string s) {
  unordered_set<string> strSet;
  cout << "Str: " << s << "\nPermutations: ";
  permute(s, 0, s.length() - 1, strSet);
  cout << "\n----------------------------------------\n";
}

int main() {
  test("");
  test("a");
  test("abc");
  test("aaa");
  test("abcd");
}
