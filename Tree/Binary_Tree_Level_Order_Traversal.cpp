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

   
public:
    
    int heightT(TreeNode* root){
        if(root == NULL) return 0;
        
        int l = heightT(root->left);
        int r = heightT(root->right);
        
        return 1 + (l > r ? l : r);
    }
    vector<vector<int>> levelOrder(TreeNode* root, int level,vector<vector<int>> &res) {
        
        if(root == NULL) return res;
        res[level].push_back(root->val);
        levelOrder(root->left,level + 1,res);
        levelOrder(root->right,level + 1,res);
        
        return res;
        
    }
    vector<vector<int>> levelOrder(TreeNode* root, int level = 0) {
        int h = heightT(root);
        vector<vector<int>> res(h);
        levelOrder(root,0,res);
        return res;
    }
};