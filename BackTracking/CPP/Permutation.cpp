#include<bits/stdc++.h>
using namespace std;


void printVector(vector<int> result){
         for(int i = 0;i<result.size();i++){
         cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
class Solution { 
    vector<int> cache;
    public:
     Solution(int size){
      for(auto i = 0 ; i < size ; i++){
        cache.push_back(0);
      }
    }
    vector<vector<int>> Permutation(vector<int> &list){
        vector<int> temp;
        solve(list,temp);
        return result;
    }
    private:
    vector<vector<int>> result;
    void solve(vector<int> &list,vector<int> &temp){
        if(temp.size() == list.size()){
            result.push_back(temp);
            printVector(temp);
            return;
        }
        for(auto i = 0; i < list.size() ; i++){
            cout<<"i:"<<i<<"\n";
            if(cache[i] == 0){
            temp.push_back(list[i]);
            cache[i] = 1;
            solve(list,temp);
            cout<<"i:"<<i<<"\n";
            cache[i] = 0;
            temp.pop_back();
            
        }
            
    }
    return;
        
    }
};

int main (){
    vector<int>  s = {2,2,3,3};
    Solution* solve = new Solution(s.size());    
    vector<vector<int>> result = solve->Permutation(s);
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