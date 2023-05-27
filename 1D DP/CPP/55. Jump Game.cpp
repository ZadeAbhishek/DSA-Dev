class Solution {
public:
    // bool canJump(vector<int>& nums, int position,vector<bool>& dp) {
    //    if(position >= size(nums)-1) return true;
    //    if(dp[position]) return dp[position];
    //    while(nums[position] != 0 && !dp[position])
    //    {
    //        dp[position] = canJump(nums,position+nums[position],dp);
    //        nums[position]--;
    //    }
    //    return dp[position];
    // }

    //  bool canJump(vector<int>& nums)
    //  {
    //       vector<bool> dp(size(nums),false);
    //       return canJump(nums,0,dp);
    //  }

    bool canJump(vector<int>& nums)
     {
          if(size(nums) <= 1) return true;
          int distance = 0;
          for(auto  curr = 0; curr < size(nums); curr++)
          {
              distance = max(distance, curr + nums[curr]);
              if(distance >= size(nums)-1) return true;
              if(distance == curr) return false;
          }
          return true;
     }


};