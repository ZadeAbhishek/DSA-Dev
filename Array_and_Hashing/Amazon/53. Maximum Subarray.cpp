class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(auto &x : nums){
            currSum += x;
            maxSum = max(maxSum,currSum);
            currSum = max(currSum,0); // this is what i always forgot 
        }
        return maxSum;
    }
};