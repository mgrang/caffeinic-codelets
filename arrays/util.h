#include <vector>
using namespace std;

void print(vector<int> &V) {
  for (auto i : V)
    cout << i << " ";
  cout << "\n";
}

void swap(vector<int> &V, int i, int j) {
  auto tmp = V[i];
  V[i] = V[j];
  V[j] = tmp;
}
