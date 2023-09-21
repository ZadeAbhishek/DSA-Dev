/**
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the intersection of two arrays
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; // Vector to store the intersection elements

        // Sort nums2 in ascending order to perform binary search efficiently
        sort(nums2.begin(), nums2.end()); // Time complexity: O(n*log(n))

        // Create an unordered set from nums1 to efficiently check for element presence
        unordered_set<int> set1(nums1.begin(), nums1.end()); // Time complexity: O(n)

        // Traverse each element in nums2 and check if it is present in nums1
        for (auto x : nums2) { // Time complexity: O(m)
            if (set1.find(x) != set1.end()) {
                // Element is present in both arrays (intersection found)
                // Check if the ans vector is empty
                if (ans.size() == 0) {
                    ans.push_back(x); // Add the element to the ans vector
                } else {
                    // Check if the element is already in the ans vector (duplicate check)
                    if (binary_search(ans.begin(), ans.end(), x)) {
                        continue; // Skip if the element is already in ans
                    }
                    ans.push_back(x); // Add the element to the ans vector
                }
            }
        }

        return ans; // Return the vector containing the intersection elements
    }
};

// Driver function to test the intersection function
void testIntersection() {
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    std::vector<int> result1 = solution.intersection(nums1, nums2);

    std::cout << "Test Case 1: Intersection of nums1 and nums2 is: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test Case 2
    std::vector<int> nums3 = {4, 9, 5};
    std::vector<int> nums4 = {9, 4, 9, 8, 4};
    std::vector<int> result2 = solution.intersection(nums3, nums4);

    std::cout << "Test Case 2: Intersection of nums3 and nums4 is: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    testIntersection();
    return 0;
}