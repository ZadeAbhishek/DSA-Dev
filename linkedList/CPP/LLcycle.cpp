// Floyd’s Cycle-Finding Algorithm 
// fast slow approach 
// 2 pointers 
// "tortoise and the hare algorithm"
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
 //constuctor 
   ListNode(int data){
    this->next = NULL;
    this->val = data;
   }    
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head ==NULL){return false;}
        ListNode* fast;
        ListNode* slow;
        fast = slow = head;
        while(fast->next !=NULL  && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
            }
        }
        return false;

    }
};


ListNode* createNodeAtHead(ListNode* &head,ListNode* &tail, int data){ // &head is reference and it is used so that copy is not created
    ListNode* temp = new ListNode(data);
    temp -> next = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    head = temp;
    return tail;
}

class print {
    public:
void printlist(ListNode* n){
    // function for traversal 
    // This will also return if traveal is Success or fail
    if(n!=NULL){
    while(n!=NULL){
        cout<<n->val<<" ";
        n = n->next;
    }
    cout<<endl;
    char s = 's';
return ;
}
}
};


int main(){
    
    int l[]={5,4,3,2,1};
    ListNode* list = NULL;
    list = new ListNode(6);
    ListNode* tail = list;
    ListNode* tail2;
    for(int i=0;i<=4;i++){
     tail2 = createNodeAtHead(list,tail,l[i]);
    }
    tail2->next = list->next;
    print* printer = new print();
   // printer->printlist(list);
   Solution* solve = new Solution();
   bool result = solve->hasCycle(list);
   cout<<result;
}