#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find element who is snaller  than its next element
        // Traverse reverse
        int start = -1;
        for(int i = nums.size()-2; i >= 0 ; i--){
               if(nums[i] < nums[i+1]) {start = i;break;}
        }
        // calucate next greater element than start
        if(start != -1){ 
        for(int i = nums.size()-1; i > start ; i--){
               if(nums[i] > nums[start]) {swap(nums[start],nums[i]);break;}
        }
        
        }
        // revers all elements after start ptr
        int end = nums.size()-1;
        start += 1; 
        while(start < end){
            swap(nums[start++],nums[end--]);
        }
        return;
    }
};


// Watch striver video its easy inttion
int main(){}