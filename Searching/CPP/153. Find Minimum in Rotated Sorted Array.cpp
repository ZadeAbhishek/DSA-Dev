/*
*Input: nums = [3,4,5,1,2]
Output: 1

Input: nums = [4,5,6,7,0,1,2]
Output: 0


*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0; 
        int high = nums.size()-1;
        int minElement = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= nums[low]) minElement = min(minElement,nums[low]),low = mid+1;
            else minElement = min(minElement,nums[mid]),high = mid-1;
        }

        return minElement;
    }


// optimised
   class Solution {
public:
    int findMin(vector<int>& nums) {
        int i,a,f=0;
        for(int i=0;i<nums.size()-1 && f==0;i++)
        {
            if(nums[i]>nums[i+1])
            {
                f=1;a=nums[i+1];
            }
        }
        if(f==0)
        {
            a=nums[0];
        }
        return a;
    }
}; 