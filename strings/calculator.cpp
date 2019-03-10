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

int doMulOrDiv(vector<int> &nums, vector<char> &ops) {
  int num2 = nums.back();
  nums.pop_back();

  int num1 = nums.back();
  nums.pop_back();

  char op = ops.back();
  ops.pop_back();

  return op == '*' ?
         num1 * num2 :
         num1 / num2;
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
          int res = doMulOrDiv(nums, ops);
          nums.push_back(res);
        }
      }
    }
  }

  if (ops.size() && isMulOrDiv(ops.back())) {
    int res = doMulOrDiv(nums, ops);
    nums.push_back(res);
  }

  int res = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    int num2 = nums[i];
    char op = ops[i - 1];

    switch(op) {
      case '+': res += num2; break;
      case '-': res -= num2; break;
      case '*': res *= num2; break;
      case '/': res /= num2; break;
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
  test("1-1+1");
  test("1+1-1");
  test("0-2147483647");
  test("3+2*2");
  test("14-3/2");
}
