class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // find element using binary search
        int lb = 0;
        int ub = nums.size()-1;
        int found = -1;
        while(lb <= ub){
            int mid = ( ub + lb ) / 2;
            if(nums[mid] == target) { found = mid; break;}
            if(nums[mid] < target) lb = mid+1;
            else ub = mid-1;
        }
        // now we have found one element we need to find next elements it might next or prev in line     
        if(found != -1){
            // search of left index 
            int start = found;
            while(start > 0 && nums[start -1] == target) start--;
            int end = found;
            while(end < nums.size()-1&& nums[end + 1] == target) end++;
            return {start,end};
        }
        return {-1,-1};
    }
};