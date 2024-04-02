#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int nums_size = nums.size();
        int temp = nums_size;
        int minSwaps = INT_MAX;
        int noOfones = 0, index = 0 , windowSize = 0 , swaps = 0,start = 0;

        while (temp) {
            nums.push_back(nums[nums_size - temp]);
            noOfones += nums[nums_size - temp] ? 1 : 0;
            temp--;
        }
        
        while (start < nums_size) {
            if (windowSize == noOfones) {
                minSwaps = min(minSwaps, (windowSize - swaps));
                swaps -= nums[index - windowSize];
                windowSize--;
                start++;
            }
            swaps += nums[index];
            windowSize++;
            index++;
        }

        return minSwaps == INT_MAX ? 0 : minSwaps;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,0,1,1,0,0}; // Example input data
    int result = solution.minSwaps(nums);
    cout << "Minimum swaps required: " << result << endl;
    return 0;
}
