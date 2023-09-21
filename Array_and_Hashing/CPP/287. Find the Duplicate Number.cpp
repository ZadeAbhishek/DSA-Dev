class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()+1;
        vector<int> count(n+1,0);
        for(auto &x : nums) {
            count[x]++;
            if(count[x] > 1) return x;
        }
    return 0;
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = slow; // both are in same place at start
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]]; // always twice fast as slow
            if(fast == slow) break;
        }
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};