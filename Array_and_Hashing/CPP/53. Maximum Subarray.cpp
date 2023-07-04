class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        // kadens algorithms
        int maxSum = INT_MIN;
        int currentSum = 0;

        for(int &x : nums){
            currentSum += x;

            if(currentSum > maxSum) maxSum = currentSum;
            if(currentSum < 0) currentSum = 0;
        }

        return maxSum;
    }
};