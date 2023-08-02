#include<bits/stdc++.h>
using namespace std;

void operator<<(ostream &out , vector<vector<int>> result){
     out<<"[";
     for(auto &x : result){
        out<<"[ ";
        for(auto &y : x){
            out<<y<<" ";
        }
        out<<"],";
     }
    out<<"]";
    out<<endl;
}


class Solution2 {
private:
vector<vector<int>> result;
set<vector<int>> table;
 void solve(vector<int> &nums,int cache[],vector<int> &temp){
    
    // sort and check if already present
    vector<int> curr = temp;
    sort(curr.begin(),curr.end());
    auto it = table.find(curr);
    
    if(it != table.end()) return;
      
    // if not push it 
    table.insert(curr);
    result.push_back(curr);
    
    // go for another 
    for(auto i = 0 ; i < nums.size() ; i++){
        if(cache[i] == 0){
           cache[i] = 1;
           temp.push_back(nums[i]);
           solve(nums,cache,temp);
           temp.pop_back();
           cache[i] = 0;
    }
    }
}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            int cache[nums.size()] = {0};
            vector<int> temp;
            solve(nums,cache,temp);
            return result;        
    }
};


int main (){
    vector<int>  s = {0,1,2,3};
    Solution2* solve = new Solution2();    
    vector<vector<int>> result = solve->subsetsWithDup(s);
    cout<<result;
}