#include <iostream>
#include <vector>
#include "trie.h"
using namespace std;

void test(vector<string> words) {
  Trie T;

  for (auto &word: words)
    T.insert(word);

  cout << "Trie words: ";
  T.display();

  cout << "hasPrefix(a): " << T.hasPrefix("a") << "\n";
  cout << "hasPrefix(abc): " << T.hasPrefix("abc") << "\n";
  cout << "hasPrefix(ab): " << T.hasPrefix("ab") << "\n";
  cout << "hasPrefix(abcde): " << T.hasPrefix("abcde") << "\n";
  cout << "hasPrefix(lmno): " << T.hasPrefix("lmno") << "\n";
  cout << "hasPrefix(xy): " << T.hasPrefix("xy") << "\n";

  cout << "hasWord(a): " << T.hasWord("a") << "\n";
  cout << "hasWord(abc): " << T.hasWord("abc") << "\n";
  cout << "hasWord(ab): " << T.hasWord("ab") << "\n";
  cout << "hasWord(abcde): " << T.hasWord("abcde") << "\n";
  cout << "hasWord(lmno): " << T.hasWord("lmno") << "\n";
  cout << "hasWord(xy): " << T.hasWord("xy") << "\n";
  cout << "hasWord(abd): " << T.hasWord("abd") << "\n";

  cout << "remove(abd)\n";
  T.remove("abd");
  cout << "remove(ab)\n";
  T.remove("ab");
  cout << "hasWord(a): " << T.hasWord("a") << "\n";
  cout << "hasWord(abc): " << T.hasWord("abc") << "\n";
  cout << "hasWord(ab): " << T.hasWord("ab") << "\n";
  cout << "hasWord(abcde): " << T.hasWord("abcde") << "\n";
  cout << "hasWord(lmno): " << T.hasWord("lmno") << "\n";
  cout << "hasWord(xy): " << T.hasWord("xy") << "\n";
  cout << "hasWord(abd): " << T.hasWord("abd") << "\n";

  cout << "\nWords with prefix a: ";
  T.showAllWords("a");
  cout << "\nWords with prefix ab: ";
  T.showAllWords("ab");
  cout << "\nWords with prefix xyz: ";
  T.showAllWords("xyz");
  cout << "\nWords with prefix abx: ";
  T.showAllWords("abx");
  cout << "\nWords with prefix abcde: ";
  T.showAllWords("abcde");
  cout << "\nWords with prefix z: ";
  T.showAllWords("z");
  cout << "\nWords with prefix (empty string): ";
  T.showAllWords("");
  cout << "\n";
}

int main() {
  test({"xyz", "abc", "abd", "abcd", "a", "ab", "bcd"});
}
