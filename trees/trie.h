#include <iostream>
#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
  class Node {
  public:
    unordered_map<char, Node *> letters;
    bool isEnd;

    Node(bool e = false) : letters({}), isEnd(e) {}
  };

private:
  Node *root;

public:
  Trie() : root(new Node()) {}

  void insert(string word) {
    auto *node = root;
    for (int i = 0; i != word.length(); ++i) {
      auto w = word[i];
      auto e = i == word.length() - 1;

      if (!node->letters.count(w))
        node->letters.insert({w, new Node(e)});
      node = node->letters[w];

      if (e)
        node->isEnd = true;
    }
  }

  bool hasPrefix(string word) {
    auto *node = root;
    for (auto w : word) {
      if (!node->letters.count(w))
        return false;
      node = node->letters[w];
    }
    return true;
  }

  bool hasWord(string word) {
    auto *node = root;
    for (auto w : word) {
      if (!node->letters.count(w))
        return false;
      node = node->letters[w];
    }
    return node->isEnd;
  }

  void removeHelper(Node *node, string word, int idx = 0) {
    if (idx == word.length()) {
      if (!node->letters.size())
        delete node;
      else node->isEnd = false;
      return;
    }

    auto w = word[idx];
    removeHelper(node->letters[w], word, ++idx);
    if (!node)
      return;
    if (!node->letters[w]->letters.size()) {
      if (!node->letters.size())
        delete node;
      else node->letters.erase(w);
    }
  }

  void remove(string word) {
    if (!hasWord(word))
      return;

    removeHelper(root, word);
  }

  void displayHelper(Node *node, char word[], int idx = 0) {
    if (node->isEnd) {
      word[idx] = '\0';
      cout << word << " ";
    }

    for (auto &pair : node->letters) {
      word[idx] = pair.first;
      displayHelper(pair.second, word, idx + 1);
    }
  }

  void display() {
    char word[20];
    displayHelper(root, word);
    cout << "\n";
  }

  void showAllWords(string prefix) {
    if (!prefix.length())
      return;

    string currWord;
    auto *node = root;

    for (auto w : prefix) {
      if (!node->letters.count(w))
        return;
      currWord += w;
      node = node->letters[w];
    }

    char word[20];
    for (int i = 0; i < currWord.length(); ++i)
      word[i] = currWord[i];

    displayHelper(node, word, currWord.length());
  }
};
