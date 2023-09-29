#include <iostream>

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int i = 0;
        while(i!=nums.size()){
            if(hash.count(nums[i])){
                ++hash[nums[i]];
            }
            else{
                hash.insert({nums[i],1});
            }
            i++;
        }
          priority_queue<pair<int,int>> y; // heap initiation
          for(auto x:hash){
          pair<int,int> p ;
          p.first = x.second;
          p.second = x.first;
          y.push(p);
          }
       vector<int> result; 
        int m = 0;
        while(m < k){
            result.push_back(y.top().second);
            y.pop();
            m++;
        }
        return result;
    }
};

int main (){
     vector<int>  s = {1,1,1,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    Solution* solve = new Solution();    
    vector<int> result = solve->topKFrequent(s,2);
    for(int i = 0;i<result.size();i++){
            cout<<result[i]<<" ";
        
    }
    cout<<endl;
}