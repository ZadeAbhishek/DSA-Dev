
// TLE error
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        // two pointer is brute force approch i suppose
        // here i = current
        // j = i  > j 
        // k = i < k
        int start = 1; // always start from i
        int end = nums.size() - 2;
        int lenght = end + 1;
        int sum = 0;
        while(start <= end){
            
            int current = nums[start];
            int j = 0;
            int k = lenght;
            int flagConditionOne = 1;
            int flagConditionTwo = 1;
            // check of condition 1
            // we have to check for all
            while(j < start){
                if(nums[j] >= nums[j + 1] || nums[j] > nums[start]){
                    flagConditionOne = 0;
                    break;
                }
                j++;
            }
            while(k > start){
                if(nums[k] <= nums[k-1] || nums[k] < nums[start]){
                    flagConditionTwo = 0;
                    break;
                }
                k--;
            }

           // check of condition 1
            if(flagConditionOne && flagConditionTwo){
                sum += 2;
            }
            // check of condition 2
            else if(nums[start - 1] < nums[start] && nums[start] < nums[start+1]){
                sum += 1;
            }
            start++;
        }
        return sum;
    }
};