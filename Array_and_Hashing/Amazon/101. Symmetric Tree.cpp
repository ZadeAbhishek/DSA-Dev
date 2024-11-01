// ##Recursive

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
class Solution {
    bool isSymmery(TreeNode* left,TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        return (left->val == right->val) && isSymmery(left->left,right->right) && isSymmery(left->right,right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmery(root->left,root->right);
    }
};