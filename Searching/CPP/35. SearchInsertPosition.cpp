/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.


Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1

Input: nums = [1,3,5,6], target = 7
Output: 4

*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            if(start == end){
                if(nums[start] == target) return start;
                else if(nums[start] > target) return start;
                else return start+1;
            }
            int mid = (start + end)/2;
            if(nums[mid] <  target) start = mid +1;
            else end = mid;
        }
        return start+1;
    }
};