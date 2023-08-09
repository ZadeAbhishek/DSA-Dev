/*
*Input: nums = [3,4,5,1,2]
Output: 1

Input: nums = [4,5,6,7,0,1,2]
Output: 0


*/

#include <iostream>
#include <vector>
using namespace std;


// optimised TC O(logn)
class Solution {
public:
    // Function to find the minimum element in a rotated sorted array using binary search
    int findMin(vector<int>& nums) {
        int low = 0; 
        int high = nums.size() - 1;
        int minElement = 1e9; // Set a large initial value for the minimum element

        // Binary search loop
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the middle index

            // Check if the middle element is greater than or equal to the leftmost element
            if (nums[mid] >= nums[low]) {
                minElement = min(minElement, nums[low]); // Update the minimum element with the leftmost element
                low = mid + 1; // Search in the right half of the array
            } else {
                minElement = min(minElement, nums[mid]); // Update the minimum element with the middle element
                high = mid - 1; // Search in the left half of the array
            }
        }

        return minElement; // Return the minimum element in the rotated sorted array
    }
};

// Definition of Solution2 class
class Solution2 {
public:
    // Function to find the minimum element in a rotated sorted array using linear search
    int findMin(vector<int>& nums) {
        int i, a, f = 0;
        for (int i = 0; i < nums.size() - 1 && f == 0; i++) {
            if (nums[i] > nums[i + 1]) {
                f = 1; // Set the flag to 1 to indicate that a rotation point is found
                a = nums[i + 1]; // Store the element after the rotation point as the minimum element
            }
        }

        if (f == 0) {
            a = nums[0]; // If no rotation point is found, set the first element as the minimum element
        }
        return a; // Return the minimum element in the rotated sorted array
    }
};

// Driver function to test the findMin function
void testFindMin() {
    Solution2 solution; // Create an instance of Solution2 class

    // Test Case 1
    std::vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int result1 = solution.findMin(nums1);
    std::cout << "Test Case 1: Minimum element in nums1 is " << result1 << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {3, 4, 5, 1, 2};
    int result2 = solution.findMin(nums2);
    std::cout << "Test Case 2: Minimum element in nums2 is " << result2 << std::endl;

    // Test Case 3
    std::vector<int> nums3 = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 1, 2, 3};
    int result3 = solution.findMin(nums3);
    std::cout << "Test Case 3: Minimum element in nums3 is " << result3 << std::endl;
}

// ... (rest of the code including main function)

