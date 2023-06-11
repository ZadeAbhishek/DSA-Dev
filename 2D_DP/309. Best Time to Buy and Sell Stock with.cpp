class Solution {
public:
    
    int maxProfit(vector<int>& prices, int buy,int index, vector<vector<int>>& dp){
        if(index >= size(prices)) return 0;
      
       if(dp[index][buy] != -1) return dp[index][buy];

        if(buy) return dp[index][buy] = max(-prices[index] + maxProfit(prices,0,index+1,dp), 0 + maxProfit(prices,1,index+1,dp));

        return dp[index][buy] = max(prices[index] + maxProfit(prices,1,index+2,dp), 0 + maxProfit(prices,0,index+1,dp));
    }
    
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(size(prices),vector<int>(2,-1));
        return maxProfit(prices,1,0,dp);
    }
};