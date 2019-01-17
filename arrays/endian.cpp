#include<iostream>
using namespace std;

bool isLittleEndian() {
  int val = 1;
  char *c = (char *) &val;
  return *c;
}

int main() {
  cout << "Is little endian: " << isLittleEndian() << "\n";
}
