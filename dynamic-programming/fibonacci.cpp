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

void test(int n) {
  cout << "fibonacci(" << n << ") = " << fib(n) << "\n";
}

int main() {
  test(1);
  test(42);
  test(99);
  test(100);
}
