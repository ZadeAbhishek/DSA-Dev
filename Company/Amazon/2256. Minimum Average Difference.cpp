#include <iostream>
#include <vector>
#include <cmath>
#include <limits> // Include this header for INT_MAX

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int pre = 0;
        int pos = nums.size() - 1;
        long long int prevCal = 0;
        long long int postCal = 0;
        vector<double> prevCalArray(nums.size());
        vector<double> postCalArray(nums.size());
        
        // cal Prev Sum array
        for (int i = 0; i < nums.size(); i++) {
            prevCal += nums[i];
            prevCalArray[i] = prevCal / (i + 1);
        }

        // cal Post sum array
        for (int i = nums.size(); i > 0; i--) {
            postCal += nums[i - 1];
            postCalArray[i - 1] = postCal / (nums.size() - i + 1);
        }

        // get the minimum array
        long long int minDiff = numeric_limits<long long int>::max(); // Using numeric_limits to get maximum value
        int Index = 0;
        for (int i = 0; i < nums.size(); i++) {
            int CurrMin = 0;
            if (i + 1 < nums.size())
                CurrMin = abs(prevCalArray[i] - postCalArray[i + 1]);
            else 
                CurrMin = abs(prevCalArray[i]);

            if (CurrMin < minDiff) {
                Index = i;
                minDiff = CurrMin;
            }
        }
        return Index;
    }
}; 

int main() {
    Solution solution;
    vector<int> nums = {3, 1, 2, 4, 3};
    cout << "Minimum Average Difference Index: " << solution.minimumAverageDifference(nums) << endl;
    return 0;
}
