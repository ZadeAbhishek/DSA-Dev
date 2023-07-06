/**
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // union interesection 
        // binary_search(startaddress,  endaddress, valuetofind)
        vector<int> ans;
        sort(nums2.begin(),nums2.end()); // nlogn binary search need sorted array
        unordered_set<int> set1(nums1.begin(),nums1.end()); //set
        for(auto x : nums2){
            if(set1.find(x) != set1.end()){
                // element is present
                // check if empty
                if(ans.size() == 0) ans.push_back(x);
                else{
                    if(binary_search(ans.begin(), ans.end(), x)) continue;
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};