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

string greedyJustify(vector<string> words, int width) {
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

vector<int> optimalJustify(vector<string> words, int width) {
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
          ++j;
        }
        break;
      }
    }
  }

  vector<int> C(n);
  vector<int> P(n);
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
  return P;
}

string optimalLeftJustify(vector<string> words, int width) {
  auto P = optimalJustify(words, width);

  string s;
  int i = 0;
  while (i < P.size()) {
    int j = i;
    while (j < P[i]) {
      s += words[j] + " ";
      ++j;
    }

    s.erase(s.length() - 1);
    s += "\n";
    i = P[i];
  }

  s.erase(s.length() - 1);
  return s;
}

string optimalRightJustify(vector<string> words, int width) {
  auto P = optimalJustify(words, width);

  string s;
  int i = 0;
  while (i < P.size()) {
    int j = i;
    string line;
    while (j < P[i]) {
      line += words[j] + " ";
      ++j;
    }

    line.erase(line.length() - 1);
    int lineWidth = line.length();
    line.insert(line.begin(), width - lineWidth, ' ');

    s += line + "\n";
    i = P[i];
  }

  s.erase(s.length() - 1);
  return s;
}

void test(string text, int width) {
  auto words = getTextToWords(text);

  cout << "Width: " << width << ", Input: " << text << "\n";
  cout << "\nGreedy Justify:\n" << greedyJustify(words, width) << "\n";
  cout << "\nOptimal Left Justify:\n" << optimalLeftJustify(words, width) << "\n";
  cout << "\nOptimal Right Justify:\n" << optimalRightJustify(words, width) << "\n";
  cout << "--------------------------------------------------------------------------------\n";
}

int main() {
  test("aaa bb cc dddd", 6);
  test("aaa bb cc ddddd", 12);
  test("ABCDEF XYZ likes to code", 10);
}
