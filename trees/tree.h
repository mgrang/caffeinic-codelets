#include<algorithm>
#include<iostream>
#include<deque>
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
  static void insertNonBST(Tree *T, int V);
  static void inorder(Tree *T);
  static void preorder(Tree *T);
  static void postorder(Tree *T);
  static int countNodes(Tree *T);
  static int height(Tree *T);
  static bool isEmpty(Tree *T);
  static int getRoot(Tree *T);
  static bool search(Tree *T, int k);
  static bool isSame(Tree *T1, Tree *T2);
  static int getMin(Tree *T);
  static int getMax(Tree *T);
  static void display(Tree *T);
  static void print(Tree *T);

private:
  static void destroy(Tree *T);
  static Tree* getRootHelper(Tree *T);
  static void printHelper(std::deque<Tree *> &Q, int count, int limit);
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

void Tree::insertNonBST(Tree *T, int V) {
  if (isEmpty(T)) {
    T->val = V;
    T->parent = nullptr;
    return;
  }

  if (!T->left)
    T->left = new Tree(V, T);
  else if (!T->right)
    T->right = new Tree(V, T);
  else {
    if (V % 2 == 0)
      insert(T->left, V);
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

bool Tree::isSame(Tree *T1, Tree *T2) {
  if (!T1 && !T2)
    return true;
  if (!T1 || !T2)
    return false;
  if (isEmpty(T1) && isEmpty(T2))
    return true;
  if (isEmpty(T1) || isEmpty(T2))
    return false;
  return T1->val == T2->val &&
         isSame(T1->left, T2->left) &&
         isSame(T1->right, T2->right);
}

int Tree::getMin(Tree *T) {
  if (!T || isEmpty(T))
    return -1;
  while (T->left)
    T = T->left;
  return T->val;
}

int Tree::getMax(Tree *T) {
  if (!T || isEmpty(T))
    return -1;
  while (T->right)
    T = T->right;
  return T->val;
}

void Tree::display(Tree *T) {
  if (!T || isEmpty(T))
    return;

  cout << T->val << " ";
}

void Tree::printHelper(std::deque<Tree *> &Q, int count = 1, int limit = 1) {
  if (Q.size() == 0)
    return;

  Tree *T = Q.front();
  Q.pop_front();

  if (count == limit) {
    cout << "\n";
    count = 0;
    limit *= 2;
  }

  if (T) {
    display(T);
    Q.push_back(T->left);
    Q.push_back(T->right);
  } else cout << " ";

  printHelper(Q, count + 1, limit);
}

void Tree::print(Tree *T) {
  if (!T || isEmpty(T))
    return;

  display(T);

  std::deque<Tree *> Q;
  Q.push_back(T->left);
  Q.push_back(T->right);
  printHelper(Q);

  cout << "\n";
}
