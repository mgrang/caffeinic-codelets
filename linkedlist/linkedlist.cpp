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

  cout << "Add 10, 20, 30, 40, 50: ";
  L->add(10);
  L->add(20);
  L->add(30);
  L->add(40);
  L->add(50);
  L->print();

  cout << "3rd from end: " << L->getNthFromEnd(3) << "\n";
  cout << "1st from end: " << L->getNthFromEnd(1) << "\n";
  cout << "7th from end: " << L->getNthFromEnd(7) << "\n";

  cout << "Is palindrome: " << L->isPalindrome() << "\n";

  cout << "Add 40, 30, 20, 10, 1, 2: ";
  L->add(40);
  L->add(30);
  L->add(20);
  L->add(10);
  L->add(1);
  L->add(2);
  L->print();

  cout << "Is palindrome: " << L->isPalindrome() << "\n";

  cout << "Pair-wise swap: ";
  L->pairWiseSwap(L->getHead());
  L->print();

  cout << "Num of nodes: " << L->getNumNodes() << "\n";

  L->~LinkedList();

  cout << "--------------------------------------------------------\n";
}

int main() {
  test({1, 2, 3, 4, 5});
}
