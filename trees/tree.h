#include<iostream>
using namespace std;

class Tree {
private:
  int val;
  Tree *left;
  Tree *right;

public:
  static Tree *root;
  static int numNodes;

  Tree(int V, Tree *L = nullptr, Tree *R = nullptr) : val(V), left(L), right(R) {
    if (!numNodes)
      root = this;
    ++numNodes;
  };

  void insert(Tree *T, int V);

  static void inorder(Tree *T);
  static void preorder(Tree *T);
  static void postorder(Tree *T);

  static void display(int V) { cout << V << " "; }
};

int Tree::numNodes = 0;
Tree *Tree::root = nullptr;

void Tree::insert(Tree *T, int V) {
  if (!T) {
    T = new Tree(V);
    return;
  }

  if (V < T->val)
    insert(T->left, V);
  else
    insert(T->right, V);
}

void Tree::inorder(Tree *T) {
  if (!T)
    return;

  inorder(T->left);
  display(T->val);
  inorder(T->right);
}

void Tree::preorder(Tree *T) {
  if (!T)
    return;

  display(T->val);
  preorder(T->left);
  preorder(T->right);
}

void Tree::postorder(Tree *T) {
  if (!T)
    return;

  preorder(T->left);
  preorder(T->right);
  display(T->val);
}
