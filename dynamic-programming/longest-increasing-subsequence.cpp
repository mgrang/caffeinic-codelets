#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

std::pair<int, std::vector<int>> lis(std::vector<int> nums) {
  std::vector<int> lens(nums.size());
  std::vector<int> preds(nums.size());

  lens[0] = 1;
  preds[0] = -1;

  int maxLen = 1;
  int maxIdx = 0;

  for (int i = 1; i < nums.size(); ++i) {
    int currMaxLen = 1;

    for (int j = 0; j < i; ++j) {
      if (nums[j] >= nums[i])
        continue;

      if (lens[j] < currMaxLen)
        continue;

      lens[i] = 1 + lens[j];
      preds[i] = j;

      currMaxLen = lens[i];

      if (currMaxLen > maxLen) {
        maxLen = currMaxLen;
        maxIdx = i;
      }
    }
  }

  std::vector<int> seq;
  while (maxIdx >= 0) {
    seq.insert(seq.begin(), nums[maxIdx]);
    maxIdx = preds[maxIdx];
  }

  return std::make_pair(maxLen, seq);
}

void test(std::vector<int> nums) {
  cout << "Input: ";
  for (auto i : nums)
    cout << i << " ";
  cout << "\n";

  auto res = lis(nums);

  cout << "LIS Length: " << res.first << "\n";
  cout << "LIS: ";
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
