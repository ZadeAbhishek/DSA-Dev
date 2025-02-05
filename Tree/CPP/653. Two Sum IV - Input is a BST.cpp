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


// More optimised Appooch 

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;
    
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }
    
    // Returns the next element in the iteration
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        if (!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }
    
    // Checks if there are more elements to iterate
    bool hasNext() {
        return !st.empty();
    }
    
private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if (!reverse) node = node->left;
            else node = node->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        // Initialize two iterators
        BSTIterator leftIter(root, false);  // In-order (ascending)
        BSTIterator rightIter(root, true);  // Reverse in-order (descending)
        
        int i = leftIter.next();
        int j = rightIter.next();
        
        while (i < j) {  // Ensure that we don't use the same element twice
            long long sum = (long long)i + (long long)j;
            if (sum == k) return true;
            else if (sum < k) {
                if (leftIter.hasNext()) i = leftIter.next();
                else break;
            }
            else {  // sum > k
                if (rightIter.hasNext()) j = rightIter.next();
                else break;
            }
        }
        
        return false;
    }
};