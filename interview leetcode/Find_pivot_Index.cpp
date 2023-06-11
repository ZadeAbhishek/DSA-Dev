#include<bits/stdc++.h>
using namespace std;

int main() {
        vector<int> nums = {2,1,-1};
        vector<int> left(nums.size());
        vector<int> right(nums.size());
            
        int prev = 0;
        int k = 1;
        left[0] = 0;
        while(k < size(nums))
        {
            left[k] = nums[k - 1] + prev;
            prev = left[k];
            k++;
        }
        
        prev = 0;
        k--;
        right[k] = 0;
        k--;
        //int k = size(nums) - 1;
        while(k >= 0)
        {
            right[k] = nums[k + 1] + prev;
            prev = right[k];
            k--;
        }
        
        int i = 0 , j = size(nums) - 1;
        while(i < j +1)
        {
            if(left[i] == right[i]) return i;
            i++;
        }
        
        return -1;
    }