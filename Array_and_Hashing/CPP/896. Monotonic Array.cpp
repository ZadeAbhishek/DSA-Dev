#include <bits/stdc++.h>
using namespace std;

    bool isMonotonic(vector<int>& nums) {
        int increasing = true;
        int decreasing = true;
        for(auto i = 1 ; i < nums.size() ; i++) {
            if(nums[i] < nums[i-1]) increasing = false;
            if(nums[i] > nums[i-1]) decreasing = false;
            if(!increasing && !decreasing) return false;
        }
        return true;
    }

int main(){
    vector<int> nums = {1,2,3,4,3,6};
    cout<<isMonotonic(nums)<<"\n";
}