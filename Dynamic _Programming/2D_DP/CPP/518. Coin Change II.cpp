#include<bits/stdc++.h>
using namespace std;


// TLE marra
class Solution {
    void getCombinations(int &amount,int total, int &count,vector<int>& coins, set<vector<int>> &hash, vector<int> &temp){
        // base case
        if(total > amount) return;

        if(total == amount){
            vector<int> x = temp;
            sort(x.begin(),x.end());
            if(hash.find(x) == hash.end()){
            hash.insert(x);
            count++;
            }
            return;
        }

        // iteration
        int n = coins.size();
        for(int i = 0 ; i < n ; i++){
            temp.push_back(coins[i]);
            getCombinations(amount,total+coins[i],count,coins,hash,temp);
            temp.pop_back();
        }

        return; 
    }
public:
    int change(int amount, vector<int>& coins) {
        int count = 0;
        set<vector<int>> hash;
        vector<int> temp;
        getCombinations(amount,0,count,coins,hash,temp);
        return count;
    }
};


class Solution {
    int getCombinations(int amount,int i,vector<int>& coins, vector<vector<int>> &dp){
        // base case

        if(amount == 0){
            return 1;
        }

        if(i == coins.size()) return 0;

        if(dp[amount][i] != -1) return dp[amount][i];
        
        int take = 0,dont = 0;

        if(coins[i]<=amount){
         take = getCombinations(amount-coins[i],i,coins,dp);
        }
        dont = getCombinations(amount,i+1,coins,dp);

        return dp[amount][i] = take + dont; 
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
        return getCombinations(amount,0,coins,dp);
    }
};



int main(){}