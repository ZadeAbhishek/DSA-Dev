#include<bits/stdc++.h>
using namespace std;


void printVector(vector<int> result){
         for(int i = 0;i<result.size();i++){
         cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
class Solution {
private:
vector<vector<int>> result;
unordered_set<int> table;

int sort(vector<int> t){
    if(t.size() == 0){
        return INT_MIN;
    }
    for(int i = 0 ; i < t.size() ; i++){
     for(int j = 0 ; j < t.size() ; j++){
        if((t[i]>t[j])){
            swap(t[i],t[j]);
        }
     }   
    }
    int x = 0;
    for(auto it : t){
       x += it;
       x *= 10; 
    }
    return x/10;
}
 void solve(vector<int> &nums,int cache[],vector<int> &temp){
    int sortTemp = sort(temp);
    auto it = table.find(sortTemp);
    if(it != table.end()){
       return;
    }
    table.insert(sortTemp);
    printVector(temp);
    result.push_back(temp);
    for(auto i = 0 ; i < nums.size() ; i++){
        if(cache[i] == 0){
           temp.push_back(nums[i]);
           cout<<"i:"<<i<<"PUSH"<<"\n";
           cache[i] = 1;
           solve(nums,cache,temp);
           cout<<"i:"<<i<<"POP"<<"\n";
           cache[i] = 0;
           temp.pop_back();
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
    Solution* solve = new Solution();    
    vector<vector<int>> result = solve->subsetsWithDup(s);
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