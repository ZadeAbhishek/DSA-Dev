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


// more optimised solution 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> s;
        
        // Process nums2 from left to right.
        // For each element, pop from the stack until the current element is smaller than the stack top.
        // For every popped element, the current element is its next greater element.
        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        // For any elements remaining in the stack, there is no next greater element.
        while (!s.empty()) {
            nextGreater[s.top()] = -1;
            s.pop();
        }
        
        // Build the result for nums1 using the precomputed mapping.
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        return result;
    }
};