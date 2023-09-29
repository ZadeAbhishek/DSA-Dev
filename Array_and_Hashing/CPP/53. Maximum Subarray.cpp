#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algorithm
        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int &x : nums) {
            currentSum += x;
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

int main() {
    Solution solution;

    // Test case: Find the maximum subarray sum
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = solution.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;
}
