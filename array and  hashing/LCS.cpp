#include <iostream>

#include<bits/stdc++.h>

using namespace std;
// brute force
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int largest= 0;
//         unordered_map<int,int> table;
        
//         // idea is to add all element to set and using for loop check if the element is present or not
//         for(auto i = 0;i < nums.size(); i++){
//              if(largest <= nums[i]){
//                 largest = nums[i];
//              }
//             table.insert({nums[i],nums[i]});
//         }
//         priority_queue<int> q;
//         int max = 0;
//         for(auto i = 0;i <= largest; i++){
//             //cout<<nums[i]<<endl;
//             if(table.count(i)){
//              max++;
//             }
//             else{
//                 q.push(max);
//                 max = 0;
//             }
             
//         }
//         return q.top();
//         }
// };

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

};



int main (){
     vector<int>  s = {7,4,10,1,2,3,5};
    Solution* solve = new Solution();    
    int result = solve->longestConsecutive(s);
    cout<<result<<endl;
}