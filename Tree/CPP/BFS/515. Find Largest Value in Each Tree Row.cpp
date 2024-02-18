#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// First Solution Class
class Solution1 {
public:
    vector<int> largestValues(TreeNode* root) {
        // bfs traversal
        unordered_map<int,int> maxnode;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int currLevel = curr.first;
            auto currNode = curr.second;
            if(maxnode.count(currLevel)) maxnode[currLevel] = max(maxnode[currLevel],currNode->val);
            else maxnode[currLevel] = currNode->val;

            if(currNode->left != NULL) q.push({currLevel+1,currNode->left});
            if(currNode->right != NULL) q.push({currLevel+1,currNode->right}); 
        }

        vector<int> result;
        for(auto x : maxnode) result.push_back(x.second);
        std::reverse(result.begin(), result.end());
        return result;
    }
};

// Second Solution Class
class Solution2 {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result; // Return an empty vector if the tree is empty
        }
        
        // bfs traversal
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelMax = INT_MIN;
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelMax = max(levelMax, node->val);
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            result.push_back(levelMax);
        }
        
        return result;
    }
};

// Driver Function
int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution1 sol1;
    Solution2 sol2;

    // Test Solution1
    vector<int> result1 = sol1.largestValues(root);
    cout << "Results from Solution1:" << endl;
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    // Test Solution2
    vector<int> result2 = sol2.largestValues(root);
    cout << "Results from Solution2:" << endl;
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
