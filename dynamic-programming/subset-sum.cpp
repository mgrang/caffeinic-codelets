#include <iostream>
#include <vector>
using namespace std;

std::vector<int> subsetSum(int sum, std::vector<int> nums) {
  bool T[nums.size() + 1][sum + 1];

  int row = -1;

  for(int i = 0; i <= nums.size(); ++i) {
    for (int j = 0; j <= sum; ++j) {
      if (j == nums[i - 1])
        T[i][j] = true;
      else if (i == 0)
        T[i][j] = false;
      else if (j == 0)
        T[i][j] = true;
      else if (j < nums[i - 1])
        T[i][j] = T[i - 1][j];
      else
        T[i][j] = T[i - 1][j - nums[i - 1]];
      }

    if (T[i][sum]) {
      row = i;
      break;
    }
  }

  std::vector<int> subset;
  if (row > -1) {
    int col = sum;

    while (row && col && T[row][col]) {
      while (row && T[row - 1][col])
        --row;

      if (row)
        subset.insert(subset.begin(), nums[row - 1]);

      col -= nums[row - 1];
      --row;
    }
  }

  return subset;
}

void test(std::vector<int> nums, int sum) {
  cout << "Target sum: " << sum << "\n";
  cout << "Input: ";
  for (auto I : nums)
    cout << I << " ";
  cout << "\n";

  if (sum == 0) {
    cout << "Subset sum: {}\n";
    return;
  }

  std::vector<int> S = subsetSum(sum, nums);
  if (S.size()) {
    cout << "Subset sum: ";
    for (auto I : S)
      cout << I << " ";
  } else
    cout << "Subset sum does not exist";
  cout << "\n";
}

int main() {
  test({1, 3, 4, 5, 7}, 19);
  test({1, 3, 4, 5, 7}, 2);
  test({1, 1, 1, 1, 1}, 5);
  test({1, 3, 4, 5, 7}, 100);
  test({1, 3, 4, 5, 7}, 13);
}
