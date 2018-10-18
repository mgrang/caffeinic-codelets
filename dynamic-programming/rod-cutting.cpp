#include <algorithm>
#include <iostream>
using namespace std;

int rodCutting(int rodLen, vector<int> lens, vector<int> vals) {
  int T[rodLen + 1] = {0};
  int S[rodLen + 1] = {0};

  int *ptrT = T;
  int *ptrS = S;

  bool flag = false;
  int i = 0;
  while (i < lens.size()) {
    int j = 1;
    ++ptrT;
    ++ptrS;

    while (j < lens[i]) {
      *ptrT = *ptrS;
      ++ptrT;
      ++ptrS;
      ++j;
    }

    while (j <= rodLen) {
      *ptrT = std::max(*ptrS, (vals[i] + *(ptrT - lens[i])));
      ++ptrT;
      ++ptrS;
      ++j;
    }

    ++i;

    if (flag) {
      flag = false;
      ptrT = T;
      ptrS = S;
    } else {
      flag = true;
      ptrT = S;
      ptrS = T;
    }
  }

  return T[rodLen];
}

int main() {
  int rodLen = 5;
  vector<int> lens = {1, 2, 3, 4};
  vector<int> vals = {2, 5, 7, 8};
  
  cout << "Max val: " << rodCutting(rodLen, lens, vals) << "\n";
}
