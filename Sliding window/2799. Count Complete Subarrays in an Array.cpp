#include<bits/stdc++.h>
using namespace std;


// brute force
class Solution
{
  public:
    int countCompleteSubarrays(vector<int> &nums)
    {
     	// stored in hash
      set<int> hash(nums.begin(), nums.end());

     	// hash size == min windows size
      int window = hash.size();

     	// result
      int count = 0;

      for (int i = 0; i < nums.size(); i++)
      {
        set<int> secondary_set;
        for (int j = i; j < nums.size(); j++)
        {
         	// if present
          secondary_set.insert(nums[j]);

          if (((j - i) + 1) >= window && secondary_set.size() == window) count++;
        }
      }

      return count;
    }
};

// rethink for this solution not my solution
class Solution2 {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), k = unordered_set<int>(nums.begin(), nums.end()).size();
        int res = 0, i = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < n; ++j) {
            count[nums[j]]++;
            if(count[nums[j]] == 1) k--;
            while(k == 0) {
                count[nums[i]]--;
                if(count[nums[i++]] == 0) k += 1;
            }
            res += i;
        }
        return res;
    }
};


int main(){
   vector<int> x = {1,3,1,2,2};
   Solution2 solve;
   cout<<solve.countCompleteSubarrays(x);
}