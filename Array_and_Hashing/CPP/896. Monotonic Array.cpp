class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int increasing = true;
        int decreasing = true;
        for(auto i = 1 ; i < nums.size() ; i++) {
            if(nums[i] < nums[i-1]) increasing = false;
            if(nums[i] > nums[i-1]) decreasing = false;
            if(!increasing && !decreasing) return false;
        }
        return true;
    }
};