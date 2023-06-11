#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> no;
            Sum(candidates,target,0,result,0,no);
        return result;
    }
    
    void Sum(vector<int>& candidates, int target,int i,vector<vector<int>> &result,int sum,vector<int> &no) {
        cout<<"sum:"<<sum<<endl;
        if(sum > target){
               return;
           }
           if(sum == target){
               result.push_back(no);
               return;
           }
           for(int x = i ; x < candidates.size(); x++){
             no.push_back(candidates[x]);
             Sum(candidates,target,x,result,sum + candidates[x],no);
             no.pop_back();
           }
           
           
        
    return;
    }
};

int main (){
     vector<int>  s = {2,3,6,7};
    Solution* solve = new Solution();    
    vector<vector<int>> result = solve->combinationSum(s,7);
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