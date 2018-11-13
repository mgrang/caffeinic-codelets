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
  cout << "Min Val: " << Tree::getMin(T) << "\n";
  cout << "Max Val: " << Tree::getMax(T) << "\n";

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

void check(vector<int> Vals1, vector<int> Vals2) {
  Tree *T1 = new Tree();
  for (auto v : Vals1)
    Tree::insert(T1, v);

  Tree *T2 = new Tree();
  for (auto v : Vals2)
    Tree::insert(T2, v);

  cout << "Inorder DFS T1: ";
  Tree::inorder(T1);
  cout << "\n";

  cout << "Inorder DFS T2: ";
  Tree::inorder(T2);
  cout << "\n";

  if (Tree::isSame(T1, T2))
    cout << "Trees are same";
  else
    cout << "Trees are different";
  cout << "\n";
  cout << "---------------------------------------------\n";
}

void nonBST(vector<int> Vals) {
  Tree *T = new Tree();
  for (auto v : Vals)
    Tree::insert(T, v);

  cout << "Inorder DFS non-BST: ";
  Tree::inorder(T);
  cout << "\n";
  cout << "---------------------------------------------\n";
}

int main() {
  test({10, 15, 30, 3, 6, 5, 2, 9, 8}, {3, 8, 10, -1, -2});
  test({50, 30, 25, 75, 82, 28, 63, 70, 4, 43, 74, 35}, {82, 50, 35, -1, -2});
  test({1}, {1, 0, -1});
  test({}, {1, 0, -1});

  check({1, 2, 3, 4}, {1, 2, 3, 4});
  check({2, 1, 3}, {2, 1, 4});
  check({2, 1, 3, 4}, {2, 1, 4});
  check({}, {});

  nonBST({10, 15, 30, 3, 6, 5, 2, 9, 8});
  nonBST({50, 30, 25, 75, 82, 28, 63, 70, 4, 43, 74, 35});
}
