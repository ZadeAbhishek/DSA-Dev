class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {        
        for(auto i = 1 ; i < size(nums) ; i++) nums[i] += nums[i - 1];
           return nums; 
    }
};

/*
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
*/