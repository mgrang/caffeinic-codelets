#include <iostream>

using namespace std;

class LinkedList {
private:
  class Node;

  Node *head;
  Node *tail;
  int numNodes;

  class Node {
  public:
    int data;
    Node *next;
    LinkedList *list;

    Node(int d, LinkedList *L) : data(d), next(nullptr), list(L) {
      if (!list->head)
        list->head = this;

      if (list->tail)
        list->tail->next = this;
      list->tail = this;

      ++list->numNodes;
    }

    void erase() {
      if (this) {
        delete this;
        --list->numNodes;
      }
    }
  };

private:
  void reverseHelper(Node *curr, Node *prev) {
    head = curr;

    if (!curr->next) {
      curr->next = prev;
      return;
    }

    auto *nextNode = curr->next;
    auto *rest = nextNode->next;

    nextNode->next = curr;
    curr->next = prev;

    reverseHelper(rest, nextNode);
  }


public:
  LinkedList(vector<int> nums) {
    for (const auto i : nums)
      add(i);
  }

  ~LinkedList() {
    while (head) {
      auto *tmp = head->next;
      head->erase();
      head = tmp;
    }
  }

  void add(int d) {
    new Node(d, this);
  }

  void remove(int d) {
    auto *node = head;

    if (head && head->data == d) {
      head = node->next;
      node->erase();
      return;
    }

    if (tail && tail->data == d) {
      Node *prev;
      while (node != tail) {
        prev = node;
        node = node->next;
      }

      prev->next = nullptr;
      tail = prev;
      node->erase();
      return;
    }

    while (node) {
      if (node->next && node->next->data == d) {
        auto *tmp = node->next;
        node->next = tmp->next;

        if (tmp == tail)
          tail = node->next;

        tmp->erase();
        return;
      }
      node = node->next;
    }
  }

  void remove(Node *node) {
    if (node == head) {
      head = node->next;
      node->erase();
      return;
    }

    auto *curr = head;
    auto *prev = node;

    while (curr && curr != node) {
      prev = curr;
      curr = curr->next;
    }

    prev->next = node->next;
    node->erase();
  }

  int getMid() {
    if (numNodes == 0)
      return -1;
    if (numNodes == 1)
      return head->data;

    auto *fast = head;
    auto *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow->data;
  }

  int getMid2() {
    int count = numNodes / 2;
    auto *node = head;

    while (count) {
      node = node->next;
      --count;
    }

    return node->data;
  }

  void print() {
    auto *node = head;
    while (node) {
      cout << node->data << "->";
      node = node->next;
    }
    cout << "\n";
  }

  void reverse() {
    tail = head;
    reverseHelper(head, nullptr);
  }

  Node *getHead() {
    return head;
  }

  Node *getTail() {
    return tail;
  }

  int getNumNodes() {
    return numNodes;
  }
};
