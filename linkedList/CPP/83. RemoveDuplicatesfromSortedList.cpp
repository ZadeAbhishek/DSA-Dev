/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(-1);
        ListNode* ptr = head;
        while(ptr != nullptr){
            if(ptr->val == prev->val){
                prev->next = ptr->next;
                ptr = ptr->next;
                continue;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};