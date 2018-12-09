#include <iostream>
#include <vector>
#include "graph1.h"
using namespace std;

void test(vector<std::pair<int, int>> Points) {
  Graph *G = new Graph();
  for (auto &p : Points)
    G->insert(p.first, p.second);

  G->print();
  vector<int> stack = G->topologicalSort();
  cout << "Topological sort: ";
  while (stack.size()) {
    cout << stack.back() << " ";
    stack.pop_back();
  }
  cout << "\n";
}

int main() {
  test({{1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 7}, {5, 6}, {6, 7}, {7, 8}});
}
