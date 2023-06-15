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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        queue<TreeNode*> q;
        int level = 0;
        int res = -1;

        q.push(root);
        while(!q.empty()){
           level++;
           int temp = 0; 
           int s = q.size(); 
           for(auto i = 0 ; i < s;i++){
            
            TreeNode* ptr = q.front();
            q.pop();

            temp += ptr->val;
            
            if(ptr->left) q.push(ptr->left);
            if(ptr->right) q.push(ptr->right);

          }

          if(maxSum < temp) maxSum = temp, res = level;
        }
        return res;
    }

};