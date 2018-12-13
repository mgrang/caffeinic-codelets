#include <iostream>
#include <vector>
#include "weighted-graph.h"
using namespace std;

void test(vector<vector<int>> Points) {
  WeightedGraph G;

  for (const auto &p : Points)
    G.insert(p[0], p[1], p[2]);

  G.print();

  cout << "--------------------------------------------------------------\n";
}

int main() {
  test({{1, 2, 3}, {2, 3, 1}, {2, 4, 3}, {1, 4, 1}, {4, 5, 6}, {3, 4, 1}, {3, 6, 4}, {3, 5, 5}, {5, 6, 2}});
}
