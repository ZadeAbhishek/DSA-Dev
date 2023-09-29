#include <iostream>
using namespace std;

// Define a ListNode class for singly-linked list nodes
class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor to initialize a ListNode with data
    ListNode(int data) {
        this->next = NULL;
        this->val = data;
    }
};

// Define a Solution class to check if a linked list has a cycle
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) {
            return false;
        }
        ListNode* fast;
        ListNode* slow;
        fast = slow = head;

        // Use the "tortoise and the hare" approach with two pointers
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true; // If the fast and slow pointers meet, there is a cycle
            }
        }
        return false; // If the fast pointer reaches the end, there is no cycle
    }
};

// Function to create a new node and add it to the head of a linked list
ListNode* createNodeAtHead(ListNode* &head, ListNode* &tail, int data) {
    ListNode* temp = new ListNode(data);
    temp->next = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    head = temp;
    return tail;
}

// Class for printing linked lists
class print {
public:
    void printlist(ListNode* n) {
        // Function for traversal
        // This will also return if traversal is successful or fail
        if (n != NULL) {
            while (n != NULL) {
                cout << n->val << " ";
                n = n->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int l[] = {5, 4, 3, 2, 1};
    ListNode* list = NULL;
    list = new ListNode(6);
    ListNode* tail = list;
    ListNode* tail2;
    for (int i = 0; i <= 4; i++) {
        tail2 = createNodeAtHead(list, tail, l[i]);
    }
    tail2->next = list->next;
    print* printer = new print();
    Solution* solve = new Solution();
    bool result = solve->hasCycle(list);
    cout << result; // Print whether the linked list has a cycle or not
}
