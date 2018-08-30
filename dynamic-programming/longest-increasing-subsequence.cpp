#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
  int len;
  vector<int> seq;
} LIS;

LIS lis(vector<int> nums) {
  vector<int> lens(nums.size());
  vector<int> preds(nums.size());

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

  vector<int> seq;
  while (maxIdx >= 0) {
    seq.insert(seq.begin(), nums[maxIdx]);
    maxIdx = preds[maxIdx];
  }

  return LIS {maxLen, seq};
}

int main() {
  vector<int> nums = {2, 4, 3, 5, 1, 7, 6, 9, 8};

  cout << "Input: ";
  for (auto i : nums)
    cout << i << " ";
  cout << "\n";

  LIS res = lis(nums);

  cout << "LIS Length: " << res.len << "\n";
  cout << "LIS: ";
  for (auto i : res.seq)
    cout << i << " ";
  cout << "\n";
}
