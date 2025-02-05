#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumOfLengths(vector<int>& nums, int k, int n) {
    int left = 0, zeros = 0, maxSum = 0;
    vector<int> lengths; // To store lengths of valid subarrays

    for (int right = 0; right < nums.size(); ++right) {
        // Expand the window
        if (nums[right] == 0) {
            zeros++;
        }

        // Shrink the window if `zeros` exceed `k`
        while (zeros > k) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }

        // Add valid subarray lengths to the list
        int currentLength = right - left + 1;
        if (currentLength > n) {
            lengths.push_back(currentLength);
        }
    }

    // Sort lengths in descending order to maximize the sum
    sort(lengths.rbegin(), lengths.rend());

    // Add the lengths to maximize the sum
    for (int i = 0; i < lengths.size() && i < k; ++i) {
        maxSum += lengths[i];
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int k = 2, n = 4;
    cout << "Maximum Sum of Lengths: " << maxSumOfLengths(nums, k, n) << endl;
    return 0;
}