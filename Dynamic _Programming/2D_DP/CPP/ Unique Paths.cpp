#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n, int x, int y, vector<vector<int>>& memo) {
        // Check if the coordinates (x, y) are within the grid boundaries.
        if (!(x < 0 || x > m - 1 || y < 0 || y > n - 1)) {
            // Check if we have reached the bottom-right corner of the grid.
            if (x == m - 1 && y == n - 1) return 1;
            
            // Check if the result for this coordinate has been memoized.
            if (memo[x][y]) return memo[x][y];
            
            // Calculate unique paths recursively by moving right and down.
            return memo[x][y] = uniquePaths(m, n, x + 1, y, memo) + uniquePaths(m, n, x, y + 1, memo);
        }
        return 0;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0)); // Initialize memoization table.
        return uniquePaths(m, n, 0, 0, memo); // Start the recursion from the top-left corner.
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 2, vector<int>(n + 2, 0)); // Initialize a memoization table with extra rows and columns.
        memo[m][n] = 1; // Initialize the bottom-right corner as 1.
        for (int x = m; x > 0; x--) {
            for (int y = n; y > 0; y--) {
                memo[x][y] += memo[x + 1][y] + memo[x][y + 1]; // Calculate unique paths iteratively.
            }
        }
        return memo[1][1]; // The top-left corner contains the result.
    }
};

class Solution3 {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++) {
            ans = (ans * i) / j; // Calculate unique paths using combinatorial formula.
        }
        return ans;
    }
};

int main() {
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;

    int m = 3;
    int n = 7;

    // Test the first solution.
    int result1 = sol.uniquePaths(m, n);
    cout << "Solution 1: " << result1 << endl;

    // Test the second solution.
    int result2 = sol2.uniquePaths(m, n);
    cout << "Solution 2: " << result2 << endl;

    // Test the third solution.
    int result3 = sol3.uniquePaths(m, n);
    cout << "Solution 3: " << result3 << endl;

    return 0;
}
