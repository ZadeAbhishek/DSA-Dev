
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

// optimised

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int lenght = nums.size();
        int end = lenght - 2;
        int start = 1;
        vector<int> minFromEndToStart(lenght,0);
        vector<int> maxFromStartToEnd(lenght,0);
        minFromEndToStart[lenght - 1] = nums[lenght - 1];
        maxFromStartToEnd[start - 1] = nums[start - 1]; 
        for(int i = 1 ; i < lenght ; i++){
            maxFromStartToEnd[i] = max(nums[i],maxFromStartToEnd[i - 1]);
            minFromEndToStart[lenght - i - 1] = min(nums[lenght - i - 1],minFromEndToStart[lenght - i]);
        }
        int sum = 0;
        while(start <= end){
            int current = nums[start];
            int currentMin = minFromEndToStart[start + 1];
            int currentMax = maxFromStartToEnd[start - 1];
            if(currentMin > current && currentMax < current) sum+=2;
            else if(nums[start - 1] <  nums[start] && nums[start] < nums[start + 1]) sum+=1;
            start++; 
        }

        return sum;
    }
};