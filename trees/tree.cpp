#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

void test1(vector<int> Vals, vector<int> Find, int k) {
  Tree *T = new Tree();
  for (auto v : Vals)
    Tree::insert(T, v);

  Tree::print(T);
  cout << "Node count: " << Tree::countNodes(T) << "\n";
  cout << "Tree height: " << Tree::height(T) << "\n";
  cout << "Root: " << Tree::getRoot(T) << "\n";
  cout << "Min Val: " << Tree::getMin(T) << "\n";
  cout << "Max Val: " << Tree::getMax(T) << "\n";
  cout << "Is BST: " << Tree::isBST(T) << "\n";

  auto res = Tree::hasPathSum(T, k);
  if (res.first) {
    cout << "Sum " << k << " found. Path: ";
    auto nums = res.second;
    while (nums.size()) {
      cout << nums.back() << " ";
      nums.pop_back();
    }
    cout << "\n";
  } else
    cout << "Sum " << k << " not found\n";

  cout << "Inorder DFS: ";
  Tree::inorder(T);
  cout << "\n";

  cout << "Iterative Inorder DFS: ";
  Tree::iterInOrder(T);
  cout << "\n";

  cout << "Preorder DFS: ";
  Tree::preorder(T);
  cout << "\n";

  cout << "Iterative Preorder DFS: ";
  Tree::iterPreOrder(T);
  cout << "\n";

  cout << "Postorder DFS: ";
  Tree::postorder(T);
  cout << "\n";

  cout << "Iterative Postorder DFS: ";
  Tree::iterPostOrder(T);
  cout << "\n";

  cout << "Reverse Level Order Print: ";
  Tree::reversePrint(T);
  cout << "\n";

  cout << "Spiral Level Order Print: ";
  Tree::spiralPrint(T);
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

void test2(vector<int> Vals1, vector<int> Vals2) {
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

void test3(vector<int> Vals, int a, int b) {
  Tree *T = new Tree();
  for (auto v : Vals)
    Tree::insert(T, v);

  Tree::print(T);
  cout << "LCA(" << a << ", " << b << "): ";
  Tree::display(Tree::lowestCommonAncestor(T, a, b));
  cout << "\n";
}

void nonBST(vector<int> Vals, int a, int b) {
  Tree *T = new Tree();
  for (auto v : Vals)
    Tree::insert(T, v);

  Tree::print(T);
  cout << "LCA(" << a << ", " << b << "): ";
  Tree::display(Tree::lowestCommonAncestorNonBST(T, a, b));
  cout << "\n";
  cout << "Is BST: " << Tree::isBST(T) << "\n";

  cout << "Inorder DFS non-BST: ";
  Tree::inorder(T);
  cout << "\n";
  cout << "---------------------------------------------\n";
}

int main() {
  test1({10, 15, 30, 3, 6, 5, 2, 9, 8}, {3, 8, 10, -1, -2}, 36);
  test1({50, 30, 25, 75, 82, 28, 63, 70, 4, 43, 74, 35}, {82, 50, 35, -1, -2}, 207);
  test1({1}, {1, 0, -1}, 1);
  test1({}, {1, 0, -1}, 1);

  test2({1, 2, 3, 4}, {1, 2, 3, 4});
  test2({2, 1, 3}, {2, 1, 4});
  test2({2, 1, 3, 4}, {2, 1, 4});
  test2({}, {});

  test3({50, 30, 25, 75, 82, 28, 63, 70, 4, 43, 74, 35}, 74, 82);
  test3({50, 30, 25, 75, 82, 28, 63, 70, 4, 43, 74, 35}, 4, 28);

  nonBST({10, 15, 30, 3, 6, 5, 2, 9, 8}, 9, 8);
  nonBST({50, 30, 25, 75, 82, 28, 63, 70, 4, 43, 74, 35}, 30, 4);
  nonBST({3, 4, 5}, 3, 5);
}
