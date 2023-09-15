#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0; // Handle the case of an empty tree.

        int maxSum = -1e9;
        int level = 0;
        int res = -1;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            level++;
            int temp = 0;
            int s = q.size();

            for (int i = 0; i < s; i++) {
                TreeNode* ptr = q.front();
                q.pop();

                temp += ptr->val;

                if (ptr->left) q.push(ptr->left);
                if (ptr->right) q.push(ptr->right);
            }

            if (maxSum < temp) {
                maxSum = temp;
                res = level;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    int maxLevel = solution.maxLevelSum(root);

    std::cout << "Level with maximum sum: " << maxLevel << std::endl;

    // Clean up the dynamically allocated tree nodes (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
