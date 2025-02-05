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
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a 
 * binary tree and inorder is the inorder traversal of the same tree, construct and return the 
 * binary tree.
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]

 * 
 * 
 * 
 * 
 */

// BruatForce
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            // edge case
            if(preorder.size() < 1 && inorder.size() < 1) return NULL;
            
            // base case
            if(preorder.size() == 1 && inorder.size() == 1){
                TreeNode* root = new TreeNode(preorder[0]);
                root->left = NULL;
                root->right = NULL;
                return root;
            }

           // original Reccusrende
            TreeNode* root = new TreeNode();
            root->val = preorder[0];
            vector<int> leftInorder;
            vector<int> rightInorder;
            bool toLeft = true;
            for(auto i = 0; i < inorder.size() ; i++){
                if(inorder[i] == root->val){
                    toLeft = false;
                    continue;
                }
                if(toLeft) leftInorder.push_back(inorder[i]);
                if(!toLeft) rightInorder.push_back(inorder[i]);
            }
            vector<int> rightPreorder;
            vector<int> leftPreorder;
            int countLeft = 0;
            for(auto i = 1 ; i < preorder.size() ; i++){
                    if(countLeft < leftInorder.size()) countLeft++,leftPreorder.push_back(preorder[i]);
                    else rightPreorder.push_back(preorder[i]);
            }

            root->left = buildTree(leftPreorder,leftInorder);
            root->right = buildTree(rightPreorder,rightInorder);

            return root;
    }
};