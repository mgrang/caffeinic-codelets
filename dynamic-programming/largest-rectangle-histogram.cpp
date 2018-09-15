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
      int newTop = stack[stack.size() - 1];

      int currArea;
      if (stack.size() == 0) {
        currArea = hist[top] * i;
      }
      else {
        currArea = hist[top] * (i - newTop - 1);
      }

      if (currArea > maxArea)
        maxArea = currArea;

      top = stack.back();
    }
    stack.push_back(i);
  }

  return maxArea;
}

int main() {
  std::vector<int> hist = {6, 2, 5, 4, 5, 1, 6};

  cout << "Input: ";
  for (auto i : hist)
    cout << i << " ";
  cout << "\n";

  cout << "Max rectangle area: " << maxArea(hist);
  cout << "\n";
}
