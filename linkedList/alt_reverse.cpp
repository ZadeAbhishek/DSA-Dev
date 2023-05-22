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

void printlist(Node* n){
    // function for traversal 
    // This will also return if traveal is Success or fail
    if(n!=NULL){
    while(n!=NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}
}

// 1 2 3 4 
// c n t
// c->next = t;
// n->next = curr;
// c = t

Node* alt_Rev(Node * head)
{
    Node* alt_head = head->next;
    Node* curr = head;
    Node* next = curr->next;
    Node* temp = next->next;
    while(temp->next != NULL)
    {
        
        curr->next = temp->next; // 0-->3  2-->5
        next->next = curr; // 1-->0  3-->4
        curr = temp; //       0 == 2 2 == 4
        next = curr->next; // 1 == 3 3 == 5
        temp = next->next; // 2 == 4 4 == NULL
        if(temp == NULL) break;

    }
    curr->next = NULL;
    next->next = curr;
    return alt_head;
}

int main (){
    
    Node * n0 = new Node(0);
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    Node * n7 = new Node(7);
    Node * n8 = new Node(8);
    Node * n9 = new Node(9);
    Node * n10 = new Node(10);
    Node * n11 = new Node(11);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = n11;

    printlist(n0);
    printlist(alt_Rev(n0));

    return 0;
}