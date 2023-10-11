class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return dfs(n, m, k, 0, 0, 0, dp);
    }

    int dfs(int n, int m, int k, int i, int currMax, int currCost, vector<vector<vector<int>>>& dp) {
        if (i == n) {
            if (k == currCost) return 1;
            return 0;
        }
        if (dp[i][currMax][currCost] != -1) return dp[i][currMax][currCost];
        int ans = 0;
        for (int num = 1; num <= m; num++) {
            int newCost = currCost;
            int newMax = currMax;
            if (num > currMax) {
                newCost++;
                newMax = num;
            }
            if (newCost > k) break;
            ans += dfs(n, m, k, i + 1, newMax, newCost, dp);
            ans %= 1000000007;
        }
        return dp[i][currMax][currCost] = ans;
    }
};