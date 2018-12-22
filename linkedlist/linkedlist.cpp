#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;

void test(const vector<int> &nums) {
  auto *L = new LinkedList(nums);

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

  cout << "Move 1 to front: ";
  L->moveNToFront(1);
  L->print();

  cout << "Move 2 to front: ";
  L->moveNToFront(2);
  L->print();

  L->~LinkedList();

  cout << "--------------------------------------------------------\n";
}

void test2(const vector<int> &nums1, const vector<int> &nums2) {
  auto *L1 = new LinkedList(nums1);
  auto *L2 = new LinkedList(nums2);

  cout << "List1: ";
  L1->print();

  cout << "List2: ";
  L2->print();

  cout << "Intersection: ";
  L1->getSortedIntersection(L2->getHead());

  L1->~LinkedList();
  L2->~LinkedList();
  cout << "--------------------------------------------------------\n";
}

void test3(vector<int> nums) {
  auto *L = new LinkedList(nums);

  cout << "List: ";
  L->print();

  cout << "Sorted list: ";
  L->sort();
  L->print();

  L->~LinkedList();

  cout << "--------------------------------------------------------\n";
}

void test4(vector<int> nums1, vector<int> nums2) {
  auto *L1 = new LinkedList(nums1);
  auto *L2 = new LinkedList(nums2);

  cout << "List1: ";
  L1->print();

  cout << "List2: ";
  L2->print();

  cout << "Addition: ";
  auto *L3 = L1->getSum(L2);
  L3->print();

  L1->~LinkedList();
  L2->~LinkedList();

  cout << "--------------------------------------------------------\n";
}

int main() {
  test({1, 2, 3, 4, 5});
  test2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {2, 4, 8, 9});
  test3({2, 1, 2, 1, 1, 2, 0, 1, 0});
  test4({1}, {9, 9, 9, 9});
  test4({9, 9, 9, 9}, {1});
  test4({9, 9, 9, 1}, {9});
  test4({9, 8, 7, 6}, {1, 2, 3, 4});
  test4({1, 2, 3}, {3, 2, 1});
  test4({9}, {0, 0, 0, 0});
}
