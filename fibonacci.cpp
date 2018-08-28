#include <iostream>
using namespace std;

long fib(int n) {
  if (n < 2)
    return n;

  long a, b;
  a = 0, b = 1;
  while (n-- > 0) {
    long tmp = b;
    b += a;
    a = tmp;
  }
  return b;
}

int main() {
  int n = 42;
  cout << "fibonacci(" << n << ") = " << fib(n) << "\n";
}
