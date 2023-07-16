/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;

int main(){}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root == p || root == q) return root;
       
        auto left =  lowestCommonAncestor(root->left,p,q);

        auto right =  lowestCommonAncestor(root->right,p,q);

        if(left == NULL) return right;

        if(right == NULL) return left;

        else return root;
    }
};