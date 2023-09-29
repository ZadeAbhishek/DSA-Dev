class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right) return head;

        // Create a dummy node to simplify handling the edge case when left == 1.
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move 'prev' to the node just before the left position.
        for(int i = 0 ; i < left - 1 ; i++) prev = prev->next;

        // 'curr' will be the current node we are working with.
        ListNode* curr = prev->next;

        // Reverse the sub-list from 'left' to 'right'.
        for(int i = 0 ; i < right - left ; i++){
            // 'temp' is used to keep track of the next node to be reversed.
            ListNode* temp = curr->next;
            // Adjust the pointers to reverse the current node.
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        // Update the 'head' pointer to the new head after reversal.
        head = dummy->next;

        // Delete the dummy node to free up memory.
        delete dummy;

        // Return the updated head of the reversed list.
        return head;
    }
};
