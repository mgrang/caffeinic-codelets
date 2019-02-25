#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void addRange(vector<string> &res, int lo, int hi) {
  string s = (lo == hi) ?
             std::to_string(lo) :
             std::to_string(lo) + "->" + std::to_string(hi);
  res.push_back(s);
}

vector<string> getMissingRanges(vector<int> &nums, int lo, int hi) {
  vector<string> res;

  if (nums[0] != lo)
    addRange(res, lo, nums[0] - 1);

  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == nums[i - 1])
      continue;

    if (nums[i] != nums[i - 1] + 1)
      addRange(res, nums[i - 1] + 1, nums[i] - 1);
  }

  int i = nums.size() - 1;
  if (nums[i] != hi)
    addRange(res, nums[i] + 1, hi);

  return res;
}

void test(vector<int> nums, int lo, int hi) {
  cout << "nums: [ ";
  for (const auto i : nums)
    cout << i << " ";
  cout << "], lo: " << lo << ", hi: " << hi << "\n";

  cout << "missing ranges: [ ";
  auto res = getMissingRanges(nums, lo, hi);
  for (const auto i : res)
    cout << i << " ";
  cout << "]\n";
  cout << "----------------------------------------------------------\n";
}

int main() {
  test({0, 1, 3, 50, 75}, 0, 99);
  test({1, 3, 50, 75, 99}, 0, 99);
  test({0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 50, 75}, 0, 99);
  test({0, 1, 2, 3, 4, 5, 6, 7}, 0, 7);
  test({0, 1, 2, 3, 5, 6, 7}, 0, 7);
  test({3}, 0, 7);
  test({-1, 1, 2, 3, 5, 6, 7}, -1, 7);
  test({-1, 1, 2, 3, 5, 6, 7}, -7, 7);
  int min = std::numeric_limits<int>::min();
  int max = std::numeric_limits<int>::max();
  test({min, min, 0, max, max}, min, max);
}
