/**
 * Given the root of a binary search tree and an integer k, return true if there exist two elements in 
 * the BST such that their sum is equal to k, or false otherwise.
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
*/

// Brute Force Approch
bool findTarget(TreeNode* root, int k) {

        //base case
        if(root->left == NULL && root->right == NULL && root->val != k) return false;

        // store in hastable
        unordered_map<int,int> node;

        // bfs to traverse 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            node.insert({curr->val,curr->val});
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }

        for(auto x : node){

            int diff = k - x.second;
            if(node.count(diff) && node[diff] != x.second) return true;
        }
        return false;
        
    }

    //optimised DFS
    class Solution {
    unordered_map<int,int> nodeMap;
public:
    bool findTarget(TreeNode* root, int k) {
        
        //base case
        if(root == NULL)  return false;

        int diff = k - root->val;
        
        if(nodeMap.count(diff) && nodeMap[diff] != root->val) return true;
        else nodeMap.insert({root->val,root->val});

        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};