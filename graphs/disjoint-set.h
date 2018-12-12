#include <map>
using namespace std;

class DisjointSet {
private:
  class Node {
  public:
    int data;
    int rank;
    Node *parent;

    Node(int d) : data(d), rank(0), parent(this) {}
  };

  map<int, Node *> nodeMap;

public:
  ~DisjointSet() {
    for (auto &pair : nodeMap)
      if (pair.second)
        delete pair.second;
  }

  void makeSet(int data) {
    nodeMap[data] = new Node(data);
  }

  void unionSet(int x, int y) {
    Node *X = nodeMap[x]->parent;
    Node *Y = nodeMap[y]->parent;

    Node *oldNode, *newNode;
    if (Y->rank > X->rank) {
      X->parent = Y;
      Y->rank = std::max(Y->rank, X->rank + 1);

      oldNode = X;
      newNode = Y;
    } else {
      Y->parent = X;
      X->rank = std::max(X->rank, Y->rank + 1);

      oldNode = Y;
      newNode = X;
    }

    for (auto &pair : nodeMap)
      if (pair.second->parent == oldNode)
        pair.second->parent = newNode;
  }

  int find(int x) {
    return nodeMap[x]->parent->data;
  }
};
