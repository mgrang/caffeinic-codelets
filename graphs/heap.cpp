#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;

void test(vector<int> nums) {
  MinHeap heap;
  heap.heapify(nums);

  heap.insert(50);

  cout << "Heap: ";
  heap.print();
  cout << "\n";

  cout << "Min element: " << heap.getMin();
  cout << "\n";

  cout << "Sorted heap: ";
  heap.sort();
  cout << "\n";
}

int main() {
  test({33, 7, 2, 1, 100, 19, 36, 3, 17, 25});
}
