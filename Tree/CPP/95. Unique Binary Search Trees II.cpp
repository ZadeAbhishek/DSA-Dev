#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    vector<vector<vector<TreeNode*>>> dp;
public:
    vector<TreeNode*> generateTree(int end, int start = 1) {       
        // If start > end, then subtree will be empty so we will directly return null pointer
        if ( start> end)
            return {nullptr};
    
        if(dp[start][end].size() > 0) return dp[start][end];

        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            // generate all possible trees in range [start, i)
            for (auto left : generateTree(i - 1, start)) {
                // generate all possible trees in range (i, end]
                for (auto right : generateTree(end, i + 1))
                    // make new trees with 'i' as the root
                    ans.push_back(new TreeNode(i, left, right));
            }
        }
        return dp[start][end] = ans;
    }

     vector<TreeNode*> generateTrees(int n){
         dp.resize(n+1,vector<vector<TreeNode*>>(n+1));
         return generateTree(n,1);
     }
};

int main(){
    Solution s;
    s.generateTrees(3);
}