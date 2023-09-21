#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Brute force solution
class SolutionBruteForce {
    // Recursive helper function to solve the problem
    void solve(vector<int>& nums, int x, int start, int end, int &minOperations, int steps) {
        // Base case: If x becomes 0, we've reached the target sum, update minOperations if necessary.
        if (x == 0) {
            minOperations = min(minOperations, steps);
            return;
        }

        // Edge case: If the indices go out of bounds, return without further processing.
        if (start > nums.size() - 1 || end < 0) return;

        // If the current element can be included, explore both options (start and end).
        if (nums[start] <= x) solve(nums, x - nums[start], start + 1, end, minOperations, steps + 1);
        if (nums[end] <= x) solve(nums, x - nums[end], start, end - 1, minOperations, steps + 1);
    }

public:
    int minOperations(vector<int>& nums, int x) {
        int minOperations = INT_MAX; // Initialize with a large value
        solve(nums, x, 0, nums.size() - 1, minOperations, 0); // Start the recursive process
        return minOperations == INT_MAX ? -1 : minOperations; // Return -1 if no valid solution found
    }
};

// Sliding window solution
class SolutionSlidingWindow {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array
        int target = total - x; // Calculate the target sum to find the subarray with this sum
        int currSum = 0; // Initialize the current sum
        int maxLenght = -1; // Initialize the maximum subarray length to -1
        int right = 0; // Initialize the right pointer
        int left = 0; // Initialize the left pointer
        int length = nums.size(); // Get the length of the input array

        for (; right < length; right++) {
            currSum += nums[right]; // Add the current element to the current sum

            // While the current sum is greater than the target, move the left pointer
            while (currSum > target && left <= right) {
                currSum -= nums[left];
                left++;
            }

            // If the current sum equals the target, update the maximum subarray length
            if (currSum == target) {
                maxLenght = max(maxLenght, (right - left) + 1);
            }
        }

        // If no valid subarray found, return -1; otherwise, return the minimum operations
        return maxLenght == -1 ? -1 : length - maxLenght;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;

    // Initialize the two solution classes
    SolutionBruteForce bruteForce;
    SolutionSlidingWindow slidingWindow;

    // Call the brute force solution and print the result
    int resultBruteForce = bruteForce.minOperations(nums, x);
    cout << "Brute Force Solution Result: " << resultBruteForce << endl;

    // Call the sliding window solution and print the result
    int resultSlidingWindow = slidingWindow.minOperations(nums, x);
    cout << "Sliding Window Solution Result: " << resultSlidingWindow << endl;

    return 0;
}
