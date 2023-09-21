/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.


Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input: nums = [1], target = 0
Output: -1
*/

#include <iostream>
#include <vector>

class Solution {
public:
    // Function to search for the target element in the rotated sorted array
    int search(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        // Check if the array is empty, return -1 if empty
        if (nums.size() == 0) return -1;

        // Check if there is only one element in the array
        if (start == end) {
            if (nums[start] == target) return start; // Return the index if target found, else return -1
            else return -1;
        }

        // Binary search algorithm
        while (start <= end) {
            int mid = (start + end) / 2; // Calculate the middle index

            if (nums[mid] == target) return mid; // Return the index if target found

            // Check if the left half of the array is sorted
            if (nums[start] <= nums[mid]) {
                // Check if the target is within the sorted left half
                if (nums[start] <= target && nums[mid] >= target) {
                    end = mid - 1; // Update the end index to search in the left half
                } else {
                    start = mid + 1; // Update the start index to search in the right half
                }
            } else { // If the right half is sorted
                // Check if the target is within the sorted right half
                if (nums[mid] <= target && nums[end] >= target) {
                    start = mid + 1; // Update the start index to search in the right half
                } else {
                    end = mid - 1; // Update the end index to search in the left half
                }
            }
        }

        return -1; // Return -1 if the target is not found in the array
    }
};

int main() {
    Solution solution;

    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Sample rotated sorted array
    int target = 0; // Target element to search for

    int result = solution.search(nums, target); // Call the search function to find the target

    // Print the result
    if (result != -1) {
        std::cout << "Target element " << target << " found at index: " << result << std::endl;
    } else {
        std::cout << "Target element " << target << " not found in the array." << std::endl;
    }

    return 0;
}

