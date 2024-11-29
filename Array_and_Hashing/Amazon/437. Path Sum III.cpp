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
// ##DFS ##Recursive
class Solution {
    int dfs(TreeNode* root, long sum) { // Use `long` for `sum`
        if (root == nullptr) return 0;

        int count = 0;

        // Check if the current node completes a path
        if (root->val == sum) count++;

        // Recursively explore left and right subtrees
        count += dfs(root->left, sum - root->val); // Avoid overflow
        count += dfs(root->right, sum - root->val);

        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

        // Use `long` to avoid overflow when passing targetSum
        int countFromRoot = dfs(root, static_cast<long>(targetSum));
        int countFromLeft = pathSum(root->left, targetSum);
        int countFromRight = pathSum(root->right, targetSum);

        return countFromRoot + countFromLeft + countFromRight;
    }
};