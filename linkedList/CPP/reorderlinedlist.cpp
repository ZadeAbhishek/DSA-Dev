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
    void reorderList(ListNode* head) {
        ListNode* curr;
        ListNode* tail;
        ListNode* pretail;
        ListNode* Postcurr;
        curr = head;
        tail = head;

       
        while (tail->next != NULL && tail->next->next != NULL)
        {
            tail = tail->next;
        }
        while(curr->next->next != NULL && curr->next !=NULL)
        {
            while (tail->next->next != NULL)
        {
            tail = tail->next;
        }
        //  cout<<"Current:"<<curr->val<<endl;
        //  cout<<"PostCur:"<<Postcurr->val<<endl;
        //  cout<<"   tail:"<<tail->val<<endl;
        //  cout<<" ----  -----  -----  ---"<<endl;
         Postcurr = curr->next;
         curr->next = tail->next;
         tail->next->next = Postcurr;
         curr = Postcurr;
         tail->next = NULL;
         tail = curr;
        }
        
        while(head!=NULL){
         cout<<head->val<<" ";
         head = head->next;
        }
        cout<<endl;
        return;
}

void reorder(ListNode* &head){
    //Find Middle
    ListNode* mid = NULL;
    mid = findMiddle(head);

    // divide list into two parts 
    ListNode* reverseList = reverse(mid->next);
    mid->next = NULL;

    //merge Two linked using other pointer
    ListNode* finalList;
    finalList = merge(head,reverseList);
    while(finalList!=NULL){
        cout<<finalList->val<<" ";
        finalList = finalList->next;
        
    }
}

ListNode* merge(ListNode* list1 , ListNode* list2){
    if(list1==NULL){return list2;}
    if(list2==NULL){return list1;}
    ListNode* mergeList= new ListNode(-1);
    ListNode* merge = mergeList;

    while(list1!=NULL && list2!=NULL){
         merge->next = list1;
         list1 = list1->next;
         merge = merge->next;
         merge->next = list2;
         list2 = list2->next;
         merge = merge->next;

    }
     if(list1==NULL){ merge->next = list2;}
    if(list2==NULL){ merge->next = list1;}
    return mergeList->next;

}
//reverse LinkedList 
ListNode* reverse(ListNode* &head){
 // three  pointer to revrse the LL
  ListNode* prev;
  ListNode* curr;
  ListNode* post;

  curr = head;
  prev = NULL;

  while(curr!=NULL){
     post = curr->next;
     curr->next = prev;
     prev =curr;
     curr = post;
  }
  
  return prev;

}
// implementation to find mid in linked list 
ListNode* findMiddle(ListNode* &head){
    ListNode* fast=NULL; 
    ListNode* slow=NULL;
    fast = slow = head;
    while(fast->next !=NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
    
    int l[]={5,4,3,2,1};
    ListNode* list = NULL;
    list = new ListNode(6);
    ListNode* tail = list;
    for(int i=0;i<=4;i++){
    createNodeAtHead(list,tail,l[i]);
    }
    printlist(list);
    Solution* solve = new Solution();
    solve->reorder(list);


}
