#include <iostream>
#include <vector>
#include <cassert> // For testing with assert
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int maxSum = -1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < k){
                maxSum = max(maxSum,sum);
                left++;
            }
            else right--;
        }
        return maxSum;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {34, 23, 1, 24, 75, 33, 54, 8};
    int k1 = 60;
    int result1 = sol.twoSumLessThanK(nums1, k1);
    cout << "Test Case 1 Result: " << result1 << endl;
    assert(result1 == 58); // Expected: 58

    // Test Case 2
    vector<int> nums2 = {10, 20, 30};
    int k2 = 15;
    int result2 = sol.twoSumLessThanK(nums2, k2);
    cout << "Test Case 2 Result: " << result2 << endl;
    assert(result2 == -1); // Expected: -1

    // Test Case 3
    vector<int> nums3 = {1, 2, 3, 4, 5};
    int k3 = 9;
    int result3 = sol.twoSumLessThanK(nums3, k3);
    cout << "Test Case 3 Result: " << result3 << endl;
    assert(result3 == 8); // Expected: 8

    cout << "All test cases passed!" << endl;

    return 0;
}