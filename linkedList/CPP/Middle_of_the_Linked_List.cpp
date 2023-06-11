class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // using two pointer method to solve this problem
        
        ListNode* s = head; // this will increment by one
        ListNode* t = head; // this will increment by two
        
        while(t != NULL)
        {
            if(t->next == NULL) return s;
            s = s->next;
            t = t->next->next;
        }
        
        return s;
    }
};