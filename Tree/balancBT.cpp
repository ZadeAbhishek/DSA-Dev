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
public:
     int maxH(TreeNode* root,bool &res){
         if(root == NULL) return 0;
         int l = maxH(root->left,res);
         int r = maxH(root->right,res);
         int h = abs(l - r);
         //cout<<h<<"\n";
         if( h > 1 ){
             res = false;
         }
         return 1+ max(l,r);
     }
    bool isBalanced(TreeNode* root) {
         if(root == NULL) return true;
         bool h = true;
         maxH(root,h);
         return h;
    }
};

int main(){
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
    bool ptr = solve->isBalanced(root);
    cout<<ptr; 

}