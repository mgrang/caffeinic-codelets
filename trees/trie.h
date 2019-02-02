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

    Node() : letters({}), isEnd(false) {}
  };

private:
  Node *root;

public:
  Trie() : root(new Node()) {}

  void insert(string word) {
    auto *node = root;
    for (int i = 0; i != word.length(); ++i) {
      auto w = word[i];

      if (!node->letters.count(w))
        node->letters.insert({w, new Node()});
      node = node->letters[w];

    }
    node->isEnd = true;
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

  void displayHelper(Node *node, string s = "") {
    if (!node)
      return;

    if (node->isEnd)
      cout << s << " ";

    for (const auto &pair : node->letters)
      displayHelper(pair.second, s + pair.first);
  }

  void display() {
    displayHelper(root);
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

    displayHelper(node, currWord);
  }

  void removeAll(Node *node) {
    if (!node)
      return;

    if (!node->letters.size()) {
      delete node;
      return;
    }

    for (auto &pair : node->letters) {
      auto *tmp = pair.second;
      delete node->letters[pair.first];
      removeAll(tmp);
    }
  }

  void removeHelper(Node *node, string word) {
    if (!node)
      return;

    for (const auto w : word) {
      if (!node->letters.count(w))
        return;
      auto *tmp = node->letters[w];
      node->letters.erase(w);
      if (!node->letters.size())
        delete node;
      node = tmp;
    }

    removeAll(node);
  }

  void remove(string word) {
    removeHelper(root, word);
  }
};
