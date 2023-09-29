#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* low_than_x_head = new ListNode(); // Dummy node for values less than x
        ListNode* high_than_x_head = new ListNode(); // Dummy node for values greater than or equal to x
        ListNode* low = low_than_x_head;
        ListNode* high = high_than_x_head;

        while (head) {
            if (head->val < x) {
                low->next = head;
                low = low->next;
            } else {
                high->next = head;
                high = high->next;
            }
            head = head->next;
        }
        
        high->next = nullptr; // Terminate the high_than_x list
        low->next = high_than_x_head->next; // Connect the low_than_x list to high_than_x list

        ListNode* result = low_than_x_head->next;
        delete low_than_x_head; // Clean up the dummy node
        delete high_than_x_head; // Clean up the dummy node
        
        return result;
    }
};


// Helper function to create a linked list from an array
ListNode* createLinkedListFromArray(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    int arr[] = {1, 4, 3, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* originalList = createLinkedListFromArray(arr, n);
    std::cout << "Original list: ";
    printLinkedList(originalList);

    int x = 3;
    ListNode* partitionedList = solution.partition(originalList, x);
    std::cout << "Partitioned list with x=" << x << ": ";
    printLinkedList(partitionedList);

    // Clean up the allocated memory
    while (partitionedList) {
        ListNode* temp = partitionedList;
        partitionedList = partitionedList->next;
        delete temp;
    }

    return 0;
}
