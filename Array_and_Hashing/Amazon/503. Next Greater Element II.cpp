class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n,-1);
        for(int i = 0 ; i < n ; i++){
            for(int j = 1; j <n; j++){
                int a = (i+j)%n;
                if(nums[a]>nums[i]){
                    arr[i] = nums[a];
                    break;
                }
            }
        }
        return arr;
    }
};


// Optimised approch 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 2 * n - 2; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i % n] = st.top();
            }
            st.push(nums[i % n]);
        }

        return ans;
    }
};
