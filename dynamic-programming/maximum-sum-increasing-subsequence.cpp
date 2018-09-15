#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

std::pair<int, std::vector<int>> msis(vector<int> nums) {
  int sum[nums.size()];
  int prev[nums.size()];
  int maxSum = nums[0];
  int maxIdx = 0;

  sum[0] = nums[0];
  prev[0] = -1;

  for (int i = 1; i < nums.size(); ++i) {
    sum[i] = nums[i];
    prev[i] = -1;
 
    for (int j = 0; j < i; ++j) {
      if (nums[j] < nums[i] &&
          nums[i] + sum[j] > sum[i]) {
        sum[i] = nums[i] + sum[j];
        prev[i] = j;
      }

      if (sum[i] > maxSum) {
        maxSum = sum[i];
        maxIdx = i;
      }
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

  auto res = msis(nums);

  cout << "Max sum: " << res.first << "\n";
  cout << "Max sum increasing sequence: ";
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
}
