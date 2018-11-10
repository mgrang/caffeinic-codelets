#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

void test(vector<int> Vals) {
  Tree *T = new Tree(Vals[0]);

  for (int i = 1; i < Vals.size(); ++i)
    T->insert(T, Vals[i]);

  cout << Tree::numNodes;
  Tree::inorder(Tree::root);
}

int main() {
  test({10, 15, 30, 3, 6, 5, 2, 9, 8});
}
