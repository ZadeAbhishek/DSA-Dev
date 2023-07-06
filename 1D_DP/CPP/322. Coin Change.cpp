/**
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1


*/

class Solution {
public:
    
    void getChange(vector<int> &coins, int amount , int counter, int &md){
        // base case
        if(amount == 0) {
            md = min(md,counter);
            return;
        }
        if(amount < 0) return;

        // recursive case
        for(int i = 0 ; i < coins.size(); i++){
            getChange(coins,amount - coins[i],counter+1,md);
        }

        return;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int counter = 0;
        int minDenomination = INT_MAX; // pass by reference
        getChange(coins,amount,counter,minDenomination);
        return minDenomination==INT_MAX?-1:minDenomination;
    }
};