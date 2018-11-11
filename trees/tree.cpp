#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

void test(vector<int> Vals) {
  Tree *T = new Tree(Vals[0]);
  for (int i = 1; i < Vals.size(); ++i)
    Tree::insert(T, Vals[i]);

  cout << "Node count: " << Tree::countNodes(T) << "\n";
  cout << "Tree height: " << Tree::height(T) << "\n";

  cout << "Inorder: ";
  Tree::inorder(T);
  cout << "\n";

  cout << "Preorder: ";
  Tree::preorder(T);
  cout << "\n";

  cout << "Postorder: ";
  Tree::postorder(T);
  cout << "\n";

  cout << "---------------------------------------------\n";

//  T->~Tree();
}

int main() {
  test({10, 15, 30, 3, 6, 5, 2, 9, 8});
  test({50, 30, 25, 75, 82, 28, 63, 70, 4, 43, 74, 35});
  test({1});
}
