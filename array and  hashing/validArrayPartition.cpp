#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
public:
    bool validPartition(list<string> nums) {
        //we can use merge sort here
           int l = nums.size(); // length of array 
           bool result =  partion(nums,0,l); //rescussive call 
           return result;
    }
private:
   bool partion(vector<int>& nums,int x ,int l){
           if(x == l){return true;}
           if(x+1<l && (nums[x] == nums[x+1]) && partion(nums,x+2,l)){ return true;}
           if(x+2<l && (nums[x] == nums[x+1] && nums[x+1] == nums[x+2]) && partion(nums,x+3,l)){return true;}
           if(x+2<l && (nums[x]+1 == nums[x+1] && nums[x+1] == nums[x+2]-1) && partion(nums,x+3,l)){return true;}
           return false; 
           }    
};
int main (){
     list<string>  s[] = {"114114"};
    Solution* solve = new Solution();    
    bool result = solve->validPartition(s);
    cout<<result;
    cout<<endl;
}
