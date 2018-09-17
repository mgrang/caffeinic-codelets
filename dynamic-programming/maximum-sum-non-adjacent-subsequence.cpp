#include <iostream>
#include <vector>
using namespace std;

std::pair<int, std::vector<int>> maxSumNonAdjSub(std::vector<int> nums) {
  int sum[nums.size()];
  int prev[nums.size()];
  int maxIdx = 0;
  int maxSum = nums[0];

  for (int i = 0; i < nums.size(); ++i) {
    sum[i] = nums[i];
    prev[i] = -1;

    if (i > 1) {
      int a = sum[i] + sum[i - 1] - nums[i - 1];
      int b = sum[i] + sum[i - 2];

      if (a > b) {
        sum[i] = a;
        prev[i] = prev[i - 1];
      } else {
        sum[i] = b;
        prev[i] = i - 2;
      }
    }

    if (sum[i] > maxSum) {
      maxSum = sum[i];
      maxIdx = i;
    }
  }

  std::vector<int> seq;
  while (maxIdx >= 0) {
    seq.insert(seq.begin(), nums[maxIdx]);
    maxIdx = prev[maxIdx];
  }

  return std::make_pair(maxSum, seq);
}

void test(std::vector<int> nums) {
  cout << "Input: ";
  for (auto i : nums)
    cout << i << " ";
  cout << "\n";

  auto res = maxSumNonAdjSub(nums);

  cout << "Max sum: " << res.first << "\n";
  cout << "Max sum non-adjacent sequence: ";
  for (auto i : res.second)
    cout << i << " ";
  cout << "\n";
}

int main() {
  test({2, 4, 3, 5, 1, 7, 6, 9, 8});
  test({1});
  test({1, 2, 1, 2, 1});
  test({1, 2, 1, 3, 1, 4});
  test({5, 4, 3, 2, 1});
  test({1, 2, 3, 4, 5});
  test({1, 0, 2, -1});
  test({-1, -2, -3});
  test({-3, -2, -1});
  test({-3, -2, -1});
}
