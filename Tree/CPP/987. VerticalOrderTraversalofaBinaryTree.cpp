

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// read discription ans is easy









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
     
    void preorderTraversal(TreeNode* root,int x,int y,map<int,vector<pair<int,int>>> &hash){
        // base case if root is NULL return 
        if(root == NULL) return;
        if(hash.find(y) == hash.end()) hash.insert({y,{{x,root->val}}});
        else hash[y].push_back({x,root->val});
        preorderTraversal(root->left,x+1,y-1,hash);
        preorderTraversal(root->right,x+1,y+1,hash);
        return;

    } 
   

     // hash<y,{x,val}>
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> hash;
        vector<vector<int>> ans;
        preorderTraversal(root,0,0,hash);
        for(auto curr : hash){
            sort(curr.second.begin(),curr.second.end());
            vector<int> temp;
            for(auto &currPair : curr.second){
                 temp.push_back(currPair.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};