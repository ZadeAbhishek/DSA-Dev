/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the 
 * relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array.
 * 
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        int next = 1;
        
        while(next < nums.size()){
        
        if(nums[curr] == 0 && nums[next] != 0) swap(nums[curr],nums[next]),next++,curr++;
        else if(nums[curr] == 0 && nums[next] == 0) next++;
        else  next++,curr++;

        }
        return;

    }
};