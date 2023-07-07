/**
 * https://www.youtube.com/watch?v=vRVfmbCFW7Y&ab_channel=takeUforward
 * https://www.youtube.com/watch?v=Yz4LlDSlkns&ab_channel=takeUforward
 * 
*/

// Partition DP

class Solution {
public:
    
    int burst(vector<int>& nums, int i , int j,vector<vector<int>> &memo){
        // base case
        if(i > j) return 0;

        //memoization
        if(memo[i][j] != -1) return memo[i][j];

        // main case
        int maxCoin = INT_MIN;
        for(int k = i ; k <= j ; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1] + burst(nums,i,k-1,memo) + burst(nums,k+1,j,memo);
            maxCoin = max(maxCoin,coins); 
        }
        return memo[i][j] = maxCoin;
    }


    int maxCoins(vector<int>& nums) {
        int size = nums.size(); // last elements before append
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // [3,1,5,8] ---> [1,3,1,5,8,1]
        vector<vector<int>> memo(size+1,vector<int>(size+1,-1));
        int coins = burst(nums,1,size,memo);
        return coins;
    }
};