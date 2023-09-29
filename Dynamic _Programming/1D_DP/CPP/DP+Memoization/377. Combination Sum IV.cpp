#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <functional>
using namespace std;
using namespace chrono;

class Solution {
    // Recursive solution
    int solve(vector<int> &nums, int &target, int sum, int &count, int &n) {
        // Base cases
        if (sum < 0 || target == 0) return 0;
        if (sum == 0) return 1;

        // Recursion
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            currSum += solve(nums, target, sum - nums[i], count, n);
        }
        return currSum;
    }

public:
    int combinationSum4Recursive(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();
        return solve(nums, target, target, count, n);
    }
};

// Dynamic Programming solution with memoization
class Solution2 {
    int solve(vector<int> &nums, int &target, int Remainingsum, int &count, int &n, vector<int> &dp) {
        // Base cases
        if (Remainingsum < 0 || target == 0) return 0;
        if (Remainingsum == 0) return 1;

        if (dp[Remainingsum] != -1) return dp[Remainingsum];

        // Recursion
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            currSum += solve(nums, target, Remainingsum - nums[i], count, n, dp);
        }
        return dp[Remainingsum] = currSum;
    }

public:
    int combinationSum4DP(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();
        vector<int> dp(1010, -1);
        return solve(nums, target, target, count, n, dp);
    }
};

// Dynamic Programming solution without memoization
class Solution3 {
public:
    int combinationSum4DPNoMemo(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();
        vector<unsigned> dp(target + 1, 0);
        dp[0] = 1; // Selecting elements with a sum of 0 will always be 1, so we start from 1

        for (int ifsum = 1; ifsum <= target; ifsum++) {
            for (int numsIndex = 0; numsIndex < n; numsIndex++) {
                if (ifsum - nums[numsIndex] >= 0)
                    dp[ifsum] += dp[ifsum - nums[numsIndex]];
            }
        } 

        return dp[target];
    }
};

// Function to measure the execution time of a given solution
long long measureExecutionTime(function<int(vector<int>&, int)> solutionFunction, vector<int>& nums, int target) {
    auto start = high_resolution_clock::now();
    int result = solutionFunction(nums, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

int main() {
    Solution solution;
    Solution2 solution2;
    Solution3 solution3;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 15;

    cout << "Solution" << setw(30) << "Execution Time (microseconds)" << endl;
    cout << "---------------------------------------------" << endl;

    // Measure execution time for Recursive solution
    auto startRecursive = high_resolution_clock::now();
    int resultRecursive = solution.combinationSum4Recursive(nums, target);
    auto stopRecursive = high_resolution_clock::now();
    auto durationRecursive = duration_cast<microseconds>(stopRecursive - startRecursive);

    // Measure execution time for Dynamic Programming solution with memoization
    auto startDP = high_resolution_clock::now();
    int resultDP = solution2.combinationSum4DP(nums, target);
    auto stopDP = high_resolution_clock::now();
    auto durationDP = duration_cast<microseconds>(stopDP - startDP);

    // Measure execution time for Dynamic Programming solution without memoization
    auto startDPNoMemo = high_resolution_clock::now();
    int resultDPNoMemo = solution3.combinationSum4DPNoMemo(nums, target);
    auto stopDPNoMemo = high_resolution_clock::now();
    auto durationDPNoMemo = duration_cast<microseconds>(stopDPNoMemo - startDPNoMemo);

    cout << left << setw(30) << "Recursive Result:" << resultRecursive << setw(30) << durationRecursive.count() << endl;
    cout << left << setw(30) << "DP (Memoization) Result:" << resultDP << setw(30) << durationDP.count() << endl;
    cout << left << setw(30) << "DP (No Memoization) Result:" << resultDPNoMemo << setw(30) << durationDPNoMemo.count() << endl;

    return 0;
}
