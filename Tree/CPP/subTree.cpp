class Solution {
public:
     bool ans = false;
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL &&  q == NULL) return true;
        if(p != NULL && q == NULL) return false;
        if(p == NULL && q != NULL) return false;
        if(p -> val == q->val) {
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(!ans){
        ans = isSameTree(root,subRoot);
        isSubtree(root->left,subRoot);
        isSubtree(root->right,subRoot);
        }
        return ans;
     
        
    }
           
};