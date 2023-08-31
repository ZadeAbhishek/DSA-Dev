// source https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/solutions/3418187/easy-c-dp/

class Solution {
public:

    int fun(vector<vector<int>> &pp , int cu , int k, vector<vector<int>> &dp ){
        if(cu>=pp.size()) return 0;
        if(dp[cu][k] != -1 ) return dp[cu][k];
        int mx=0;
        for(int i=0;i<pp[cu].size();i++){
            if(k-i>=0) mx = max(mx , pp[cu][i]+fun(pp,cu+1,k-i,dp));
        }
        return dp[cu][k] = mx;
    }

    int maxValueOfCoins(vector<vector<int>>& pp, int k) {
        int  n = pp.size();
        vector<vector<int>> pre(n);
        vector<vector<int>> dp(n+2,vector<int>(k+2,-1));
        for(int i=0;i<n;i++){
            int su=0;
            for( int a : pp[i]){
                pre[i].push_back(su);
                su+=a;
            }
            pre[i].push_back(su);
        }
        return fun(pre,0,k,dp);
    }
};