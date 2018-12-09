#include <map>
#include <set>
#include <unordered_set>
using namespace std;

typedef map<int, set<int>> List;

class Graph {
private:
  List list;

public:
  Graph() {}

  void insert(int V, int E) {
    set<int> edges;
    if (list.count(V))
      edges = list[V];

    edges.insert(E);
    list[V] = edges;

    if (!list.count(E))
      list[E] = set<int>();
  }

  void print() {
    for (const auto &p : list) {
      for (const auto &q : p.second) {
        cout << p.first << "->" << q << "\n";
      }
    }
  }

  void dfs(int V, vector<int> &stack) {
    static unordered_set<int> visited;

    if (visited.count(V))
      return;

    visited.insert(V);
    for (const auto &p : list[V])
      dfs(p, stack);

    stack.push_back(V);
  }

  vector<int> topologicalSort() {
    vector<int> stack;

    for (const auto &p : list)
      dfs(p.first, stack);

    return stack;
  }
};
