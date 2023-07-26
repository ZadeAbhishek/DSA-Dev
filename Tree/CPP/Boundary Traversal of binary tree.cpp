#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    
    vector<int> ans; 
     
    // traverse left part of node
    void traverseLeft(Node * root){
        
        // base case 
        if(root == NULL) return;
        
        // leaf nodes case
        if(root->left == NULL && root->right == NULL) return;
        
        // pusg ans
        ans.push_back(root->data);
        
        // we want to go only left
        if(root->left != NULL)
             traverseLeft(root->left);
        else 
             traverseLeft(root->right);
             
        return;     
    }
    
    
    
        void traverseRight(Node * root){
        
        // base case 
        if(root == NULL) return;
        
        // leaf nodes case
        if(root->left == NULL && root->right == NULL) return;
        
        
        // we want to go only right
        if(root->right != NULL)
             traverseRight(root->right);
        else 
             traverseRight(root->left);
             
         // pusg ans
        ans.push_back(root->data);     
             
        return;     
    }
    
    
    
     void traverseLeaf(Node * root){
        
        // base case 
        if(root == NULL) return;
        
        // leaf nodes case
        if(root->left == NULL && root->right == NULL){
                // pusg ans
               ans.push_back(root->data);
               return;
        }
        
        traverseLeaf(root->left);
        traverseLeaf(root->right);


        return;     
    }



    vector <int> boundary(Node *root)
    {
        //Your code here
        
        if(root == NULL) return ans;
        
        ans.push_back(root->data);
        // print left
        
        traverseLeft(root->left);
        
        // print leaf
        traverseLeaf(root->left);
        traverseLeaf(root->right);
        
        // print right
        traverseRight(root->right);
        
        return ans;
    }
};

int main(){}