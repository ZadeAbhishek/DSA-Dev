#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> memo;  // Memoization array to store intermediate results
    
public:

    // Recursive approach with memoization
    bool dp(vector<int>& nums, int i){
        // Base cases
        if(i < 0) return true;  // Successfully partitioned the whole array
        if(i == 0) return false;  // Last element itself can't form a valid partition

        if(memo[i] != -1) return memo[i];  // If result is already computed, return it

        int x = false;
        
        if(i > 0 && nums[i] == nums[i-1])
            x |= dp(nums, i - 2);  // Check if valid partition can be made up to i-2

        if(i > 1 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2])
            x |= dp(nums, i - 3);  // Check if valid partition can be made up to i-3
        
        if(i > 1 && nums[i] == nums[i-1] + 1 && nums[i-1] == nums[i-2] + 1)
            x |= dp(nums, i - 3);  // Check if valid partition can be made up to i-3

        return memo[i] = x;  // Store and return the result for index i
    }

    // Function to check if valid partition exists using recursive approach
    bool validPartition(vector<int>& nums) {
        // Initialize memoization array
        memo.resize(nums.size() + 1, -1);

        // Call the dp function starting from the last index of the array
        return dp(nums, nums.size() - 1);
    }
};

class Solution {
public:

    // Function to check if valid partition exists using bottom-up approach
    bool validPartition(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);  // Memoization array to store intermediate results
        
        for(int i = 0; i < nums.size(); i++) {
            int x = false;
            
            if(i > 0 && nums[i] == nums[i-1])
                x |= (i - 2 < 0) ? true : memo[i - 2];  // Check if valid partition can be made up to i-2

            if(i > 1 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2])
                x |= (i - 3 < 0) ? true : memo[i - 3];  // Check if valid partition can be made up to i-3
            
            if(i > 1 && nums[i] == nums[i-1] + 1 && nums[i-1] == nums[i-2] + 1)
                x |= (i - 3 < 0) ? true : memo[i - 3];  // Check if valid partition can be made up to i-3

            memo[i] = x;  // Store the result for index i
        }

        return memo[nums.size() - 1];  // Return the result for the last index
    }
};
