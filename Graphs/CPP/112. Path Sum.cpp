class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        if (root->val == targetSum && !root->left && !root->right) return true;
        return hasPathSum(root->right, targetSum - root->val) || hasPathSum(root->left, targetSum - root->val);
    }
};