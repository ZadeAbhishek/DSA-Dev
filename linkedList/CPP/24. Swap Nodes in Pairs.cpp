// basically swap alternate node

// without swaping values
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if(!head || !head->next) return head;

       ListNode* dummy = new ListNode();

       ListNode* prev = dummy;
       ListNode* curr = head;

       while(curr && curr->next){
           prev->next = curr->next; // dummy -> 2
           curr->next = prev->next->next; // 1 -> 2
           prev->next->next = curr; // 2 -> 1

           prev = curr;
           curr = curr->next;
       }
       return dummy->next;
    }
};

// recussive solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode * temp = head->next->next;
        ListNode * newHead = head->next;

        head->next->next = head;
        head->next =  swapPairs(temp);

        return newHead;
    }
};


// with swaping (there might be condition in exam dont swap value if that is availabe use this)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            swap(slow->val, fast->val);
            slow = fast->next;
            fast = slow->next;
        }
        if(fast != NULL)swap(slow->val, fast->val);
        return head;
    }
};