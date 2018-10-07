#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> getTextToWords(string text) {
  istringstream i(text);
  string s;
  vector<string> words;
  while (getline(i, s, ' '))
    words.push_back(s);
  return words;
}

string greedyLeftJustify(string text, int width) {
  auto words = getTextToWords(text);

  string s = words[0];
  int currWidth = width - s.length();

  for (int i = 1; i < words.size(); ++i) {
    string w = words[i];
    int l = w.length();

    // +1 for the space between words.
    if (l + 1 <= currWidth) {
      currWidth -= (l + 1);
      s += " " + w;
    } else {
      currWidth = width - l - 1;
      s += "\n" + w;
    }
  }

  return s;
}

string optimalJustify(string text, int width) {
  auto words = getTextToWords(text);
  int n = words.size();
  int T[n][n] = {0};
  const int INF = std::numeric_limits<int>::max();

  for (int i = 0; i < n; ++i) {
    int currWidth = width;

    for (int j = i; j < n; ++j) {
      int space = j == i ? 0 : 1;

      currWidth -= (words[j].length() + space);

      if (currWidth >= 0)
        T[i][j] = currWidth * currWidth;
      else {
        while (j < n) {
          T[i][j] = INF;
          j++;
        }
        break;
      }
    }
  }

  int C[n];
  int P[n];

  int i = n - 1;
  int j = n - 1;

  while (i >= 0) {
    if (T[i][j] != INF) {
      C[i] = T[i][j];
      P[i] = j + 1;
      --i;
      continue;
    }

    while (j > i && T[i][j] == INF)
      --j;

    C[i] = T[i][j] + C[j + 1];
    P[i] = j + 1;

    while (j >= i) {
      if (T[i][j] + C[j + 1] < C[i]) {
        C[i] = T[i][j] + C[j + 1];
        P[i] = j + 1;
      }
      --j;
    }

    --i;
    j = n - 1;
  }

  string s;
  i = 0;
  while (i < n) {
    int j = i;
    while (j < P[i]) {
      s += words[j] + " ";
      ++j;
    }
    s += "\n";
    i = P[i];
  }

  s.erase(s.length() - 1);
  return s;
}

void test(string text, int width) {
  cout << "Width: " << width << ", Input: " << text << "\n";
  cout << "\nGreedy:\n" << greedyLeftJustify(text, width) << "\n";
  cout << "\nOptimal:\n" << optimalJustify(text, width) << "\n";
  cout << "--------------------------------------------------------------------------------\n";
}

int main() {
  test("aaa bb cc dddd", 6);
  test("aaa bb cc ddddd", 12);
  test("ABCDEF XYZ likes to code", 10);
}
