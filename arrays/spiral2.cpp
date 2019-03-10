#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

vector<int> spiral(vector<vector<int>> &matrix) {
  vector<int> res;
  
  if (!matrix.size())
    return res;
  
  int rowStart = 0;
  int rowEnd = matrix.size() - 1;
  int colStart = 0;
  int colEnd = matrix[0].size() - 1;
  
  while (rowStart <= rowEnd && colStart <= colEnd) {        
    // go right;
    for (int c = colStart; c <= colEnd; ++c)
      res.push_back(matrix[rowStart][c]);
    
    ++rowStart;
    
    // go down.
    for (int r = rowStart; r <= rowEnd; ++r)
      res.push_back(matrix[r][colEnd]);
    
    --colEnd;
    
    if (rowStart > rowEnd)
      break;
    
    // go left;
    for (int c = colEnd; c >= colStart; --c)
      res.push_back(matrix[rowEnd][c]);
    
    --rowEnd;
    
    if (colStart > colEnd)
      break;
    
    // go up;
    for (int r = rowEnd; r >= rowStart; --r)
      res.push_back(matrix[r][colStart]);
    
    ++colStart;
  }
  return res;
}

void test(vector<vector<int>> nums) {
  auto res = spiral(nums);

  cout << "Input:\n";
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = 0; j < nums[0].size(); ++j)
      cout << nums[i][j] << " ";
    cout << "\n";
  }

  cout << "Output: ";
  for (auto i : res)
    cout << i << " ";
  cout << "\n----------------------------------------------------\n";
}

int main() {
  test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  test({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
  test({{}});
  test({{1}});
  test({{1, 2, 3, 4, 5, 6}});
  test({{1}, {2}, {3}, {4}, {5}, {6}});
  test({{1, 2}, {3, 4}, {5, 6}});
}
