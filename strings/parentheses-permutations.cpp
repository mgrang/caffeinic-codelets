#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> getPermutations(int n) {
  if (n == 0)
    return {""};

  if (n == 1)
    return {"()"};

  vector<string> prev = {"()"};
  vector<string> res;

  for (int i = 2; i < n + 1; ++i) {
    unordered_set<string> Set;

    for (const auto &s : prev) {
      for (int j = 0; j < s.length(); ++j) {
        string cur;
        for (int k = 0; k < s.length(); ++k) {
          if (j == k)
            cur += "()";
          cur += s[k];
        }
        Set.insert(cur);
      }
    }

    for (const auto &s : Set)
      res.push_back(s);
    prev = res;
  }
  return res;
}

void test(int n) {
  cout << "n = " << n << " : ";
  const auto res = getPermutations(n);
  for (const auto &s : res)
    cout << s << " ";
  cout << "\n--------------------------------------------\n";
}

int main() {
  test(0);
  test(1);
  test(2);
  test(3);
  test(4);
  test(5);
}
