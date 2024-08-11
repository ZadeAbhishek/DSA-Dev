#include <vector>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
  // Find the total length of the linked list
  int totalLength = 0;
  LinkedList* index = head;
  while (index != nullptr) {
    totalLength++;
    index = index->next;
  }

  // Base case: If k is larger than the list length or less than 1, return
  if (k > totalLength || k < 1) return;

  // Calculate the position of the node to remove (0-indexed)
  int kFromStart = totalLength - k;

  // If the node to remove is the head trafer the head->next data to head and delete next
  // this we are doing becuase we cannot delete head node other list will be lost
  if (kFromStart == 0) {
    LinkedList* nodeToDelete = head->next;
    head->value = head->next->value;
    head->next = head->next->next;
    delete nodeToDelete;
    return;
  }

  // Traverse the list to the node just before the one to be removed
  LinkedList* curr = head;
  for (int i = 0; i < kFromStart - 1; i++) {
    curr = curr->next;
  }

  // Remove the k-th node
  LinkedList* nodeToDelete = curr->next;
  curr->next = curr->next->next;
  delete nodeToDelete;
}
