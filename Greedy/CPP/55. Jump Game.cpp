#include <iostream>
#include <vector>
#include <chrono> // For measuring runtime

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums, int position, vector<int>& dp) {
        // If we reach the last index or beyond, return true.
        if (position >= nums.size()-1) return true;
        
        // If this position has already been calculated, return its result.
        if (dp[position]) return dp[position];
        
        // Iterate through possible jump distances.
        bool curr = false;
        while (nums[position] != 0 && !dp[position]) {
            dp[position] |= canJump(nums, position + nums[position], dp);
            nums[position]--;
        }
        
        return dp[position];
    }

    bool canJump(vector<int>& nums) {
        // Initialize a dynamic programming array for memoization.
        vector<int> dp(nums.size(), 0);
        
        // Start the recursive function from the first position.
        return canJump(nums, 0, dp);
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int distance = 0;
        
        for (int curr = 0; curr < nums.size(); curr++) {
            distance = max(distance, curr + nums[curr]);
            
            // If we can reach or exceed the last index, return true.
            if (distance >= nums.size() - 1) return true;
            
            // If we're stuck at a position with a zero, return false.
            if (distance == curr) return false;
        }
        
        return true;
    }
};

int main() {
    vector<int> nums = {2,0,0}; // Replace this with your input data

    Solution solution1;
    Solution2 solution2;

    // Measure the runtime of Solution 1
    auto start_time1 = chrono::high_resolution_clock::now();
    bool result1 = solution1.canJump(nums);
    auto end_time1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1);

    // Measure the runtime of Solution 2
    auto start_time2 = chrono::high_resolution_clock::now();
    bool result2 = solution2.canJump(nums);
    auto end_time2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);

    // Print the results and runtimes
    cout << "Using Solution 1:" << endl;
    cout << "Can jump: " << (result1 ? "true" : "false") << endl;
    cout << "Runtime for Solution 1: " << duration1.count() << " microseconds" << endl;

    cout << "Using Solution 2:" << endl;
    cout << "Can jump: " << (result2 ? "true" : "false") << endl;
    cout << "Runtime for Solution 2: " << duration2.count() << " microseconds" << endl;

    return 0;
}
