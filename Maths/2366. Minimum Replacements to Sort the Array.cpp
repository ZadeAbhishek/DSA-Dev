class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        int n = nums.size();

        long long ans = 0;

        int prev = nums[n-1];

        for(int i = n - 2 ; i >= 0 ; i--){

            // check if the curr element is divisible by the next element
            // if it is divisilbe get the qutiont will present how many
            // we need to substract from it
            int numOfTimes = nums[i]/prev;

            // check if completlky divsible or not if not change prev to qutiont
            // for exapmlr 10/3 = 3 3 3 1 prev will be 1
            if((nums[i]%prev != 0)){
                numOfTimes++;
                prev= nums[i]/numOfTimes;
            }

            ans += numOfTimes-1;
        }

        return ans;        
    }
};