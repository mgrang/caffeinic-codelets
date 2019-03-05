#include<algorithm>
#include<iostream>
#include<deque>
#include<unordered_set>

using namespace std;

typedef struct {
  bool isBST;
  int size;
  int min;
  int max;
} BST;

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
  static void insertAVL(Tree *T, int V);
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
  static Tree *lowestCommonAncestor(Tree *T, int a, int b);
  static Tree *lowestCommonAncestorNonBST(Tree *T, int a, int b);
  static BST getLargestBST(Tree *T);
  static int inorderPred(Tree *T);
  static int inorderSucc(Tree *T);

  static void display(Tree *T);
  static void print(Tree *T);
  static void reversePrint(Tree *T);
  static void spiralPrint(Tree *T);
  static void levelOrderPrint(Tree *T);

private:
  static void destroy(Tree *T);
  static Tree* getRootHelper(Tree *T);
  static void printHelper(std::deque<Tree *> &Q, int count, int limit);
  static void reversePrintHelper(vector<Tree *> &V, int idx);
  static bool getPathSum(Tree *T, int k, vector<int> &nums);
  static bool isBSTHelper(Tree *T, int min, int max);
  static void levelOrderPrint(std::deque<Tree *> Q);
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

  vector<Tree *> V;
  V.push_back(T);

  while (V.size()) {
    if (!T) {
      T = V.back();
      V.pop_back();
      if (T) {
        display(T);
        T = T->right;
        V.push_back(T);
      }
    } else {
      T = T->left;
      V.push_back(T);
    }
  }
}

void Tree::iterPreOrder(Tree *T) {
  if (!T || isEmpty(T))
    return;

  vector<Tree *> V;
  V.push_back(T);

  while (V.size()) {
    if (!T) {
      T = V.back();
      V.pop_back();
      if (T) {
        display(T);
        V.push_back(T->right);
        T = T->left;
      }
    } else {
      display(T);
      if (T && V.back() == T)
        V.pop_back();
      V.push_back(T->right);
      T = T->left;
    }
  }
}

