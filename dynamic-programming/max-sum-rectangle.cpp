#include <iostream>
#include <vector>
using namespace std;

std::pair<int, std::pair<int, int>> maxSumSubarray(vector<int> nums) {
  int maxSum = nums[0];
  int currSum = nums[0];
  int maxIdx = 0;
  int prev[nums.size()];

  prev[0] = -1;

  for (int i = 1; i < nums.size(); ++i) {
    if (currSum + nums[i] > nums[i]) {
      currSum += nums[i];
      prev[i] = i - 1;
    } else {
      currSum = nums[i];
      prev[i] = -1;
    }

    if (currSum > maxSum) {
      maxSum = currSum;
      maxIdx = i;
    }
  }

  int right = maxIdx;
  while (prev[maxIdx] != -1)
    maxIdx = prev[maxIdx];

  return std::make_pair(maxSum, std::make_pair(maxIdx, right));
}

vector<int> maxSumSquare(vector<vector<int>> matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  int maxSum = matrix[0][0];
  int left = 0;
  int right = 0;
  int up = 0;
  int down = 0;

  for (int i = 0; i < n; ++i) {
    vector<int> T(n);

    for (int k = i; k < n; ++k) {
      for (int j = 0; j < m; ++j)
        T[j] += matrix[k][j];

      auto res = maxSumSubarray(T);
      if (res.first > maxSum) {
        maxSum = res.first;
        left = res.second.first;
        right = res.second.second;
        up = i;
        down = k;
      }
    }
  }

  return {maxSum, left, right, up, down};
}

void test(vector<vector<int>> matrix) {
  cout << "Input:\n";
  for (auto rows : matrix) {
    for (auto i : rows)
      cout << i << " ";
    cout << "\n";
  }

  auto res = maxSumSquare(matrix);
  cout << "Max sum square matrix: " << res[0] << "\n";
  cout << "L, R, U, D: " << res[1] << ", " << res[2] << ", " << res[3] << ", " << res[4];
  cout << "\n";
}

int main() {
  test({{1, 1, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}});
  test({{1}});
  test({{1, 0, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}});
  test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  test({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}});
  test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
  test({{2, 1, -3, -4, 5}, {0, 6, 3, 4, 1}, {2, -2, -1, 4, -5}, {-3, 3, 1, 0, 3}});
}
