#include <iostream>
#include <vector>
using namespace std;

class Solution {
    // Helper function for recursive DFS
    bool solve(vector<int>& stones, int units, int curr, vector<vector<int>>& dp) {
        // Base case: If we reach the last stone, we can cross.
        if (curr == stones.size() - 1) return true;

        // If we go beyond the last stone, we can't cross.
        if (curr >= stones.size()) return false;

        // If we have already computed this state, return the result from dp.
        if (dp[curr][units] != -1) return dp[curr][units];

        bool ans = false;

        // Try three possible jump units: units-1, units, and units+1.
        for (auto unit : {units - 1, units, units + 1}) {
            // Skip the case where the unit is 0, as it's not a valid jump.
            if (unit == 0) continue;

            // Find the next stone we can jump to.
            int next = lower_bound(stones.begin() + (curr + 1), stones.end(), stones[curr] + unit) - stones.begin();

            // If we can't find a stone to jump to, or it's not the right distance, continue to the next unit.
            if (next == stones.size() || stones[next] != stones[curr] + unit) continue;

            // Recursively check if we can reach the end from the next stone with the current unit.
            ans |= solve(stones, unit, next, dp);
        }

        // Store the result in dp and return it.
        return dp[curr][units] = ans;
    }

public:
    bool canCross(vector<int>& stones) {
        int units = 0;

        // If there are no stones, we can reach the end.
        if (stones.size() < 1) return true;

        // Initialize a memoization table dp.
        vector<vector<int>> dp(stones.size() + 1, vector<int>(stones.size() + 1, -1));

        // Start the DFS from the first stone.
        return solve(stones, units, 0, dp);
    }
};


int main() {
    Solution solution;

    // Test case 1: Positive case
    std::vector<int> stones1 = {0, 1, 3, 5, 6, 8, 12, 17};
    bool canCross1 = solution.canCross(stones1);
    std::cout << "Test case 1: " << (canCross1 ? "Yes" : "No") << std::endl;

    // Test case 2: Negative case
    std::vector<int> stones2 = {0, 1, 2, 3, 4, 8, 9, 11};
    bool canCross2 = solution.canCross(stones2);
    std::cout << "Test case 2: " << (canCross2 ? "Yes" : "No") << std::endl;

    // Test case 3: Edge case with no stones
    std::vector<int> stones3;
    bool canCross3 = solution.canCross(stones3);
    std::cout << "Test case 3: " << (canCross3 ? "Yes" : "No") << std::endl;

    return 0;
}
