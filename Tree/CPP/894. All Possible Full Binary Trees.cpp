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


    unordered_map<int,vector<TreeNode*>> mp; 
      
    vector<TreeNode*> allPossibleFBT(int n) {
       
       vector<TreeNode*> currList;

       if(n%2==0) return {};

       if(n == 1) return { new TreeNode(0)};

       if(mp.count(n)) return mp[n];

       for(int i = 1 ; i < n ; i+=2){
           auto leftVector = allPossibleFBT(i);
           auto rightVector = allPossibleFBT(n-i-1);

           for(auto leftNodes : leftVector){
               for(auto rightNodes : rightVector){
                   currList.push_back(new TreeNode(0,leftNodes,rightNodes));
               }
           }
       }

       return mp[n] = currList;
    }

int main(){

    allPossibleFBT(7);
}