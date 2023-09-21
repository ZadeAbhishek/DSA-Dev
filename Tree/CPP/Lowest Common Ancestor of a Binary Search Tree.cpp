/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          // we know for sure if p < root then it lies left side and if q lies to right then there common ancestor is root 
        
        if(p->val <= root->val && q->val >= root->val) return root;
        else if(p->val >= root->val && q->val <= root->val) return root;
        else if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right,p,q);
        else if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left,p,q);
        else return NULL;
    }
};