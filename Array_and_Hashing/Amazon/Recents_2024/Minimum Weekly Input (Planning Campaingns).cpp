#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> minimumWeeklyInput(vector<int>& costs, int weeks) {
    int n = costs.size();
    if (weeks > n) return {-1}; // More weeks than campaigns is invalid.
     
    // Dp to chekc 
    // dp[i][j] will store the minimum cost for the first i campaigns in exactly j weeks
    vector<vector<int>> dp(n + 1, vector<int>(weeks + 1, INT_MAX));
    
    // max_cost[i][j] will store the maximum cost in the range costs[i] to costs[j]
    vector<vector<int>> max_cost(n, vector<int>(n, 0));
    

    // This maxCost will give me maxCost from window i to j
    // Precompute the maximum costs for all subarrays
    for (int i = 0; i < n; ++i) {
        max_cost[i][i] = costs[i];
        for (int j = i + 1; j < n; ++j) {
            max_cost[i][j] = max(max_cost[i][j - 1], costs[j]);
        }
    }
    
    // Base case: For one week, dp[i][1] is the maximum cost from 0 to i.
    for (int i = 0; i < n; ++i) {
        dp[i + 1][1] = max_cost[0][i];
    }
    
    // Fill dp array
    for (int j = 2; j <= weeks; ++j) { // For each week from 2 to 'weeks'
        for (int i = 1; i <= n; ++i) { // For each campaign position
            for (int k = 0; k < i; ++k) { // Possible previous split points
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + max_cost[k][i - 1]);
            }
        }
    }
    
    return dp[n-1];
}

int main() {
    vector<int> costs = {1000, 500, 2000, 8000, 1500};
    int weeks = 3;
    
    vector<int> result = minimumWeeklyInput(costs, weeks);
    int maxR = INT_MIN;
    for(auto x : result) maxR = max(maxR,x), cout<<x<<" ";
    cout<<maxR; 
    
    return 0;
}