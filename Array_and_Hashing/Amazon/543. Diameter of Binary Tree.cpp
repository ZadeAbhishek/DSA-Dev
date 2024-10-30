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
    int solve(TreeNode* root, int &maxDiameter){
         if(root == NULL) return 0;
         int left = solve(root->left,maxDiameter);
         int right = solve(root->right,maxDiameter);
         maxDiameter = max(maxDiameter,left+right);
         return max(left,right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = INT_MIN;
        solve(root,maxDiameter);
        return maxDiameter;
        
    }
};