#include <iostream>
#include <vector>
using namespace std;

bool isDigit(char c) {
  return c >= '0' && c <= '9';
}

string decodeStr(string s) {
  vector<char> V;
  
  int i = s.length() - 1;
  while (i >= 0) {
    while (i >= 0 && s[i] != '[') {
      V.push_back(s[i]);
      --i;
    }
    
    int count = 0;
    if (i >= 0 && s[i] == '[') {
      --i;
      int pow = 1;
      while (i >= 0 && isDigit(s[i])) {
        count += (s[i] - '0') * pow;
        pow *= 10;
        --i;
      }
      
      string tmp;
      while (V.size() && V.back() != ']') {
        tmp += V.back();
        V.pop_back();
      }

      if (V.size() && V.back() == ']')
        V.pop_back();
      
      if (count == 0)
        count = 1;
      while (count--) {
        for (int j = tmp.length() - 1; j >=0; --j)
          V.push_back(tmp[j]);
      }
    }
  }
  
  string res;
  while (V.size()) {
    res += V.back();
    V.pop_back();
  }
  return res;
}

void test(string s) {
  cout << "Encoded str: " << s << "\n";
  cout << "Decoded str: " << decodeStr(s) << "\n";
  cout << "-----------------------------------\n";
}

int main() {
  test("3[a]2[bc]");
  test("2[abc]3[cd]ef");
  test("3[a2[c]]");
}
