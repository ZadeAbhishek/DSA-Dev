#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        if (root->val == targetSum && !root->left && !root->right) return true;
        return hasPathSum(root->right, targetSum - root->val) || hasPathSum(root->left, targetSum - root->val);
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution solution;

    if (solution.hasPathSum(root, targetSum)) {
        std::cout << "There is a path with sum " << targetSum << " in the binary tree." << std::endl;
    } else {
        std::cout << "There is no path with sum " << targetSum << " in the binary tree." << std::endl;
    }

    // Clean up the memory used by the tree (optional)
    // You may need to implement a function to delete the tree nodes.
    // Cleanup code is not provided here.

    return 0;
}
