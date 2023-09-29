#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        long long total = 0;
        for (auto &x : nums) {
            total += x;
        }
        int n = nums.size();
        int sumA = 0;
        int count = 0;

        // Iterate over the first partition
        for (int first = 0; first < n - 2; first++) {
            sumA += nums[first];
            int sumB = 0;

            // Iterate over the second partition
            for (int second = first + 1; second < n - 1; second++) {
                sumB += nums[second];
                int sumC = total - (sumA + sumB);

                // Check if the conditions for a valid split are met
                if (sumA <= sumB && sumA <= sumC && sumB <= sumC) {
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution2 {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        for (auto &x : nums) {
            total += x;
        }
        int count = 0;
        int n = nums.size();
        long long sum = 0;

        // Iterate over the first partition
        for (int part = 0; part < n - 1; part++) {
            sum += nums[part];

            // Check if the conditions for a valid split are met
            if (sum >= (total - sum)) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    Solution2 solution2;

    // Test cases
    vector<int> nums1 = {1, 2, 2, 2, 5};
    vector<int> nums2 = {1, 2, 3, 2, 1};

    cout << "Solution 1:" << endl;
    cout << "Ways to split the array (nums1): " << solution.waysToSplit(nums1) << endl;
    cout << "Ways to split the array (nums2): " << solution.waysToSplit(nums2) << endl;

    cout << "Solution 2:" << endl;
    cout << "Ways to split the array (nums1): " << solution2.waysToSplitArray(nums1) << endl;
    cout << "Ways to split the array (nums2): " << solution2.waysToSplitArray(nums2) << endl;

    return 0;
}
