https://leetcode.com/problems/linked-list-cycle-ii/ 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // retry fast slow method
        
     if(head == NULL) return NULL;
     
     ListNode* slow = head;
     ListNode* fast = head;
        
     while(slow != NULL && fast != NULL)
     {
          slow = slow->next;
          if(fast->next != NULL) fast = fast->next->next;
         
         if(fast == slow){
             slow = head;
             while(slow!=fast)
             {
                 slow = slow->next;
                 if(fast == NULL) return NULL;
                 fast = fast->next;
             }
             
             return fast;
         }
     }
     return NULL;  
    }
};