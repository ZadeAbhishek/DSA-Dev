#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Recursive function to find the maximum amount that can be robbed from the subtree rooted at 'root'
    int rob(TreeNode* root, bool take) {
        // Base case: if the node is NULL, return 0
        if (root == NULL) return 0;

        int take_curr_home = INT_MIN, dont_take = INT_MIN;

        // If we can take from this node, calculate the maximum amount by considering or not considering this node
        if (take) {
            take_curr_home = root->val + rob(root->left, false) + rob(root->right, false);
        }

        // Calculate the maximum amount by considering the child nodes
        dont_take = rob(root->left, true) + rob(root->right, true);

        // Return the maximum of the two cases
        return max(take_curr_home, dont_take);
    }

    // Wrapper function to start the recursion with 'take' set to true
    int rob(TreeNode* root) {
        bool take = true;
        return rob(root, take);
    }
};

class Solution2 {
public:
    // Recursive function with memoization using 'dp' map to find the maximum amount that can be robbed
    int rob(TreeNode* root, bool take, map<pair<TreeNode*, bool>, int>& dp) {
        // Base case: if the node is NULL, return 0
        if (root == NULL) return 0;

        // Check if the result for the current node and 'take' value is already in 'dp'
        if (dp.count({root, take})) return dp[{root, take}]; 

        int take_curr_home = INT_MIN, dont_take = INT_MIN;

        // If we can take from this node, calculate the maximum amount by considering or not considering this node
        if (take) {
            take_curr_home = root->val + rob(root->left, false, dp) + rob(root->right, false, dp);
        }

        // Calculate the maximum amount by considering the child nodes
        dont_take = rob(root->left, true, dp) + rob(root->right, true, dp);

        // Memoize the result and return
        return dp[{root, take}] = max(take_curr_home, dont_take);
    }

    // Wrapper function to start the recursion with 'take' set to true and use memoization
    int rob(TreeNode* root) {
        bool take = true;
        map<pair<TreeNode*, bool>, int> dp; // Memoization map
        return max(rob(root, true, dp), rob(root, false, dp));
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    // Create instances of the Solution classes
    Solution solution;
    Solution2 solution2;

    // Call the rob function for both classes
    int result1 = solution.rob(root);
    int result2 = solution2.rob(root);

    // Display the results
    cout << "Result from Solution class: " << result1 << endl;
    cout << "Result from Solution2 class: " << result2 << endl;

    return 0;
}
