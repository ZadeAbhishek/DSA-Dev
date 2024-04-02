#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class
class Solution {
public:
    // updated approch would be instead of using array just start slow and fast;
    int pairSum(ListNode* head) {
        // go to half and add the half
        ListNode* fast = head;
        ListNode* slow = head;
        vector<int> sums;
        int maxSum = INT_MIN;
        while(fast != NULL && fast->next != NULL){
           sums.push_back(slow->val);
           fast = fast->next->next;
           slow = slow->next;
        }
        while(slow != NULL){
            maxSum = std::max(maxSum,(sums.back() + slow->val));
            sums.pop_back();
            slow = slow->next;
        }
        return maxSum;
    }
};

// Driver function
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(9);

    // Create an instance of the Solution class
    Solution solution;

    // Call the pairSum function and print the result
    cout << "Maximum Pair Sum: " << solution.pairSum(head) << endl;

    // Free memory allocated for the linked list
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
