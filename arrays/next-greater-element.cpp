#include <iostream>
#include <vector>
using namespace std;

vector<int> getNextGreater(vector<int> &V) {
  vector<int> res(V.size());
  vector<int> st;

  for (int i = 0; i < V.size(); ++i) {
    while (st.size() && V[i] > V[st.back()]) {
      res[st.back()] = V[i];
      st.pop_back();
    }
    st.push_back(i);
  }
  return res;
}

void test(vector<int> V) {
  cout << "Input:  ";
  for (const auto i : V)
    cout << i << " ";
  cout << "\n";

  auto res = getNextGreater(V);
  cout << "Output: ";
  for (const auto i : res)
    cout << i << " ";
  cout << "\n";
  cout << "--------------------------------\n";
}

int main() {
  test({1, 3, 10, 2, 5, 4, 7, 8});
  test({5, 4, 3, 2, 1});
  test({1, 2, 3, 4, 5});
  test({});
  test({1});
  test({1, 10, 2, 11, 3, 12});
  test({1, 20, 2, 19, 3, 18, 4, 17, 5});
  test({10, 9, 8, 7, 6, 100});
}
