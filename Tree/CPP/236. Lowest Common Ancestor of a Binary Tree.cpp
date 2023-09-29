#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to find the lowest common ancestor of two nodes in a binary tree.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If the root is NULL, return NULL.
        if (root == NULL) return NULL;

        // If either of the nodes is equal to the root, the root is their common ancestor.
        if (root == p || root == q) return root;

        // Recursively search for the common ancestor in the left and right subtrees.
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        // If one subtree returned NULL, return the other non-NULL subtree.
        if (left == NULL) return right;
        if (right == NULL) return left;

        // If both subtrees returned non-NULL values, then the current root is the LCA.
        return root;
    } 
};

int main() {
    // Constructing a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    // Finding the Lowest Common Ancestor of nodes p and q.
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
