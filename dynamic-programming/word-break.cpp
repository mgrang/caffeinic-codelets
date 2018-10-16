#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool check(string t, std::unordered_set<string> &dict) {
  return dict.find(t) != dict.end();
}

std::pair<bool, vector<string>>
wordBreak(string s, std::unordered_set<string> &dict) {
  if (s.length() == 0)
    return std::make_pair(true, vector<string>());

  std::unordered_map<int, int> idxMap;
  int n = s.length();
  bool T[n][n];

  int start = 0;
  int end = n;

  while (start < n && end) {
    int i = 0;
    int j = start;

    while (i < end && j < n) {
      string t = s.substr(i, j - i + 1);
      T[i][j] = check(t, dict);

      if (!T[i][j]) {
        int k = i;
        while (k < j) {
          if (T[i][k] & T[k + 1][j]) {
            T[i][j] = true;
            idxMap.insert(std::make_pair(i * n + j, k));
            break;
          }
          ++k;
        }
      }

      ++i;
      ++j;
    }

    ++start;
    --end;
  }

  vector<string> words;
  bool res = T[0][n - 1];
  if (res) {
    int i = 0;
    int j = n - 1;

    while (true) {
      auto it = idxMap.find(i * n + j);

      if (it == idxMap.end()) {
        string t = s.substr(i, j - i + 1);
        words.push_back(t);
        break;
      } else {
        int k = it->second;
        string t = s.substr(i, k - i + 1);
        words.push_back(t);

        i = k + 1;
      }
    }
  }
  
  return std::make_pair(res, words);
}

void test(string s, std::unordered_set<string> dict) {
  auto res = wordBreak(s, dict);

  cout << "\n--------------------------------------------------\n";
  cout << s << ": ";
  if (res.first) {
    cout << "TRUE\n";
    cout << "Words: [";
    for (auto w : res.second)
      cout << w << ", ";
    cout << "]\n";
  } else
    cout << "FALSE\n";
}

int main() {
  test("",            {"a", "Rose", "Roses", "are", "red"});
  test("Rosesarered", {"a", "Rose", "Roses", "are", "red"});
  test("Rosesarered", {"a", "Rose", "are", "red"});
  test("osesarered",  {"a", "Rose", "Roses", "are", "red"});
  test("Roses",       {"Roses"});
}
