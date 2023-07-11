// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
  public: Node * flatten(Node * head) {
    if (head == NULL) return head;
    Node * d = new Node();
    Node * dummy = d;
    stack < Node * > q;
    q.push(head);
    while (!q.empty()) {
      Node * temp = q.top();
      q.pop();
      if (temp) {
        dummy -> next = temp;
        temp -> prev = dummy;
      }

      if (temp -> next) {
        q.push(temp -> next);
      }

      if (temp -> child) {
        q.push(temp -> child);
        temp -> child = NULL;
      }
      dummy = temp;
    }
    dummy = d -> next;
    dummy -> prev = NULL;
    return dummy;
  }
};