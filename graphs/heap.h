#include <iostream>
#include <vector>
using namespace std;

using Vec = vector<int>;

class MinHeap {
private:
  Vec heap;

  void swap(int &a, int &b) {
    auto tmp = a;
    a = b;
    b = tmp;
  }

  void siftUp() {
    int i = heap.size() - 1;
    while (i && i / 2 &&
           heap[i] < heap[i / 2]) {
      swap(heap[i], heap[i / 2]);
      i /= 2;
    }
  }

  void siftDown(int i = 1) {
    int l = 2 * i;
    int r = l + 1;
    int n = heap.size();

    while ((l < n && heap[i] > heap[l]) ||
           (r < n && heap[i] > heap[r])) {
      if (r < n && heap[r] < heap[l])
        l = r;

      swap(heap[i], heap[l]);
      i = l;
      l = 2 * i;
      r = l + 1;
    }
  }

  void removeAt(int i) {
    heap[i] = heap.back();
    heap.pop_back();
    siftDown(i);
  }

public:
  void insert(int k) {
    heap.push_back(k);
    siftUp();
  }

  int getMin() {
    return heap[1];
  }

  int extractMin() {
    int min = getMin();
    removeAt(1);
    return min;
  }

  void removeMin() {
    removeAt(1);
  }

  void heapify(Vec &nums) {
    heap.push_back(-1);
    for (const auto n : nums)
      insert(n);
  }

  void print() {
    for (int i = 1; i < heap.size(); ++i)
      cout << heap[i] << " ";
  }

  void sort() {
    while (heap.size() > 1)
      cout << extractMin() << " ";
  }
};
