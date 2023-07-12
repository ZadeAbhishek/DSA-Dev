/// https://www.youtube.com/watch?v=bcAwHkL7A3A&ab_channel=CodewithAlisha

// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    
    int get_max_sum_minimun_elemnt(vector<int>& nums, int maxSum){
        int count = 1;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(sum + nums[i] > maxSum){
                count++;
                sum = nums[i];
            }
            else sum += nums[i];
        }
        
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        // binary search is used bloddy i dont know why it is used
        int low = *max_element(nums.begin(),nums.end()); // max element of nums
        int high = accumulate(nums.begin(),nums.end(),0); // sum of all elements
    
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;
            int currMaxPartition = get_max_sum_minimun_elemnt(nums,mid);
            if(currMaxPartition > k) low = mid + 1;
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};