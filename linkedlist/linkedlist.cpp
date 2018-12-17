#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;

void test(vector<int> nums) {
  LinkedList *L = new LinkedList(nums);

  cout << "List: ";
  L->print();

  cout << "Reverse list: ";
  L->reverse();
  L->print();

  cout << "Middle node: " << L->getMid() << "\n";

  cout << "Remove 3: ";
  L->remove(3);
  L->print();

  cout << "Add 10: ";
  L->add(10);
  L->print();

  cout << "Remove 5: ";
  L->remove(5);
  L->print();

  cout << "Remove 10: ";
  L->remove(10);
  L->print();

  cout << "Remove head: ";
  L->remove(L->getHead());
  L->print();

  cout << "Num of nodes: " << L->getNumNodes() << "\n";

  L->~LinkedList();

  cout << "--------------------------------------------------------\n";
}

int main() {
  test({1, 2, 3, 4, 5});
}
