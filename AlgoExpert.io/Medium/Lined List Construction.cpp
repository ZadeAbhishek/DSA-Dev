#include <iostream>
using namespace std;

class Node {
 public:
  int value;
  Node* prev;
  Node* next;

  Node(int value);
};

class DoublyLinkedList {
 public:
  Node* head;
  Node* tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void setHead(Node* node) {
    if (head == nullptr) {
      head = node;
      tail = node;
    } else {
      insertBefore(head, node);
    }
  }

  void setTail(Node* node) {
    if (head == nullptr) {
      setHead(node);
    } else {
      insertAfter(tail, node);
    }
  }

  void insertBefore(Node* node, Node* nodeToInsert) {
    if (nodeToInsert == head && nodeToInsert == tail) return;
    remove(nodeToInsert); 

    nodeToInsert->next = node;
    nodeToInsert->prev = node->prev;

    if (node->prev == nullptr) { 
      head = nodeToInsert;
    } else {
      node->prev->next = nodeToInsert;
    }

    node->prev = nodeToInsert;
  }

  void insertAfter(Node* node, Node* nodeToInsert) {
    if (nodeToInsert == head && nodeToInsert == tail) return;
    remove(nodeToInsert);

    nodeToInsert->prev = node;
    nodeToInsert->next = node->next;

    if (node->next == nullptr) { 
      tail = nodeToInsert;
    } else {
      node->next->prev = nodeToInsert;
    }

    node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node* nodeToInsert) {
    if (position == 1) {
      setHead(nodeToInsert);
      return;
    }

    Node* node = head;
    int currentNode = 1;

    while (node != nullptr && currentNode != position) {
      node = node->next;
      currentNode++;
    }

    if (node != nullptr) {
      insertBefore(node, nodeToInsert);
    } else {
      setTail(nodeToInsert);
    }
  }

  void removeNodesWithValue(int value) {
    Node* node = head;
    while (node != nullptr) {
      Node* next = node->next;
      if (node->value == value) remove(node);
      node = next;
    }
  }

  void remove(Node* node) {
    if (node == head) head = node->next;
    if (node == tail) tail = node->prev;

    if (node->prev != nullptr) node->prev->next = node->next;
    if (node->next != nullptr) node->next->prev = node->prev;

    node->next = nullptr;
    node->prev = nullptr;
  }

  bool containsNodeWithValue(int value) {
    Node* node = head;
    while (node != nullptr) {
      if (node->value == value) return true;
      node = node->next;
    }
    return false;
  }
};