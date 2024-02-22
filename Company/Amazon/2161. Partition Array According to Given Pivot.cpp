class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // less array 
        vector<int> less;
        // greater arrat
        vector<int> great;
        // pivot
        vector<int> piv;

        for(auto x : nums){
            if(x < pivot) less.push_back(x);
            else if(x > pivot) great.push_back(x);
            else piv.push_back(x);
        }

        nums.clear();

        copy(less.begin(), less.end(), back_inserter(nums));
        copy(piv.begin(), piv.end(), back_inserter(nums)); 
        copy(great.begin(), great.end(), back_inserter(nums));

        return nums;  
    }
};