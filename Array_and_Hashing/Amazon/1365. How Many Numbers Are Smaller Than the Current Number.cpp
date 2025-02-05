class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
         unordered_map<int,int> hash; // num , index
         vector<int> result;
         auto temp = nums;
         sort(nums.begin(),nums.end());
         for(int i = nums.size() - 1; i >= 0 ; i--){
             hash[nums[i]] = i;
         }
         for(auto x : temp){
            int index = hash[x];
            result.push_back(index);
         }
         return result;
    }
};