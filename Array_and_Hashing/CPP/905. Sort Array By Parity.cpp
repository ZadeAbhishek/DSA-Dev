class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for(auto &curr : nums){
            if(curr%2 == 1) result.push_back(curr);
            else result.insert(result.begin(),curr);
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even = 0; // even pointer
        int odd = nums.size() - 1; // odd pointer
        while(even <= odd){
            // there will be four case 
            if(nums[even] % 2 == 1 && nums[odd] % 2 == 0) swap(nums[even],nums[odd]);
            else if(nums[even] % 2 == 1 && nums[even] % 2 == 1) odd--;
            else even++;
        }
        return nums;
    }
};



//log n time complexity
class Solution3 {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even = 0; // even pointer
        int odd = nums.size() - 1; // odd pointer
        while (even < odd) {
            if (nums[even] % 2 != 0) {
                swap(nums[even], nums[odd]);
                odd--;
            } else {
                even++;
            }
        }
        return nums;
    }
};