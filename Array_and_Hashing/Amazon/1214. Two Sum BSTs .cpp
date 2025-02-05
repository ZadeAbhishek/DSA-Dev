#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    void traverse(unordered_map<int,int> &hash,TreeNode* root){
        if(root == NULL) return;
        hash[root->val] = root->val;
        traverse(hash,root->left);
        traverse(hash,root->right);
        return;

    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        // Write your code here
        unordered_map<int,int> hash_1;
        unordered_map<int,int> hash_2;
        traverse(hash_1,root1); // T O(N)
        traverse(hash_2,root2); // T O(N)
        for(auto x : hash_1){  
            int sum1 = x.first;
            if(hash_2.count(target - sum1)) return true; // T O(N)
        }
        return false;
    }
};

// Helper function to insert a value into a BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Helper function to print a tree in-order (for debugging purposes)
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// Main function
int main() {
    // Create BST 1
    TreeNode* root1 = nullptr;
    root1 = insert(root1, 2);
    root1 = insert(root1, 1);
    root1 = insert(root1, 4);

    // Create BST 2
    TreeNode* root2 = nullptr;
    root2 = insert(root2, 1);
    root2 = insert(root2, 0);
    root2 = insert(root2, 3);

    // Target sum
    int target = 2;

    // Solution class
    Solution solution;
    bool result = solution.twoSumBSTs(root1, root2, target);

    // Print result
    cout << "Result: " << (result ? "True" : "False") << endl;

    return 0;
}