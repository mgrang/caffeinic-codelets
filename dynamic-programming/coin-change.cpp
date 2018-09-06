#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> coinChange(int target, std::vector<int> coins) {
  // T is unsigned int to guard against integer overflow.
  unsigned int T[target + 1];
  unsigned int U[target + 1];

  for (int i = 0; i <= target; ++i) {
    T[i] = std::numeric_limits<int>::max();
    U[i] = -1;
  }

  T[0] = 0;

  for (int i = 0; i < coins.size(); ++i) {
    for (int j = 1; j <= target; ++j) {
      if (j < coins[i])
        continue;

      int newCoins = 1 + T[j - coins[i]];
      if (newCoins < T[j]) {
        T[j] = newCoins;
        U[j] = i;
      }
    }
  }

  std::vector<int> coinsReq;
  int i = target;
  while (i > 0 && U[i] > -1) {
    coinsReq.insert(coinsReq.begin(), coins[U[i]]);
    i -= coins[U[i]];
  }

  return coinsReq;
}

int main() {
  int target = 13;
  std::vector<int> coins = {2, 3, 5};

  cout << "Target: " << target << "\n";
  cout << "Input coins: ";
  for (auto c : coins)
    cout << c << " ";
  cout << "\n";

  std::vector<int> coinsReq = coinChange(target, coins);
  cout << "Output coins: ";
  for (auto c : coinsReq)
    cout << c << " ";
  cout << "\n";
}
