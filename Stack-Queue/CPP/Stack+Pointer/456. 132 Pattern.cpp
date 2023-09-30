class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int thirdNo = INT_MIN;

        for(int i = nums.size()-1 ; i >= 0 ; i--){
            if(nums[i] < thirdNo) return true;
            while(!s.empty() && s.top() < nums[i]){
                thirdNo = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};