#include<algorithm>
#include<iostream>
#include<set>

using namespace std;

class Tree {
  int val;
  Tree *left, *right, *parent;

  Tree(int v, Tree *p) : val(v), parent(p), left(nullptr), right(nullptr) {}

public:
  Tree() : val(-1), parent(this), left(nullptr), right(nullptr) {}
  Tree(const Tree &);

  ~Tree() { destroy(this); }

  static void insert(Tree *T, int V);
  static void inorder(Tree *T);
  static void preorder(Tree *T);
  static void postorder(Tree *T);
  static int countNodes(Tree *T);
  static int height(Tree *T);
  static bool isEmpty(Tree *T);
  static int getRoot(Tree *T);
  static bool search(Tree *T, int k);

  static void display(Tree *T) { cout << T->val << " "; }

private:
  static void destroy(Tree *T);
  static Tree* getRootHelper(Tree *T);
};

void Tree::destroy(Tree *T) {
  if (T) {
    destroy(T->left);
    destroy(T->right);
    delete T;
  }
}

bool Tree::isEmpty(Tree *T) {
  return T->parent == T;
}

void Tree::insert(Tree *T, int V) {
  if (isEmpty(T)) {
    T->val = V;
    T->parent = nullptr;
    return;
  }

  if (V < T->val) {
    if (!T->left)
      T->left = new Tree(V, T);
    else
      insert(T->left, V);
  }
  else {
    if (!T->right)
      T->right = new Tree(V, T);
    else
      insert(T->right, V);
  }
}

void Tree::inorder(Tree *T) {
  if (!T)
    return;

  inorder(T->left);
  display(T);
  inorder(T->right);
}

void Tree::preorder(Tree *T) {
  if (!T)
    return;

  display(T);
  preorder(T->left);
  preorder(T->right);
}

void Tree::postorder(Tree *T) {
  if (!T)
    return;

  postorder(T->left);
  postorder(T->right);
  display(T);
}

int Tree::countNodes(Tree *T) {
  if (!T || isEmpty(T))
    return 0;
  return 1 + countNodes(T->left) + countNodes(T->right);
}

int Tree::height(Tree *T) {
  if (!T || isEmpty(T))
    return 0;
  return 1 + std::max(height(T->left), height(T->right));
}

Tree *Tree::getRootHelper(Tree *T) {
  if (!T || isEmpty(T) || !T->parent)
    return T;
  return getRootHelper(T->parent);
}

int Tree::getRoot(Tree * T) {
  return getRootHelper(T)->val;
}

bool Tree::search(Tree *T, int k) {
  if (!T || isEmpty(T))
    return false;
  if (T->val == k)
    return true;
  if (T->val < k)
    return search(T->right, k);
  return search(T->left, k);
}
