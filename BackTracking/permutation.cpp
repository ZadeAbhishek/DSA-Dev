#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates) {
            vector<vector<int>> result;
            vector<int> no;
            Sum(candidates,0,result,0,no);
        return result;
    }
    
    void Sum(vector<int>& candidates, int target,int i,vector<vector<int>> &result,int sum,vector<int> &no) {
        cout<<"sum:"<<sum<<endl;
           if(){
               result.push_back(no);
               return;
           }
           no.push_back(candidates[i]);
           for(int x = 0 ; x < candidates.size(); x++){
             if(x == i){ continue;}
             Sum(candidates,target,x,result,sum + candidates[x],no);
             no.pop_back();
           }
           
           
        
    return;
    }
};

int main (){
     vector<int>  s = {1,2,3};
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