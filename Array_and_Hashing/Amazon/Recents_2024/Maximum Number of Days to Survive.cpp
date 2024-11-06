#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ##Greedy 
class Solution {
public:
    int maximumNumberOfDaysToSurvive(vector<int>& lender, vector<int>& payback) {
        int n = lender.size();
        vector<pair<int, int>> loans(n);
        
        // Create pairs of (lender[i], payback[i]) and sort them based on lender[i]
        for (int i = 0; i < n; i++) {
            loans[i] = {lender[i], payback[i]};
        }
        
        // Sort lenders by their lender value
        sort(loans.begin(), loans.end());
        
        // DP array to store max days achievable starting from each lender
        vector<int> dp(n, 0);
        
        // Initialize base case: if we start with each lender individually
        for (int i = 0; i < n; i++) {
            dp[i] = 1; // At least one day can be survived with any lender
        }
        
        // Fill DP table
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (loans[j].first >= loans[i].second) { // Can use lender[j] after lender[i]
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        
        // The result is the maximum value in dp array
        return *max_element(dp.begin(), dp.end());
    }
};

// Function to run a single test case
void runTest(vector<int> lender, vector<int> payback, int expected, int testNumber) {
    Solution sol;
    int result = sol.maximumNumberOfDaysToSurvive(lender, payback);
    
    cout << "Test Case " << testNumber << ": ";
    if (result == expected) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
        cout << "Expected: " << expected << ", but got: " << result << endl;
    }
}

int main() {
    // Test cases
    vector<int> lender1 = {4, 6, 1, 8};
    vector<int> payback1 = {7, 10, 3, 9};
    int expected1 = 3;
    runTest(lender1, payback1, expected1, 1);

    vector<int> lender2 = {2, 1, 5};
    vector<int> payback2 = {2, 2, 5};
    int expected2 = 3;
    runTest(lender2, payback2, expected2, 2);

    vector<int> lender3 = {1, 1, 1, 2};
    vector<int> payback3 = {2, 2, 2, 3};
    int expected3 = 2;
    runTest(lender3, payback3, expected3, 3);

    return 0;
}