#include<algorithm>
#include<iostream>
#include<deque>
#include<unordered_set>

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
  static bool isLeafNode(Tree *T);
  static std::pair<bool, vector<int>> hasPathSum(Tree *T, int k);
  static bool isBST(Tree *T);
  static void iterInOrder(Tree *T);
  static void iterPreOrder(Tree *T);
  static void iterPostOrder(Tree *T);

  static void display(Tree *T);
  static void print(Tree *T);

private:
  static void destroy(Tree *T);
  static Tree* getRootHelper(Tree *T);
  static void printHelper(std::deque<Tree *> &Q, int count, int limit);
  static std::pair<bool, vector<int>> getPathSum(Tree *T, int k, vector<int> &nums);
  static bool isBSTHelper(Tree *T, int min, int max);
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

void Tree::iterInOrder(Tree *T) {
  if (!T || isEmpty(T))
    return;

  unordered_set<Tree *> visited;
  vector<Tree *> V;
  V.push_back(T);

  while (V.size()) {
    if (isLeafNode(T) ||
       (!T->left || visited.count(T->left))) {
      display(T);
      visited.insert(T);

      if (V.back() == T)
        V.pop_back();

      if (!isLeafNode(T) && T->right) {
        T = T->right;
        V.push_back(T);
      }
      else if (V.size())
        T = V.back();
      continue;
    }

    if (V.back() != T)
      V.push_back(T);

    if (T->left)
      T = T->left;
    else if (T->right)
      T = T->right;
  }
}

void Tree::iterPreOrder(Tree *T) {
  if (!T || isEmpty(T))
    return;

  unordered_set<Tree *> visited;
  vector<Tree *> V;
  V.push_back(T);

  while (V.size()) {
    if (!visited.count(T)) {
      display(T);
      visited.insert(T);
    }

    if (isLeafNode(T) ||
       ((!T->left || visited.count(T->left)) &&
        (!T->right || visited.count(T->right)))) {
      V.pop_back();
      T = V.back();
      continue;
    }

    if (T->right)
      V.push_back(T->right);
    if (T->left)
      V.push_back(T->left);

    if (T->left)
      T = T->left;
    else if (T->right)
      T = T->right;
  }
}

void Tree::iterPostOrder(Tree *T) {
  if (!T || isEmpty(T))
    return;

  unordered_set<Tree *> visited;
  vector<Tree *> V;
  V.push_back(T);

  while (V.size()) {
    if (isLeafNode(T) ||
       ((!T->left || visited.count(T->left)) &&
        (!T->right || visited.count(T->right)))) {
      display(T);
      visited.insert(T);
      V.pop_back();
      T = V.back();
      continue;
    }

    if (T->right)
      V.push_back(T->right);
    if (T->left)
      V.push_back(T->left);

    if (T->left)
      T = T->left;
    else if (T->right)
      T = T->right;
  }
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

std::pair<bool, vector<int>>
Tree::getPathSum(Tree *T, int k, vector<int> &nums) {
  if (!T || isEmpty(T))
    return std::make_pair(false, nums);

  if (isLeafNode(T) && T->val == k) {
    nums.push_back(T->val);
    return std::make_pair(true, nums);
  }

  auto leftSum = getPathSum(T->left, k - T->val, nums);
  if (leftSum.first) {
    nums.push_back(T->val);
    return std::make_pair(true, nums);
  }

  auto rightSum = getPathSum(T->right, k - T->val, nums);
  if (rightSum.first) {
    nums.push_back(T->val);
    return std::make_pair(true, nums);
  }

  return std::make_pair(false, nums);
}

std::pair<bool, vector<int>>
Tree::hasPathSum(Tree *T, int k) {
  vector<int> nums;
  return getPathSum(T, k, nums);
}

bool Tree::isLeafNode(Tree *T) {
  return T && !T->left && !T->right;
}

bool Tree::isBSTHelper(Tree *T,
                       int min = std::numeric_limits<int>::min(),
                       int max = std::numeric_limits<int>::max()) {
  if (!T || isEmpty(T))
    return true;

  if (T->val < min || T->val > max)
    return false;

  return isBSTHelper(T->left, min, T->val) &&
         isBSTHelper(T->right, T->val, max);
}

bool Tree::isBST(Tree *T) {
  return isBSTHelper(T);
}
