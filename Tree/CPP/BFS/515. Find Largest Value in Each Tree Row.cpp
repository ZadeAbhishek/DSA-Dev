class Solution {
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

class Solution {
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