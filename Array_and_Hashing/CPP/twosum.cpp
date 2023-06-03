#include <iostream>
#include <vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using HashMaps 
        vector<int> ans;
        map<int,int> hash;
        for(auto i=0;i<nums.size();i++){
             int remainder; 
             remainder = target - nums[i];
             cout<<remainder<<endl;
            if(hash.count(remainder)){
                ans.push_back(nums[i]);
                ans.push_back(nums[hash.find(remainder)->second]);
                return ans;
              }
            hash[nums[i]]=i;
            
        }
        return ans;
    }
    
        
};

int main (){
     vector<int> List = {2,7,11,15};
     int len = List.size();
     for(int i = 0;i<len;i++){
         cout<<List[i]<<" ";
        }
       cout<<endl;
    Solution* solve = new Solution();    
    vector<int> result = solve->twoSum(List,18);
    for(int i = 0;i<result.size();i++){
         cout<<result[i]<<" ";
        }
       cout<<endl;

}