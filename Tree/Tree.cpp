#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    
    void Left(Node* x){
        this->left = x;
    }
    void Right(Node* x){
        this->right = x;
    }
    void Data(int x){
        this->data = x;
    }
    
    void Traverse(Node* node){
        // normal traveral
    if(node->left!=NULL){
        Traverse(node->left);
    }
    cout<<node->data<<"\n"; 
    if(node->right!=NULL){
     //   cout<<node->data<<"\n";
        Traverse(node->right);
    }
    return;
        
    }
};

int main (){
   Node *node = new Node();
   Node* node2 = new Node();
   Node* node3 = new Node();
   node->Data(1);
   node2->Data(2);
   node3->Data(3);
   node->Left(node2);
   node->Right(node3);
   node->Traverse(node);

}