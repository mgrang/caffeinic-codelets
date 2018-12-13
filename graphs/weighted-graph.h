#include <map>
#include <unordered_set>
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

  void insert(int V, int E, int W = 0) {
    points[V].insert(std::make_pair(E, W));
  }

  void print() {
    for (const auto &p : points) {
      for (const auto &q : p.second) {
        cout << p.first << "->" << q.first << ", w = " << q.second << "\n";
      }
    }
  }
};