void Tree::iterPostOrder(Tree *T) {
  if (!T || isEmpty(T))
    return;

  vector<Tree *> V;
  V.push_back(T);

  Tree *prev = T;

  while (V.size()) {
    Tree *T = V.back();

    if (isLeafNode(T) || T->right == prev ||
       (!T->right && T->left == prev)) {
      display(T);
      prev = T;
      V.pop_back();
      continue;
    }

    if (T->right && T->left == prev)
      V.push_back(T->right);
    else if (T->left)
      V.push_back(T->left);
    else if (T->right)
      V.push_back(T->right);
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

bool Tree::getPathSum(Tree *T, int k, vector<int> &nums) {
  if (!T || isEmpty(T))
    return false;

  if (isLeafNode(T) && T->val == k) {
    nums.push_back(T->val);
    return true;
  }

  if (getPathSum(T->left, k - T->val, nums)) {
    nums.push_back(T->val);
    return true;
  }

  if (getPathSum(T->right, k - T->val, nums)) {
    nums.push_back(T->val);
    return true;
  }

  return false;
}

std::pair<bool, vector<int>>
Tree::hasPathSum(Tree *T, int k) {
  vector<int> nums;
  bool res = getPathSum(T, k, nums);
  return std::make_pair(res, nums);
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

void Tree::reversePrintHelper(vector<Tree *> &V, int idx = 0) {
  if (idx >= V.size())
    return;

  Tree *T = V[idx];
  if (T->left)
    V.push_back(T->left);

  if (T->right)
    V.push_back(T->right);

  reversePrintHelper(V, ++idx);
}

void Tree::reversePrint(Tree *T) {
  if (!T || isEmpty(T))
    return;

  vector<Tree *> V;
  V.push_back(T);
  reversePrintHelper(V);

  while (V.size()) {
    display(V.back());
    V.pop_back();
  }
}

void Tree::spiralPrint(Tree *T) {
  if (!T || isEmpty(T))
    return;

  vector<Tree *> V1;
  vector<Tree *> V2;
  bool flag = true;

  V1.push_back(T);

  while (V1.size() || V2.size()) {
    if (flag) {
      flag = false;
 
     while (V1.size()) {
        Tree *T = V1.back();
        V1.pop_back();
        display(T);

        if (T->left)
          V2.push_back(T->left);
        if (T->right)
          V2.push_back(T->right);
      }
    }

    else {
      flag = true;

     while (V2.size()) {
        Tree *T = V2.back();
        V2.pop_back();
        display(T);

        if (T->right)
          V1.push_back(T->right);
        if (T->left)
          V1.push_back(T->left);
      }
    }
  }
}

void Tree::levelOrderPrint(std::deque<Tree *> Q) {
  if (!Q.size())
    return;

  auto *T = Q.front();
  Q.pop_front();

  if (!T)
    cout << "\n";

  else {
    display(T);
    if (T->left)
      Q.push_back(T->left);
    if (T->right)
      Q.push_back(T->right);
    if (Q.size() && !Q.front())
      Q.push_back(nullptr);
  }

  levelOrderPrint(Q);
}

void Tree::levelOrderPrint(Tree *T) {
  if (!T)
    return;

  std::deque<Tree *> Q;
  Q.push_back(T);
  Q.push_back(nullptr);
  levelOrderPrint(Q);
}

Tree *Tree::lowestCommonAncestor(Tree *T, int a, int b) {
  if (T->val < std::min(a, b))
    return lowestCommonAncestor(T->right, a, b);
  else if (T->val > std::max(a, b))
    return lowestCommonAncestor(T->left, a, b);
  return T;
}

Tree *Tree::lowestCommonAncestorNonBST(Tree *T, int a, int b) {
  if (!T)
    return nullptr;
  if (T->val == a || T->val == b)
    return T;
  if (isLeafNode(T))
    return nullptr;

  Tree *LHS = lowestCommonAncestorNonBST(T->left, a, b);
  Tree *RHS = lowestCommonAncestorNonBST(T->right, a, b);
  if (LHS && RHS)
    return T;
  return LHS ? LHS : RHS;
}

BST Tree::getLargestBST(Tree *T) {
  if (!T)
    return BST{true, 0, 0, 0};
  if (isLeafNode(T))
    return BST{true, 1, T->val, T->val};

  BST lhs = getLargestBST(T->left);
  BST rhs = getLargestBST(T->right);

  if (lhs.isBST && rhs.isBST &&
      T->val > lhs.max && T->val < rhs.min)
    return BST{true, 1 + lhs.size + rhs.size, lhs.min, rhs.max};
  return BST{false, std::max(lhs.size, rhs.size), 0, 0};
}

int Tree::inorderPred(Tree *T) {
  if (!T->left)
    return -1;

  T = T->left;
  while (T->right)
    T = T->right;
  return T->val;
}

int Tree::inorderSucc(Tree *T) {
  if (!T->right)
    return -1;

  T = T->right;
  while (T->left)
    T = T->left;
  return T->val;
}

#if 0
void Tree::insertAVL(Tree *T, int V) {
  if (isEmpty(T)) {
    T->val = V;
    T->parent = nullptr;
    T->n = std::make_pair(0, 0);
    return;
  }

  if (V < T->val) {
    if (!T->left) {
      T->left = new Tree(V, T);
      T->n.first++;
      T->left->n = std::make_pair(0, 0);
    } else {
      if (1 + T->n.first - T->n.second > 1) {
        if (V > T->left->val) {
          auto *newT = new Tree (V, T);
          auto *oldLeftT = T->left;
          T->left = newT;
          newT->left = oldLeftT;
        }

        auto *oldLeftT = T->left;
        oldLeftT->right = T;
        T->left = nullptr;
      }
    }
  }

  else if (V > T->val) {
    if (!T->right) {
      T->right = new Tree(V, T);
      T->n.second++;
      T->right->n = std::make_pair(0, 0);
    } else {
    }
  }
}
#endif
