#include <iostream>
#include <vector>

class Solution {
public:
    // Binary search function to find the target in the sorted array
    int search(std::vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        
        while (low <= high) {
            // Calculate the middle index
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid; // Target found at mid index
            } else if (target > nums[mid]) {
                low = mid + 1; // Search in the right half of the array
            } else {
                high = mid - 1; // Search in the left half of the array
            }
        }
        
        return -1; // Target not found
    }
};

int main() {
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int result1 = solution.search(nums1, target1);
    std::cout << "Test Case 1: Target " << target1 << " found at index " << result1 << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    int result2 = solution.search(nums2, target2);
    std::cout << "Test Case 2: Target " << target2 << " found at index " << result2 << std::endl;

    // Test Case 3
    std::vector<int> nums3 = {2, 5};
    int target3 = 5;
    int result3 = solution.search(nums3, target3);
    std::cout << "Test Case 3: Target " << target3 << " found at index " << result3 << std::endl;

    return 0;
}