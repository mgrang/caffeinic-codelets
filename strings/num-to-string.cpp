#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[] = {"zero", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string numToString(int n) {
  if (!n)
    return units[n];

  string s = std::to_string(n);
  int l = s.length();
  int p = pow(10, l - 1);
  int i = 0;

  string res;
  while (i < l) {
    int x = s[i] - '0';

    if (!x) {
      i++;
      p /= 10;
      continue;
    }

    if (p == 1)
      res += units[x] + " ";
    else if (p == 10) {
      if (x == 1) {
        res += teens[x] + " ";
        break;
      }
      else 
        res += tens[x] + " ";
    }
    else if (p == 100)
      res += units[x] + " hundred ";
    else if (p == 1000)
      res += units[x] + " thousand ";

    i++;
    p /= 10;
  }

  return res;
}

void test(int n) {
  cout << n << " = " << numToString(n) << "\n";
}

int main() {
  test(1233);
  test(60);
  test(5961);
  test(999);
  test(11);
  test(0);
  test(87);
  test(1021);
  test(5030);
  test(9090);
  test(9009);
}
