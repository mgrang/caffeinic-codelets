#include <iostream>
#include "disjoint-set.h"
using namespace std;

int main() {
  DisjointSet ds;
  ds.makeSet(1);
  ds.makeSet(2);
  ds.makeSet(3);
  ds.makeSet(4);
  ds.makeSet(5);
  ds.makeSet(6);
  ds.makeSet(7);

  ds.unionSet(1, 2);
  ds.unionSet(2, 3);
  ds.unionSet(4, 5);
  ds.unionSet(6, 7);
  ds.unionSet(5, 6);
  ds.unionSet(3, 7);

  cout << ds.find(1) << "\n";
  cout << ds.find(2) << "\n";
  cout << ds.find(3) << "\n";
  cout << ds.find(4) << "\n";
  cout << ds.find(5) << "\n";
  cout << ds.find(6) << "\n";
  cout << ds.find(7) << "\n";

  ds.~DisjointSet();
}
