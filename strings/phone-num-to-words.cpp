#include <fstream>
#include <iostream>
#include <unordered_set>
using namespace std;

class Dict {
private:
  unordered_set<string> words;

public:
  Dict() {
    std::ifstream input ("/usr/share/dict/words");

    for (string line; getline(input, line);) {
      words.insert(line);
    }
  }

  bool isWord(string word) {
    return words.count(word);
  }
};

string phone[] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwy", "xz"};
Dict D;

void getWords(string num, int numLen, string s = "", int k = 0) {
  if (k == numLen) {
    if (D.isWord(s))
      cout << s << " ";
    return;
  }

  int idx = num[k] - '0';
  for (char c : phone[idx])
    getWords(num, numLen, s + c, k + 1);
}

void test(string num) {
  cout << "Num: " << num << "\n";
  cout << "Words: ";
  getWords(num, num.length());
  cout << "\n-------------------------------------------------------------\n";
}

int main() {
  test("012");
  test("6104");
  test("000");
  test("1261061");
  test("616");
}
