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

void deleteNode(Node* &head,Node* &NullPointer,Node* &tail,int position){

    if(position == 0){
        head = head->next;
        return;
    }
    int count = 1;
    NullPointer = head;
    while((count)!=position){
        NullPointer = NullPointer->next;
        count++;
    }
    NullPointer->next = NullPointer->next->next;
    if(NullPointer->next == NULL){
        tail = NullPointer;
    }

}

int main (){

    Node* head = NULL;
    Node* tail = NULL;
    Node* NullPointer = NULL;
    //Node* one = NULL;
    //Node* two = NULL;
    head = new Node(6);  // alocating node in heap
    tail = head;
    //one = new Node(1);
    //two = new Node(2);
    createNodeAtHead(head,tail,45);
    createNodeAtHead(head,tail,0);
    InsertNodeAtEnd(tail,21);
    InsertNodeAtEnd(tail,29);
    InsertNodeAtEnd(tail,96);
    InsertAtMiddle(head,2,54);
    InsertAtMiddle(head,4,69);
    
char response;
response = printlist(head);
createNodeAtHead(head,tail,85);
InsertNodeAtEnd(tail,52);
response = printlist(head);
createNodeAtHead(head,tail,78);
InsertNodeAtEnd(tail,32);
response = printlist(head);

deleteNode(head,NullPointer,tail,5);
response = printlist(head);
deleteNode(head,NullPointer,tail,6);
response = printlist(head);
deleteNode(head,NullPointer,tail,9);
response = printlist(head);
InsertNodeAtEnd(tail,32);
response = printlist(head);
deleteNode(head,NullPointer,tail,0);
response = printlist(head);
deleteNode(head,NullPointer,tail,0);
response = printlist(head);

if(response == 's'){
    cout<<"Success!";
}
else{
    cout<<"Try Something  Else!";
}
    return 0;
} 
