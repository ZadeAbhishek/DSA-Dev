#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TreeNode{ 
   public: 
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;


    void Traverse(TreeNode* node){
        // normal traveral
    if(node == NULL){
        return;
    }
    cout<<node->val<<" ";    
    Traverse(node->left);
    Traverse(node->right);
    return;
    }
};   

class Solution {
    int count = INT_MIN;
public:
    int daimeter(TreeNode* root, int &d){
       if(root == NULL) return 0;
       int l = daimeter(root->left,d);
       int r = daimeter(root->right,d);
       d = max(d,l+r);
       return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
    int d = 0;
    daimeter(root,d);
    return d;
    }
};

int main (){
   TreeNode* root = new TreeNode();
    TreeNode* node1 = new TreeNode();
    TreeNode* node2 = new TreeNode();
    TreeNode* node3 = new TreeNode();
    TreeNode* node4 = new TreeNode();
    TreeNode* node5 = new TreeNode();
    TreeNode* node6 = new TreeNode();
    root->val = 4;
    node1->val = 2;
    node2->val = 7;
    node3->val = 1;
    node4->val = 3;
    node5->val = 6;
    node6->val = 9;
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    //root->Traverse(root);

   Solution* solve = new Solution();
   cout<<solve->diameterOfBinaryTree(root);

}