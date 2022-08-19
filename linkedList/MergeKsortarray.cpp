#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class ListNode {
    public:
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        ListNode* Merged = NULL;
        int index=0;
        while(index!=len){
            ListNode* l1 = lists[index];
            if(index+1!=len){
            ListNode* l2 = lists[index+1];
            Merged = mergeTwoLists(l1,l2);
            lists[index+1]= Merged;
            }
            else
            {
                return l1; 
            }
            index++;
        }
        return Merged;
    }
    ListNode* recursiveSort(vector<ListNode*> &list){
         if(list.empty()){return NULL;}
           int low = 0;
           int high = list.size()-1;
           ListNode* head = NULL;
           head = mergeSort(list,low,high);
           return head;
    }
    ListNode* mergeSort(vector<ListNode*> &lis,int l,int h){
        int m = (l+h)/2;
         //cout<<"Low-->"<<l<<" "<<"Mid-->"<<m<<" "<<"High"<<"High-->"<<h<<endl;
        if(l == h ){ 
            return lis[l];}
        ListNode* list1 = mergeSort(lis,l,m);
        ListNode* list2 = mergeSort(lis,m+1,h);
        ListNode* head = mergeTwoLists(list1,list2);
        return head;

    }
    
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       // cout<<list2->val<<endl;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1; 
        ListNode* NewList = new ListNode(-1);
        ListNode* ptr = NewList;
        ListNode* prt1 = NULL;
        ListNode* prt2 = NULL;
        prt1 = list1;
        prt2 = list2;
       // printNode(ptr);
       

        while(prt1!=NULL && prt2!=NULL){
             if((prt1->val) > (prt2->val)){
            ptr->next=prt2;
            prt2 = prt2->next;
           // printNode(ptr);
            }
        else {
            ptr->next = prt1;
            prt1 = prt1->next;
           // printNode(ptr);
        }
        ptr = ptr->next;
        
    }
    //cout<<"END OF LOOP"<<endl;
   // printNode(prt1);
    if(prt1 == NULL){ ptr->next = prt2;}
    if(prt2 == NULL){ ptr->next = prt1;}

    return NewList->next;
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
int main(){
    
    int l[]={4,1};
    ListNode* list1 = NULL;
    list1 = new ListNode(5);
    ListNode* tail = list1;
    for(int i=0;i<=1;i++){
    createNodeAtHead(list1,tail,l[i]);
    }
     int m[]={3,1};
    ListNode* list2 = NULL;
    list2 = new ListNode(4);
    ListNode* tail2 = list2;
    for(int i=0;i<=1;i++){
    createNodeAtHead(list2,tail2,m[i]);
    }
     int n[]={2};
    ListNode* list3 = NULL;
    list3 = new ListNode(6);
    ListNode* tail3 = list3;
    for(int i=0;i<=0;i++){
    createNodeAtHead(list3,tail3,n[i]);
    }
    print* printer = new print();
    printer->printlist(list1);
    printer->printlist(list2);
    printer->printlist(list3);
    vector<ListNode*> nodeList;
    nodeList.push_back(list1);
    nodeList.push_back(list2);
    nodeList.push_back(list3);
    Solution* solve = new Solution();
    // ListNode* merNode =  solve->mergeKLists(nodeList);
    // printer->printlist(merNode);
    ListNode* mer =  solve->recursiveSort(nodeList);
    printer->printlist(mer);

}