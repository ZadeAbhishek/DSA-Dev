#include <iostream>
#include <vector>
using namespace std;


//##1DP
class Solution {
public:
    int findDerangement(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1) return 0; // Base case: D(1) = 0
        if (n == 2) return 1; // Base case: D(2) = 1

        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // D(0) = 1
        dp[1] = 0; // D(1) = 0
        dp[2] = 1; // D(2) = 1

        for (int i = 3; i <= n; ++i) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 4;
    cout << "Number of derangements for n = " << n << " is: " << solution.findDerangement(n) << endl;
    return 0;
}


#include <iostream>
using namespace std;

class Solution {
public:
    int findDerangement(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1) return 0; // Base case: D(1) = 0
        if (n == 2) return 1; // Base case: D(2) = 1

        long long prev2 = 1; // D(0)
        long long prev1 = 0; // D(1)
        long long current = 1; // D(2)

        for (int i = 3; i <= n; ++i) {
            current = (i - 1) * (prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};

int main() {
    Solution solution;
    int n = 4;
    cout << "Number of derangements for n = " << n << " is: " << solution.findDerangement(n) << endl;
    return 0;
}