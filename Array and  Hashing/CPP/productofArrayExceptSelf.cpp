#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) { return nums;}
        int i;
        vector<int> result(nums.size());
        int prev = 1; // since prev is always one
       
       
        for(i=0;i<len;i++){
            //pre Multiplication for curr elements
            result[i] = prev;
            prev = prev*nums[i];
         }
        // multiplying prev with post
        
        int post = 1;
        
        
        
        for(i=len-1;i>=0;i--){
            int temp = result[i];
            result[i] = post* temp;
            //sult[i] = post * temp;
            post *= nums[i]; 
        }
       
        return result;
        
    }
};
int main (){
     vector<int>  s = {1,2,3,4};
    Solution* solve = new Solution();    
    vector<int> result = solve->productExceptSelf(s);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
