#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
#include <queue>
using namespace std;


//top down approch
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> curr;
//         vector<vector<int>> result;
//         dfs(nums, 0, curr, result);
//         return result;
//     }
// private:
//     void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result) {
//         result.push_back(curr);
//         for (int i = start; i < nums.size(); i++) {
//             curr.push_back(nums[i]);
//             dfs(nums, i + 1, curr, result);
//             curr.pop_back();
//         }
//     }
// };

//bottom up approch 
class Solution {
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        sets(nums,0,curr,result);
        return result;
    }

    vector<vector<int>> sets(vector<int> &nums, int start, vector<int> &curr, vector<vector<int>> &result ){
        if(start == nums.size()){
            result.push_back(curr);
            return result;
         }
         curr.push_back(nums[start]);
         sets(nums,start+1,curr,result);
         curr.pop_back();
         sets(nums,start+1,curr,result);
         return result;
    } 
};

int main (){
    vector<int>  s = {1,2,3,4};
    Solution* solve = new Solution();    
    vector<vector<int>> result = solve->subsets(s);
    cout<<"[ ";
    for(auto i = 0;i<result.size();i++){
            cout<<"[ ";
        for(auto j = 0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
         cout<<"]";
    }
    cout<<" ]";
    cout<<endl;
}