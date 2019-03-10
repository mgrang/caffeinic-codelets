#include <iostream>
#include <vector>
using namespace std;

bool isAddOrSub(char c) {
  return c == '+' || c == '-';
}

bool isMulOrDiv(char c) {
  return c == '*' || c == '/';
}

bool isOperator(char c) {
  return isAddOrSub(c) || isMulOrDiv(c);
}

bool isDigit(char c) {
  return c >= '0' && c <= '9';
}

int calculate(string s) {
  vector<int> nums;
  vector<char> ops;

  for (int i = 0; i < s.length(); ++i) {
    char c = s[i];

    if (c == ' ')
      continue;

    if (isOperator(c))
      ops.push_back(c);

    else {
      int digit = c - '0';

      if (i > 0 && isDigit(s[i - 1])) {
        digit += (nums.back() * 10);
        nums.pop_back();
      }
      nums.push_back(digit);

      if (i < s.length() - 1 && isOperator(s[i + 1])) {
        if (ops.size() && isMulOrDiv(ops.back())) {
          int num2 = nums.back();
          nums.pop_back();

          int num1 = nums.back();
          nums.pop_back();

          char op = ops.back();
          ops.pop_back();

          int res = op == '*' ?
                    num1 * num2 :
                    num1 / num2;

          nums.push_back(res);
        }
      }
    }
  }

  int res = nums.back();
  nums.pop_back();

  while (ops.size()) {
    int num1 = nums.back();
    nums.pop_back();

    char op = ops.back();
    ops.pop_back();

    switch(op) {
      case '+': res = num1 + res; break;
      case '-': res = num1 - res; break;
      case '*': res = num1 * res; break;
      case '/': res = num1 / res; break;
    }
  }
  return res;
}

void test(string s) {
  cout << s << " = " << calculate(s) << "\n";
}

int main() {
  test("1+2");
  test("3+2*2");
  test("3/2");
  test("3+5/2");
  test("1*2*3*4");
}
