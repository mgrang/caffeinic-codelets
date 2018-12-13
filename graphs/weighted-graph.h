#include <algorithm>
#include <map>
#include <unordered_set>
#include <vector>
#include "disjoint-set.h"
using namespace std;

struct PairHash {
  size_t operator() (const std::pair<int, int> &pair) const {
    return std::hash<int>()(pair.first);
  }
};

using Vec = vector<int>;
using USet = unordered_set<std::pair<int, int>, PairHash>;
using Points = map<int, USet>;

class WeightedGraph {
private:
  Points points;

public:
  WeightedGraph() {}

  void insert(int V1, int V2, int W = 0) {
    points[V1].insert(std::make_pair(V2, W));

    if (!points.count(V2))
      points[V2] = USet();
  }

  void print() {
    for (const auto &p : points) {
      for (const auto &q : p.second) {
        cout << p.first << "->" << q.first << ", w = " << q.second << "\n";
      }
    }
  }

  void kruskalMinSpanningTree() {
    DisjointSet ds;
    vector<vector<int>> edges;

    for (const auto &p : points) {
      ds.makeSet(p.first);
      int V1 = p.first;

      for (const auto &q : p.second) {
        int V2 = q.first;
        int W = q.second;
        edges.push_back({V1, V2, W});
      }
    }

    auto comparator = [](vector<int> &A, vector<int> &B) {
                        return A[2] < B[2]; };
    std::sort(edges.begin(), edges.end(), comparator);

    for (const auto &e : edges) {
      int V1 = e[0];
      int V2 = e[1];
      int W  = e[2];

      if (ds.find(V1) == ds.find(V2))
        continue;

      ds.unionSet(V1, V2);

      cout << V1 << " --> " << V2 << ", w = " << W << "\n";
    }
  }
};
