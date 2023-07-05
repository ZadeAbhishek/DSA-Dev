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
 * 
 *  Input: root = [3,9,20,null,null,15,7]
 *  Output: [[3],[20,9],[15,7]]
 * 
 * Input: root = [1] 
 * Output: [[1]]
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 */
class Solution {
public:
   int heightT(TreeNode* root){
        if(root == NULL) return 0;
        
        int l = heightT(root->left);
        int r = heightT(root->right);
        
        return 1 + (l > r ? l : r);
    }

    void zigzagTraversal(TreeNode* root, vector<vector<int>> &result, int level){
        if(root == NULL) return;
        // using bfs to solve the this 
        queue<TreeNode*> q;
        q.push(root);
        int rotate = 1;
        while(!q.empty()){
            int n =  q.size();
            vector<int> row(n);
            for(auto i = 0 ; i < n; i++){
            TreeNode* curr = q.front();
            q.pop();
            int index = (rotate)?i:(n-1-i);
            row[index] = curr->val;
            if(curr->left) {q.push(curr->left);}
            if(curr->right) {q.push(curr->right);}

        }
        result.push_back(row);
        rotate = !rotate;
        level++;
    }
    return;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         int level = 0;
         vector<vector<int>> result;
         zigzagTraversal(root,result,level);
         return result;  
    }
};