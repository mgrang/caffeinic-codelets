#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int getLeastMatrixMulCost(vector<std::pair<int, int>> matrix) {
  int size = matrix.size();
  int T[size][size] = {0};

  int start = 0;
  int end = size;

  while (start < size) {
    int i = 0;
    int j = start;

    while (i < end && j < size) {
      if (i != j) {
        auto dimI = matrix[i];
        auto dimJ = matrix[j];
        int currProd = dimI.first * dimJ.second;
        int k = i;

        T[i][j] = std::numeric_limits<int>::max();

        while (k < j) {
          auto dimK = matrix[k];

          int currCost = T[i][k] + T[k + 1][j] + (currProd * dimK.second);

          if (currCost < T[i][j])
            T[i][j] = currCost;

          ++k;
        }
      }

      ++j;
      ++i;
    }

    ++start;
    --end;
  }

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      cout << T[i][j] << " ";
    }
    cout << "\n";
  }

  return T[0][size - 1];
}

void test(vector<std::pair<int, int>> matrix) {
  cout << "Input: ";
  for (auto row : matrix) {
    cout << "[" << row.first << "x" << row.second << "] ";
  }
  cout << "\n";

  cout << "Min cost: " << getLeastMatrixMulCost(matrix);
  cout << "\n";
}

int main() {
  test({{5, 4}, {4, 6}, {6, 2}, {2, 7}});
  test({{1, 2}, {2, 3}, {3, 4}, {4, 5}});
  test({{5, 4}, {4, 3}, {3, 2}, {2, 1}});
  test({{1, 2}});
  test({{0, 0}});
}
