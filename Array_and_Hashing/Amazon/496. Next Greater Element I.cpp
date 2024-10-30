class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // May be hashmap can be use here
        unordered_map<int,int> hash;
        for(auto i = 0 ; i < nums2.size(); i++){
            hash[nums2[i]] = i;
        }
        // traverse the elements
        vector<int> result;
        for(auto x : nums1){
            int sudoIndex = hash[x];
            int nextGreat = -1;
            for(auto i = sudoIndex+1 ; i < nums2.size(); i++){
                if(nums2[i] > x) {
                    nextGreat = nums2[i];
                    break;
                }
            }
            result.push_back(nextGreat);
        }
        return result;
    }
};