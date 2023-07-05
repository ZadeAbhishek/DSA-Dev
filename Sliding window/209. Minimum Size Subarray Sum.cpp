/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minimun = INT_MAX;
        int i = 0;
        int j = 0;
        int sum = 0;
        while(i < nums.size()){
            sum += nums[i];
            if(sum >= target){
            minimun = min(minimun,i-j+1);

            while(sum>=target){
                sum-=nums[j];
                
                minimun = min(minimun,i-j+1);
                j++;
            }
        }
        i++;
        }
        return (minimun == INT_MAX)?0:minimun;
    }
};