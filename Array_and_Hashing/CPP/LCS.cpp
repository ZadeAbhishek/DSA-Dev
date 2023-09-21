#include <iostream>

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int largest= 0;
        unordered_map<int,int> table;
        
        // idea is to add all element to set 
        for(auto i = 0;i < nums.size(); i++){
             if(largest <= nums[i]){
                largest = nums[i];
             }
            table.insert({nums[i],nums[i]});
        }
        priority_queue<int> q;
        int max = 0;
        for(auto i = 0;i < nums.size(); i++){
             if(!table.count(nums[i]-1)){
                int temp = nums[i];
                max = 1;
                while(table.count(temp+1)){
                  max++;
                  temp++;
                }
                q.push(max);
                max = 0;
             }
             

        }
        return q.top();
    }




    int longestConsecutive_apporch_2(vector<int>& nums) {
        // sort will take nlogn 
        // using set will also work 
        set<int> hash;

        int maxx = INT_MIN;

        for(auto &x : nums) hash.insert(x);

        for(auto &x : nums){
            int count = 1;
            while(hash.find(x+1) != hash.end()){
                 count++;
                 x++;
            }
            maxx = max(count,maxx);
        }

        return maxx;
    }

};



int main (){
     vector<int>  s = {0,3,7,2,5,8,4,6,0,1};
    Solution* solve = new Solution();    
    int result = solve->longestConsecutive_apporch_2(s);
    cout<<result<<endl;
}