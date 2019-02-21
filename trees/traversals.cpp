#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

using Vec = vector<int>;
using Deck = deque<int>;
using UMap = unordered_map<int, int>;

void print(Vec &V) {
  for (const auto i : V)
    cout << i << " ";
  cout << "\n";
}

void print(Deck Q) {
  while (Q.size()) {
    cout << Q.back() << " ";
    Q.pop_back();
  }
  cout << "\n";
}

int getRoot(int lo, int hi, Vec &in, UMap &preMap) {
  int minIdx = in.size();
  for (int i = lo; i < hi; ++i)
    if (preMap[in[i]] < minIdx)
      minIdx = preMap[in[i]];
  return minIdx;
}

void getPost(int lo, int hi, Vec &in, Vec &pre, UMap &inMap, UMap &preMap, Deck &Q) {
  if (lo >= hi)
    return;

  int rootIdx = getRoot(lo, hi, in, preMap);
  int root = pre[rootIdx];
  Q.push_back(root);

  rootIdx = inMap[root];
  getPost(rootIdx + 1, hi, in, pre, inMap, preMap, Q);
  getPost(lo, rootIdx, in, pre, inMap, preMap, Q);
}

Deck getPost(Vec in, Vec pre) {
  UMap inMap;
  UMap preMap;

  for (int i = 0; i < in.size(); ++i) {
    inMap[in[i]] = i;
    preMap[pre[i]] = i;
  }

  Deck Q;
  getPost(0, in.size(), in, pre, inMap, preMap, Q);
  return Q;
}

void test(Vec in, Vec pre, Vec post) {
  cout << "Input:\n";
  cout << "Inorder: ";
  print(in);
  cout << "Preorder: ";
  print(pre);
  cout << "Postorder: ";
  print(post);

  cout << "Output:\n";
  cout << "Postorder: ";
  print(getPost(in, pre));
}

int main() {
  test({4, 2, 5, 1, 3, 6}, {1, 2, 4, 5, 3, 6}, {4, 5, 2, 6, 3, 1});
}
