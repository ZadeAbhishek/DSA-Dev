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


#include <iostream>
#include <vector>

class Solution {
public:
    // Function to find the index where the target should be inserted in the sorted array
    int searchInsert(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        // Binary search algorithm
        while (start <= end) {
            // Check if there is only one element remaining in the search space
            if (start == end) {
                // Check if the target is equal to the remaining element
                if (nums[start] == target) return start;
                // Check if the target should be inserted before the remaining element
                else if (nums[start] > target) return start;
                // The target should be inserted after the remaining element
                else return start + 1;
            }

            int mid = (start + end) / 2; // Calculate the middle index

            // Check if the middle element is less than the target
            if (nums[mid] < target) start = mid + 1; // Update the start index to search in the right half
            else end = mid; // Update the end index to search in the left half
        }

        return start + 1; // Return the index where the target should be inserted
    }
};


// Driver function to test the searchInsert function
void testSearchInsert() {
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    int result1 = solution.searchInsert(nums1, target1);
    std::cout << "Test Case 1: Insert " << target1 << " in nums1 at index " << result1 << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    int result2 = solution.searchInsert(nums2, target2);
    std::cout << "Test Case 2: Insert " << target2 << " in nums2 at index " << result2 << std::endl;

    // Test Case 3
    std::vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    int result3 = solution.searchInsert(nums3, target3);
    std::cout << "Test Case 3: Insert " << target3 << " in nums3 at index " << result3 << std::endl;

    // Test Case 4
    std::vector<int> nums4 = {1, 3, 5, 6};
    int target4 = 0;
    int result4 = solution.searchInsert(nums4, target4);
    std::cout << "Test Case 4: Insert " << target4 << " in nums4 at index " << result4 << std::endl;
}

int main() {
    testSearchInsert();
    return 0;
}
