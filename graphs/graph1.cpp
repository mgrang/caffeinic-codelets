#include <iostream>
#include <vector>
#include "graph1.h"
using namespace std;

void test(vector<std::pair<int, int>> Points) {
  Graph G;

  for (const auto &p : Points)
    G.insert(p.first, p.second);

  G.print();

  cout << "Topological sort: ";
  G.topologicalSort();
  cout << "\n";

  cout << "DFS: ";
  G.dfs();
  cout << "\n";

  cout << "DFS Iter: ";
  G.dfsIter();
  cout << "\n";

  cout << "BFS: ";
  G.bfs();
  cout << "\n";

  cout << "BFS Iter: ";
  G.bfsIter();
  cout << "\n";

  cout << "Has cycle: " << G.hasCycle();
  cout << "\n";

  G.remove(5);

  for (const auto &p : Points)
    cout << "Edge (" << p.first << ", " << p.second << "): "
         << G.hasEdge(p.first, p.second) << "\n";

  cout << "--------------------------------------------------------------\n";
}

int main() {
  test({{1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 7}, {5, 6}, {6, 7}, {7, 8}});
  test({{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}, {6, 8}, {7, 8}});
}
