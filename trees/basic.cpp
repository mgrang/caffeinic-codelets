#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

void test(vector<int> Vals, vector<int> Find) {
  Tree *T = new Tree();
  for (auto v : Vals)
    Tree::insert(T, v);

  cout << "Node count: " << Tree::countNodes(T) << "\n";
  cout << "Tree height: " << Tree::height(T) << "\n";
  cout << "Root: " << Tree::getRoot(T) << "\n";

  cout << "Inorder DFS: ";
  Tree::inorder(T);
  cout << "\n";

  cout << "Preorder DFS: ";
  Tree::preorder(T);
  cout << "\n";

  cout << "Postorder DFS: ";
  Tree::postorder(T);
  cout << "\n";

  for (auto i : Find) {
    if (Tree::search(T, i))
      cout << "Key found: " << i;
    else
      cout << "Key not found: " << i;
    cout << "\n";
  }

  cout << "---------------------------------------------\n";

//  T->~Tree();
}

int main() {
  test({10, 15, 30, 3, 6, 5, 2, 9, 8}, {3, 8, 10, -1, -2});
  test({50, 30, 25, 75, 82, 28, 63, 70, 4, 43, 74, 35}, {82, 50, 35, -1, -2});
  test({1}, {1, 0, -1});
  test({}, {1, 0, -1});
}
