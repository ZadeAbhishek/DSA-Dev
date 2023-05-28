class Solution {
public:
   vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
       
      sort(begin(nums),end(nums));
      vector<int> answer;
      vector<int> prefix(size(nums),0);
      int sum = 0;
      for(auto it = 0 ; it < size(nums); it++) sum += nums[it],prefix[it] = sum;
      for(auto it : queries) answer.push_back(upper_bound(prefix.begin(),prefix.end(),it)-prefix.begin()); // binary search fuction
      return answer;
    }
};