/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// Can i assume p will be always left and q will be always right
// root 3 
// return true if p or q is found
// go to step 1 recussively root->left
// return false

// ###DFS
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // basically we can traverse root left and roots right and check for p and q
        // in any root if we return true then we have this root as common ancestor
        // check for P and Q
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if (!left) return right; // If the left subtree is null, return the right subtree.
        if (!right) return left; // If the right subtree is null, return the left subtree.
        return root; 
    }
};