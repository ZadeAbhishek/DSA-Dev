#include <iostream>
using namespace std;

  class ListNode {
    public:
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){return l2;}
        if(l2==NULL){return l1;}
        ListNode* Add = new ListNode(-1);
        ListNode* head = Add;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int value = l1->val + l2->val + carry;
            carry = value/10;
            //cout<<value%10;
            ListNode* newNode = new ListNode(value%10);
            Add->next = newNode;
            Add = Add->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l2!=NULL){
        ListNode* newNode = new ListNode((l2->val + carry)%10);
        Add->next = newNode;
        carry =(l2->val + carry)/10;
        Add = Add->next;
        l2 = l2->next;
        }
        while(l1!=NULL){
        ListNode* newNode = new ListNode((l1->val + carry)%10);
        Add->next = newNode;
        carry =(l1->val + carry)/10;
        Add = Add->next;
        l1 = l1->next;
        }
        if(carry!=0){
        ListNode* newNode = new ListNode(carry);
        Add->next = newNode;
        }
        return head->next;
    }
};

void createNodeAtHead(ListNode* &head,ListNode* &tail, int data){ // &head is reference and it is used so that copy is not created
    ListNode* temp = new ListNode(data);
    temp -> next = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    head = temp;
}
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
int main(){
    
    int l[]={9,9,9,9,9,9};
    ListNode* list = NULL;
    list = new ListNode(9);
    ListNode* tail = list;
    for(int i=0;i<6;i++){
    createNodeAtHead(list,tail,l[i]);
    }
    printlist(list);
    int m[]={9,9,9};
    ListNode* list2 = NULL;
    list2 = new ListNode(9);
    ListNode* tail2 = list2;
    for(int i=0;i<3;i++){
    createNodeAtHead(list2,tail2,m[i]);
    }
    printlist(list2);
    Solution* solve = new Solution();
    printlist(solve->addTwoNumbers(list,list2));


}