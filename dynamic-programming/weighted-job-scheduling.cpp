#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
  int profit;
  int startTime;
  int endTime;
} Jobs;

int scheduleJobs(vector<Jobs> J) {
  int P[J.size()] = {0};
  P[0] = J[0].profit;

  int maxProfit = P[0];
  int maxIdx = 0;

  for (int right = 1; right < J.size(); ++right) {
    P[right] = J[right].profit;

    for (int left = 0; left < right; ++left) {
      if (J[left].endTime > J[right].startTime)
        continue;

      if (J[left].startTime == J[right].startTime)
        continue;

      int currProfit = P[left] + J[right].profit;
      if (currProfit > P[right]) {
        P[right] = currProfit;
        if (currProfit > maxProfit) {
          maxProfit = currProfit;
          maxIdx = right;
        }
      }
    }
  }
  return maxProfit;
}

void test(vector<Jobs> J) {
  std::sort(J.begin(), J.end(), [](Jobs A, Jobs B) {
                                  return A.endTime < B.endTime &&
                                         A.startTime < B.startTime; });
  auto res = scheduleJobs(J);
  cout << "Max profit: " << res;
  cout << "\n";
}

int main() {
  test({{6, 6, 8}, {3, 1, 4}, {5, 2, 6}, {8, 7, 10}, {4, 5, 9}, {2, 4, 7}});
  test({{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}});
  test({{1, 1, 1}, {1, 1, 1}});
  test({{1, 2, 2}, {1, 1, 2}});
}
