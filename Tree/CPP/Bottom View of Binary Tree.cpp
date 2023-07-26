#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   vector<int> ans;
    
    queue<pair<Node*,int>> que;
    
    map<int,int> hash;  // map is to store in ordered way
    
    vector <int> bottomView(Node *root) {
        // Your Code Here //Your code here
        // base case
        if(root == NULL) return ans;
        
        // -2 -1 0 1 2    zero is root
        
        que.push({root,0}); // start with 0
        
        
        while(!que.empty()){
        
            auto currTop = que.front();
            que.pop();
            
            auto currNode = currTop.first;
            
            auto HorizontalDistance = currTop.second;
            
            // check if alrewady any element is add for horizontal distance
            if(hash.find(HorizontalDistance) == hash.end()){
                hash.insert({HorizontalDistance,currNode->data});
            }
            else{
                hash[HorizontalDistance] = currNode->data;
            }
            
            if(currNode->left != NULL)
                que.push({currNode->left,HorizontalDistance-1});
                
            if(currNode->right != NULL)
                que.push({currNode->right,HorizontalDistance+1});
        }
        
        // we don't need to sort since we are using map
        for(auto &x : hash) ans.push_back(x.second);
        
        return ans;
    }
};

int main(){}