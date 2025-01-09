class BSTIterator {
    stack<TreeNode*> st;
    //##Stack
    // Helper function to push all left nodes onto the stack
    void storeLeft(TreeNode* start) {
        while (start != nullptr) {
            st.push(start);
            start = start->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        storeLeft(root);
    }
    
    int next() {
        // Pop the top node (next smallest element)
        auto tempNode = st.top();
        st.pop();
        // If the popped node has a right subtree, process its left descendants
        if (tempNode->right != nullptr) {
            storeLeft(tempNode->right);
        }
        return tempNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */