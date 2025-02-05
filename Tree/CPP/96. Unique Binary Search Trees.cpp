#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    int dp[20] = {0};
    int numTrees(int n) {
        // basically catalan number formula 

        // base case
        if(n <= 1) return 1;

        //dp case
        if(dp[n]) return dp[n];


        for(int i = 1 ; i <= n ; i++){
            int left = numTrees(i-1);
            int right = numTrees(n-i);
            dp[n] += left * right;
        }

        return dp[n];
    }
};

int numTreesBottomUp(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1; // Base cases

    for(int j = 2; j <= n; ++j) {
        for(int i = 1; i <= j; ++i) {
            dp[j] += dp[i - 1] * dp[j - i];
        }
    }

    return dp[n];
}

int main(){}