#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

void test(vector<int> Vals) {
  Tree *T = new Tree(Vals[0]);
  for (int i = 1; i < Vals.size(); ++i)
    Tree::insert(T, Vals[i]);

  cout << "Total nodes: " << Tree::numNodes << "\n";
  cout << "Root: ";
  Tree::display(Tree::root);
  cout << "\n";

  cout << "Inorder: ";
  Tree::inorder(Tree::root);
  cout << "\n";

  cout << "Preorder: ";
  Tree::preorder(Tree::root);
  cout << "\n";

  cout << "Postorder: ";
  Tree::postorder(Tree::root);
  cout << "\n";

  T->~Tree();
}

int main() {
  test({10, 15, 30, 3, 6, 5, 2, 9, 8});
}
