#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
// ##LongestCommonSubsequnce
class Solution {
public:
    int minOperations(string A, string B) {
        int len_A = A.length();
        int len_B = B.length();

        // Create a DP table to store lengths of LCS
        vector<vector<int>> dp(len_A + 1, vector<int>(len_B + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= len_A; ++i) {
            for (int j = 1; j <= len_B; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The length of the LCS
        int max_lcs_len = dp[len_A][len_B];

        // Calculate the minimum number of operations
        int operations = (len_A - max_lcs_len) + (len_B - max_lcs_len);

        return operations;
    }
};

// Driver code to test the function
int main() {
    Solution solution;
    string A = "abcdef";
    string B = "azced";
    int result = solution.minOperations(A, B);
    cout << "Minimum number of operations: " << result << endl;

    return 0;
}