#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

std::pair<int, std::pair<int, int>> maxSumSubarray(std::vector<int> nums) {
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

void test(std::vector<int> nums) {
  cout << "Input: ";
  for (auto i : nums)
    cout << i << " ";
  cout << "\n";

  auto res = maxSumSubarray(nums);

  cout << "Max sum: " << res.first << ", Subarray: ";
  for (int i = res.second.first; i <= res.second.second; ++i)
    cout << nums[i] << " ";
  cout << "\n";
}

int main() {
  test({2, -4, 3, -5, 1, 7, -6, 9, 8});
  test({1});
  test({1, 2, 1, 2, 1});
  test({-1, 2, -1, 3, -1, 4});
  test({5, -4, 3, -2, 1});
  test({-1, 2, 3, -4, 5});
  test({-1, 0, 2, -1});
  test({-1, -2, -3});
  test({-3, -2, -1});
}
