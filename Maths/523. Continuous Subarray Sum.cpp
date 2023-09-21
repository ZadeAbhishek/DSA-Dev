// please watch this in 1.5X 
// https://www.youtube.com/watch?v=2K92SzwNaPg&t=599s&ab_channel=TechAdorabyNivedita

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int sum = 0;
      unordered_map<int,int> remainders;
      remainders[0] = 0;
      for(int index = 0; index < nums.size() ; index++){
          sum += nums[index];
          if(remainders.count(sum%k)){
              if(remainders[sum%k] < index) return true;
          }
          else remainders[sum%k] = index+1;
      }
      return false;
    }
};