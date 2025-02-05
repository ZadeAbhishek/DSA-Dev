#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    // Helper function to calculate subarrays with at most `k` distinct integers
    int findK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, result = 0;
        unordered_map<int, int> hash;

        for (int right = 0; right < n; ++right) {
            hash[nums[right]]++;

            while (hash.size() > k) { // Reduce window size if distinct count > k
                hash[nums[left]]--;
                if (hash[nums[left]] == 0) {
                    hash.erase(nums[left]);
                }
                left++;
            }

            result += (right - left + 1); // Add all subarrays ending at `right`
        }

        return result;
    }

public:
    // Function to calculate subarrays with exactly `k` distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k == 0) return 0; // Handle edge case for k = 0
        return findK(nums, k) - findK(nums, k - 1);
    }
};

void runTestCases() {
    Solution solution;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 1, 1, 1}, 2},     // Expected Output: 0
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int k = testCases[i].second;

        cout << "Test Case " << i + 1 << ": ";
        cout << "Input: nums = {";
        for (size_t j = 0; j < nums.size(); ++j) {
            cout << nums[j];
            if (j < nums.size() - 1) cout << ", ";
        }
        cout << "}, k = " << k << endl;

        int result = solution.subarraysWithKDistinct(nums, k);
        cout << "Output: " << result << endl;
        cout << "--------------------------------" << endl;
    }
}

int main() {
    runTestCases();
    return 0;
}