#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // array is sorted 
        
        // find mid and find the number 
        
        // if got return else don't return 
        
        int high = size(nums) - 1;
        int low = 0;
                     
        
        while(true)
        {
            
            if(low == high)
            {
                if(nums[low] == target) return low;
                else return -1;
            }
            
            int mid = (high + low) / 2;
            
            if(nums[mid] == target) return mid;
            
            else if(target > nums[mid]) low = mid + 1;
            
            else if(target < nums[mid]) high = mid;
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9,10,11,12};
    Solution * solve = new Solution();
    int index = solve->search(arr,3);
    cout<<index;
}