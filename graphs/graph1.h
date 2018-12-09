#include <deque>
#include <map>
#include <unordered_set>
using namespace std;

typedef vector<int> Vec;
typedef unordered_set<int> USet;
typedef deque<int> Deck;
typedef map<int, USet> Points;

class Graph {
private:
  Points points;

public:
  Graph() {}

  void insert(int V, int E) {
    points[V].insert(E);
  }

  bool hasEdge(int V1, int V2) {
    if (!points.count(V1))
      return false;
    return points[V1].count(V2);
  }

  void remove(int V) {
    if (!points.count(V))
      return;

    points.erase(V);

    for (auto &p : points)
      if (p.second.count(V))
        p.second.erase(V);
  }

  void print() {
    for (const auto &p : points) {
      for (const auto &q : p.second) {
        cout << p.first << "->" << q << "\n";
      }
    }
  }

  void dfsHelper(int V, USet &visited) {
    if (visited.count(V))
      return;

    visited.insert(V);
    cout << V << " ";
    for (const auto &p : points[V])
      dfsHelper(p, visited);
  }

  void dfs() {
    USet visited;

    for (const auto &p : points)
      dfsHelper(p.first, visited);
  }

  void dfsIter() {
    USet visited;
    Deck Q;

    for (const auto &p : points) {
      if (visited.count(p.first))
        continue;

      Q.push_back(p.first);

      while (Q.size()) {
        auto V = Q.front();
        Q.pop_front();

        if (visited.count(V))
          continue;

        visited.insert(V);
        cout << V << " ";
        for (const auto &p : points[V])
          Q.push_front(p);
      }
    }
  }

  void bfsHelper(Deck &Q, USet &visited) {
    while (Q.size()) {
      auto V = Q.front();
      Q.pop_front();

      if (visited.count(V))
        continue;

      visited.insert(V);
      cout << V << " ";

      for (const auto &p : points[V])
        Q.push_back(p);

      bfsHelper(Q, visited);
    }
  }

  void bfs() {
    USet visited;
    Deck Q;

    for (const auto &p : points) {
      Q.push_back(p.first);
      bfsHelper(Q, visited);
    }
  }

  void bfsIter() {
    USet visited;
    Deck Q;

    for (const auto &p : points) {
      if (visited.count(p.first))
        continue;

      Q.push_back(p.first);

      while (Q.size()) {
        auto V = Q.front();
        Q.pop_front();

        if (visited.count(V))
          continue;

        visited.insert(V);
        cout << V << " ";
        for (const auto &q : points[V])
          Q.push_back(q);
      }
    }
  }

  void visit(int V, Vec &st, USet &visited) {
    if (visited.count(V))
      return;

    visited.insert(V);
    for (const auto &p : points[V])
      visit(p, st, visited);

    st.push_back(V);
  }

  void topologicalSort() {
    USet visited;
    Vec st;

    for (const auto &p : points)
      visit(p.first, st, visited);

    while (st.size()) {
      cout << st.back() << " ";
      st.pop_back();
    }
  }
};
