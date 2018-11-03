#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
  int length;
  int width;
  int height;
} Box;

typedef vector<Box> Boxes;

void printBox(Box b) {
  cout << "[" <<
            b.length << ", " <<
            b.width  << ", " <<
            b.height <<
          "] ";
}

Boxes getRotations(Boxes boxes) {
  Boxes Rot;

  for (auto b : boxes) {
    if (b.length >= b.width)
     Rot.push_back({b.length, b.width, b.height});
    else Rot.push_back({b.width, b.length, b.height});
  
    if (b.length >= b.height)
     Rot.push_back({b.length, b.height, b.width});
    else Rot.push_back({b.height, b.length, b.width});
  
    if (b.width >= b.height)
     Rot.push_back({b.width, b.height, b.length});
    else Rot.push_back({b.height, b.width, b.length});
  }

  std::sort(Rot.begin(), Rot.end(), [](Box b1, Box b2) {
            return b1.length * b1.width >= b2.length * b2.width; });

  return Rot;
}

std::pair<int, Boxes> stackBoxes(Boxes boxes) {
  Boxes Rot = getRotations(boxes);

  int T[Rot.size()];
  int S[Rot.size()];

  T[0] = Rot[0].height;
  S[0] = -1;

  int maxHeight = T[0];
  int maxIdx = 0;

  for (int i = 1; i < Rot.size(); ++i) {
    T[i] = Rot[i].height;
    S[i] = i;

    for (int j = 0; j < i; ++j) {
      if (Rot[i].length < Rot[j].length &&
          Rot[i].width  < Rot[j].width) {
        if (Rot[i].height + T[j] > T[i]) {
          T[i] = Rot[i].height + T[j];
          S[i] = j;
        }
      }
    }

    if (T[i] > maxHeight) {
      maxHeight = T[i];
      maxIdx = i;
    }
  }

  Boxes boxStack;
  int i = maxIdx;
  while (i >= 0) {
    boxStack.push_back(Rot[i]);
    i = S[i];
  }

  return std::make_pair(maxHeight, boxStack);
}

void test(Boxes boxes) {
  cout << "Input: ";
  for (auto b : boxes)
    printBox(b);
  cout << "\n";

  auto res = stackBoxes(boxes);

  cout << "Max Height: " << res.first << "\n";
  cout << "Stack: ";
  for (auto b : res.second)
    printBox(b);
  cout << "\n";
}

int main() {
  test({{1, 2, 4}, {3, 2, 5}});
  test({{1, 1, 1}, {2, 2, 2}});
}
