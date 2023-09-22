#include <iostream>
#include <vector>
#include <climits> // For using INT_MAX
#include <chrono> // For measuring runtime
using namespace std;

class Solution {
public:
    // Approach 1: Recursive (Brute Force)
    void getChange(vector<int> &coins, int amount, int counter, int &md) {
        // Base case: If we have reached the desired amount.
        if (amount == 0) {
            md = min(md, counter); // Update the minimum denomination if needed.
            return;
        }
        if (amount < 0) return;

        // Recursive case: Try using each coin denomination.
        for (int i = 0; i < coins.size(); i++) {
            getChange(coins, amount - coins[i], counter + 1, md);
        }
        return;
    }

    int coinChangeBruteForce(vector<int>& coins, int amount) {
        int counter = 0; // Counter to keep track of the number of coins used.
        int minDenomination = INT_MAX; // Initialize with a large value.

        // Find the minimum denomination using the recursive function.
        getChange(coins, amount, counter, minDenomination);

        // If minDenomination is still INT_MAX, it means no valid combination was found.
        return minDenomination == INT_MAX ? -1 : minDenomination;
    }

    // Approach 2: Dynamic Programming (Optimized)
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        vector<int> memo(amount + 1, -1); // Memoization array to store computed results.

        // Helper function to find the minimum denomination.
        int minDenomination = getChange(coins, amount, memo);

        // If minDenomination is still INT_MAX, it means no valid combination was found.
        return minDenomination == INT_MAX ? -1 : minDenomination;
    }

    int getChange(vector<int> &coins, int amount, vector<int> &memo) {
        // Base case: If we have reached the desired amount.
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX; // Use INT_MAX to represent invalid combinations.
        if (memo[amount] != -1) return memo[amount]; // Return the memoized result if available.

        int mini = INT_MAX; // Initialize with a large value.

        // Recursive case: Try using each coin denomination.
        for (int i = 0; i < coins.size(); i++) {
            int ans = getChange(coins, amount - coins[i], memo);

            // If ans is not INT_MAX, it means a valid combination was found.
            if (ans != INT_MAX) {
                mini = min(mini, ans + 1); // Update the minimum denomination.
            }
        }
        memo[amount] = mini; // Memoize the result.

        return memo[amount];
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    // Using the Brute Force approach
    auto start_time_bruteforce = chrono::high_resolution_clock::now();
    int resultBruteForce = solution.coinChangeBruteForce(coins, amount);
    auto end_time_bruteforce = chrono::high_resolution_clock::now();
    auto duration_bruteforce = chrono::duration_cast<chrono::microseconds>(end_time_bruteforce - start_time_bruteforce);

    cout << "Using Brute Force Approach: " << resultBruteForce << endl;
    cout << "Runtime for Brute Force Approach: " << duration_bruteforce.count() << " microseconds" << endl;

    // Using the Optimized Dynamic Programming approach
    auto start_time_optimized = chrono::high_resolution_clock::now();
    int resultOptimized = solution.coinChange(coins, amount);
    auto end_time_optimized = chrono::high_resolution_clock::now();
    auto duration_optimized = chrono::duration_cast<chrono::microseconds>(end_time_optimized - start_time_optimized);

    cout << "Using Optimized Dynamic Programming: " << resultOptimized << endl;
    cout << "Runtime for Optimized Dynamic Programming: " << duration_optimized.count() << " microseconds" << endl;

    return 0;
}
