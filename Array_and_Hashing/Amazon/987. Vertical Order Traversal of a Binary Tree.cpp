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
//##bfs //##BFS
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // {index -> {height -> multiset of values}}
        queue<tuple<TreeNode*, int, int>> q;    // {node, index, height}
        
        q.push({root, 0, 0});
        
        while (!q.empty()) {
            auto [node, index, height] = q.front();
            q.pop();

            // Skip if the node is null
            if (node == nullptr) continue;

            nodes[index][height].insert(node->val); // Store the value in the map

            // Add left and right children to the queue
            q.push({node->left, index - 1, height + 1});
            q.push({node->right, index + 1, height + 1});
        }

        // Construct the result
        vector<vector<int>> result;
        for (auto& [index, levels] : nodes) {
            vector<int> temp;
            for (auto& [height, values] : levels) {
                temp.insert(temp.end(), values.begin(), values.end()); // Append sorted values
            }
            result.push_back(temp);
        }

        return result;
    }
};