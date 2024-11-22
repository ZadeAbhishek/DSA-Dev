#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        
        vector<int> boundary;
        
        // Add root to boundary if it's not a leaf
        if (!isLeaf(root)) boundary.push_back(root->val);
        
        // Add left boundary
        addLeftBoundary(root->left, boundary);
        
        // Add leaves
        addLeaves(root, boundary);
        
        // Add right boundary (stored in reverse order)
        vector<int> rightBoundary;
        addRightBoundary(root->right, rightBoundary);
        boundary.insert(boundary.end(), rightBoundary.rbegin(), rightBoundary.rend());
        
        return boundary;
    }

private:
    // Check if a node is a leaf
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    // Add left boundary excluding leaves
    void addLeftBoundary(TreeNode* node, vector<int>& boundary) {
        while (node) {
            if (!isLeaf(node)) boundary.push_back(node->val);
            node = (node->left) ? node->left : node->right;
        }
    }

    // Add all leaf nodes
    void addLeaves(TreeNode* node, vector<int>& boundary) {
        if (!node) return;
        if (isLeaf(node)) {
            boundary.push_back(node->val);
            return;
        }
        addLeaves(node->left, boundary);
        addLeaves(node->right, boundary);
    }

    // Add right boundary excluding leaves (in reverse order)
    void addRightBoundary(TreeNode* node, vector<int>& rightBoundary) {
        while (node) {
            if (!isLeaf(node)) rightBoundary.push_back(node->val);
            node = (node->right) ? node->right : node->left;
        }
    }
};

// Helper function to print the boundary
void printBoundary(const vector<int>& boundary) {
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;
}

// Example usage
int main() {
    // Constructing a sample binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //       / \
    //      8   9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    Solution sol;
    vector<int> boundary = sol.boundaryOfBinaryTree(root);
    printBoundary(boundary); // Output: 1 2 4 8 9 6 7 3

    return 0;
}