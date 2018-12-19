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

  int getLength(Node *a) {
    auto *node = a;
    int len = 0;
    while (node) {
      node = node->next;
      ++len;
    }
    return len;
  }

public:
  LinkedList() : head(nullptr), tail(nullptr) {};

  LinkedList(const vector<int> &nums) {
    head = nullptr;
    tail = nullptr;

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

  int getNthFromEnd(int n) {
    if (n > numNodes)
      return -1;

    Node *fast = head;
    Node *slow = head;
    while (fast) {
      fast = fast->next;
      if (n == 0)
        slow = slow->next;
      else --n;
    }

    return slow->data;
  }

  bool isPalindrome() {
    vector<int> st;
    auto *node = head;
    while (node) {
      st.push_back(node->data);
      node = node->next;
    }

    node = head;
    while (node) {
      if (node->data != st.back())
        return false;

      st.pop_back();
      node = node->next;
    }

    return true;
  }

  void pairWiseSwap(Node *node) {
    if (!node)
      return;

    if (node == head && node->next)
      head = node->next;

    if (node == tail)
      return;

    auto *nextNode = node->next;
    auto *rest = nextNode->next;

    nextNode->next = node;
    node->next = rest->next ? rest->next : rest;

    pairWiseSwap(rest);
  }

  int getIntersection(Node *a, Node *b) {
    auto len1 = getLength(a);
    auto len2 = getLength(b);

    if (!len1 || !len2)
      return -1;

    auto diff = len1 - len2;
    if (diff < 0) {
      auto *tmp = b;
      b = a;
      a = tmp;
    }

    while (diff) {
      a = a->next;
      --diff;
    }

    while (a && b) {
      if (a == b)
        return a->data;
      a = a->next;
      b = b->next;
    }

    return -1;
  }

  // Note: a and b have to be sorted lists.
  void getCommon(Node *a, Node *b) {
    if (!getLength(a) || !getLength(b))
      return;

    auto *nodeA = a;
    auto *nodeB = b;

    LinkedList *res = new LinkedList();

    while (nodeA && nodeB) {
      while (nodeA && nodeA->data < nodeB->data)
        nodeA = nodeA->next;
      while (nodeB && nodeB->data < nodeA->data)
        nodeB = nodeB->next;
      if (nodeA && nodeB && nodeA->data == nodeB->data) {
        res->add(nodeA->data);
        nodeA = nodeA->next;
        nodeB = nodeB->next;
      }
    }

    auto *nodeRes = res->head;
    while (nodeRes) {
      cout << nodeRes->data << "->";
      nodeRes = nodeRes->next;
    }
    cout << "\n";

    res->~LinkedList();
  }
};
