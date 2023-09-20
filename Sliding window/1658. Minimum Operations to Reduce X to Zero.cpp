// brute force
class Solution {
    void solve(vector<int>& nums, int x , int start , int end ,int &minOperations, int steps){

        // edges case
        if(start > nums.size()-1 || end < 0) return;

        // base case
        if(x == 0){
        minOperations = min(minOperations,steps);
        return;
        }

        if(nums[start] <= x) solve(nums,x - nums[start],start+1,end,minOperations, steps+1);

        if(nums[end] <= x) solve(nums,x - nums[end],start,end-1,minOperations, steps+1);

        return;

    }
public:
    int minOperations(vector<int>& nums, int x) {
        // recurrtion would work
        int minOperations = INT_MAX;
        solve(nums,x,0,nums.size()-1, minOperations, 0);
        return minOperations == INT_MAX?-1:minOperations;
    }
};


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // sliding window protocol
        int total = accumulate(nums.begin(),nums.end(),0);
        int target = total - x;
        int currSum = 0;
        int maxLenght = -1;
        int right = 0;
        int left = 0;
        int lenght = nums.size();
        for(;right < lenght ; right++){
            currSum += nums[right];
            while(currSum > target && left <= right){
                currSum -= nums[left];
                left++;
            }
            if(currSum == target) maxLenght = max(maxLenght,(right-left)+1);
        }
        return maxLenght == -1?-1:lenght - maxLenght;
    }
};