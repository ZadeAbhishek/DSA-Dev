// basically swap alternate node

// without swaping values
#include<bits/stdc++.h>
using namespace std;


struct ListNode{
    ListNode* next;
    int val;
};

class Solution1 {
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
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        
        // base case
        if(head == NULL || head->next == NULL) return head;
       
       // 1 2 3 4 5 NULL

        ListNode * temp = head->next->next;  // temp = 3 part from were we want to start swap
        ListNode * newHead = head->next; // new head
 
        head->next->next = head; // 2 -> 1
        head->next =  swapPairs(temp); // 1 -> (swaped elements)

        return newHead; // return new head
    }
};


// with swaping (there might be condition in exam dont swap value if that is availabe use this)
class Solution3 {
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


void operator<<(ostream &Cout , ListNode* head){
    while(head != NULL){
        Cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
    return;
}

int main(){
    int siz;
    cin>>siz;
    vector<ListNode*> temp(siz);
    temp[0] = new ListNode;
    cin>>temp[0]->val;
    for(int i = 1 ; i < siz ; i++){
        
        temp[i] = new ListNode;
        cin>>temp[i]->val;
        temp[i-1]->next = temp[i];
    }
    temp[siz-1]->next = NULL;
    cout<<temp[0];
    Solution2 *solve = new Solution2();
    cout<<solve->swapPairs(temp[0]);
}