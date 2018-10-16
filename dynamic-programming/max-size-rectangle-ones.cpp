#include <iostream>
#include <vector>
using namespace std;

int maxRectInHist(vector<int> hist) {
  hist.push_back(0);

  vector<int> stack;
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

int maxArea(vector<vector<int>> matrix) {
  int maxArea = 0;

  vector<int> hist(matrix[0].size());
  for (auto rows : matrix) {
    for (int i = 0; i < rows.size(); ++i)
      if (rows[i])
        ++hist[i];
      else
        hist[i] = 0;

    int currMax = maxRectInHist(hist);
    if (currMax > maxArea)
      maxArea = currMax;
  }
  return maxArea;
}

void test(vector<vector<int>> matrix) {
  cout << "Input:\n";
  for (auto rows : matrix) {
    for (auto i : rows)
      cout << i << " ";
    cout << "\n";
  }

  cout << "Max area of rectangle with all 1's: " << maxArea(matrix);
  cout << "\n";
}

int main() {
  test({{1, 1, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}});
  test({{1}});
  test({{}});
  test({{1, 0, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}});
  test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  test({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}});
  test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
}
