#include <iostream>
#include <vector>
using namespace std;

int maxArea(std::vector<int> hist) {
  hist.push_back(0);

  std::vector<int> stack;
  stack.push_back(0);
  int maxArea = hist[0];

  for (int i = 1; i < hist.size(); ++i) {
    int top = stack.back();

    while (stack.size() && hist[i] < hist[top]) {
      stack.pop_back();
      int newTop = stack.back();

      int currArea;
      if (stack.size() == 0)
        currArea = hist[top] * i;
      else
        currArea = hist[top] * (i - newTop - 1);

      if (currArea > maxArea)
        maxArea = currArea;

      top = newTop;
    }
    stack.push_back(i);
  }

  return maxArea;
}

void test(std::vector<int> hist) {
  cout << "Input: ";
  for (auto i : hist)
    cout << i << " ";
  cout << "\n";

  cout << "Max rectangle area: " << maxArea(hist);
  cout << "\n";
}

int main() {
  test({6, 2, 5, 4, 5, 1, 6});
  test({1, 2, 3, 4, 5});
  test({5, 4, 3, 2, 1});
  test({1});
  test({-1, 0, -1});
}

