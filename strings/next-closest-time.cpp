#include <iostream>
#include <unordered_set>
using namespace std;

std::pair<bool, int> isValid(string s, unordered_set<char> &Set) {
  for (int i = 0; i < s.length(); ++i)
    if (!Set.count(s[i]))
      return std::make_pair(false, i);
  return std::make_pair(true, 0);
}

string getNextClosestTime(string t) {
  unordered_set<char> Set;

  for (const auto c : t)
    Set.insert(c);

  string s = t;
  string strH = s.substr(0, 2);
  string strM = s.substr(3, 2);
  int intH = std::stoi(strH);
  int intM = std::stoi(strM);

  while (true) {
    while (intM < 59) {
      ++intM;

      strM = std::to_string(intM);
      if (strM.length() == 1)
        strM = "0" + strM;

      s = strH + strM;
      auto res = isValid(s, Set);

      if (res.first)
        return strH + ":" + strM;

      if (res.second < 2)
        break;

      if (res.second == 2)
        intM += 9;
    }

    intM = -1;

    if (intH == 23)
      intH = -1;

    ++intH;
    strH = std::to_string(intH);

    if (strH.length() == 1)
      strH = "0" + strH;
  }

  return "-";
}

void test(string t) {
  cout << "Next closest time to " << t << " is " << getNextClosestTime(t) << "\n";
}

int main() {
  test("19:34");
  test("23:59");
  test("00:00");
  test("12:00");
  test("00:01");
  test("12:34");
}
