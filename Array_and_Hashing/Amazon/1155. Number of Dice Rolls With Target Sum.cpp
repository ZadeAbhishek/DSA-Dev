// ##dp
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target, dp, 0);
    }

private:
    int helper(int n, int k, int target, vector<vector<int>>& dp, int currSum) {
        if (currSum > target) return 0;

        // Base case: If no dice left and we reach the target
        if (n == 0) {
            return currSum == target ? 1 : 0;
        }

        // Memoization: If the result is already calculated
        if (dp[n][currSum] != -1) return dp[n][currSum];

        int totalCount = 0;

        // Loop through all face values of the dice
        for (int i = 1; i <= k; i++) {
            totalCount = (totalCount + helper(n - 1, k, target, dp, currSum + i)) % 1000000007;
        }

        return dp[n][currSum] = totalCount;
    }
};


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1; // Base case: 0 dice to make sum 0

        for (int dice = 1; dice <= n; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                for (int face = 1; face <= k; face++) {
                    if (sum - face >= 0) {
                        dp[dice][sum] = (dp[dice][sum] + dp[dice - 1][sum - face]) % MOD;
                    }
                }
            }
        }

        return dp[n][target];
    }
};