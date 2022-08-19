#include <iostream>
using namespace std;

// program to learn linked list
class Node {
    public:
    int data;
    Node* next;  // node pointer pointing to next node


    Node(int data){  // constructor
        this->data = data;
        this->next = NULL;
    }
};

char printlist(Node* n){
    // function for traversal 
    // This will also return if traveal is Success or fail
    if(n!=NULL){
    while(n!=NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
    char s = 's';
return s;
    }
    else{
        char f = 'f';
        return f;
    }
}

void createNodeAtHead(Node* &head,Node* &tail, int data){ // &head is reference and it is used so that copy is not created
    Node* temp = new Node(data);
    temp -> next = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    head = temp;
    

}

void InsertNodeAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void InsertAtMiddle(Node* head,int position,int data){
    int  count = 1; 
    // Node* tempPointer = NULL;
    // tempPointer = head;
    while(count != position){
       head = head->next;
       count++;
       }
    Node* temp = new Node(data);
    temp->next =  head->next;
    head ->next = temp;
}


class RecurrsiveSolution {

public:
Node* RecurrsiveMerge(Node* &list1,Node* &list2){
 
 if(list1==NULL) {return list2;}
 if(list2==NULL) {return list1;}
 Node *FinalList;
 if(list1->data < list2->data){
   FinalList = list1;
   
    FinalList->next = RecurrsiveMerge(list1->next,list2);
 }
 else{
    FinalList = list2;
   FinalList->next = RecurrsiveMerge(list1,list2->next);
 }
 return FinalList;
}
};

class solution {
public:
Node* mergeTwoLists(Node* list1, Node* list2) {
      
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1; 
        Node* NewList = new Node(-1);
        Node* ptr = NewList;
        Node* prt1 = NULL;
        Node* prt2 = NULL;
        prt1 = list1;
        prt2 = list2;
       // printNode(ptr);
       

        while(prt1!=NULL && prt2!=NULL){
             if((prt1->data) > (prt2->data)){
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
    
void exchange(Node* &ptr1,Node* &ptr2){
          Node* temp = NULL;
          temp = ptr2->next;
          ptr2->next = ptr1;
          ptr2 = temp;
    }

 void printNode(Node* &node){
    if(node == NULL || node->next == NULL){ cout<<"NULL"<<endl;
    return;} 
    
     cout<<node->data<<"->"<<node->next->data<<endl;
     cout<<"-------------------------------------"<<endl;
 }   
};

 void printNode(Node* &node){
     if(node->next == NULL) return;
     cout<<node->data<<"->"<<node->next->data<<endl;
 }   
 int main (){

    Node* head = NULL;
    Node* tail = NULL;
    Node* tail2 = NULL;
    Node* NullPointer = NULL;

    Node* list2 = NULL;
    list2 = new Node(6);
    tail2 = list2;
    createNodeAtHead(list2,tail2,5);
    createNodeAtHead(list2,tail2,4);
    createNodeAtHead(list2,tail2,3);
    createNodeAtHead(list2,tail2,1);

    //Node* one = NULL;
    //Node* two = NULL;
    head = new Node(5);  // alocating node in heap
    tail = head;
    printNode(head);
    createNodeAtHead(head,tail,4);
    createNodeAtHead(head,tail,2);
    createNodeAtHead(head,tail,1);
    
    //one = new Node(1);
    //two = new Node(2);

    
    
char response;
response = printlist(head);

response = printlist(list2);



solution* solve = new solution();
response = printlist(solve->mergeTwoLists(head,list2));

RecurrsiveSolution* resolve = new RecurrsiveSolution();
response = printlist(resolve->RecurrsiveMerge(head,list2));
if(response == 's'){
    cout<<"Success!";
}
else{
    cout<<"Try Something  Else!";
}
    return 0;
}   