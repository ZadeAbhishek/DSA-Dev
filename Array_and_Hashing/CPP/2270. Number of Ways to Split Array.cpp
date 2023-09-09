#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Calculate the total sum of all elements in the 'nums' vector
        long long total = 0;
        for (auto &x : nums) {
            total += x;
        }
        
        int count = 0; // Initialize a count variable to track valid partitions
        int n = nums.size();
        long long sum = 0; // Initialize a sum variable to track the current partition sum
        
        // Iterate through the 'nums' vector, excluding the last element
        for (int part = 0; part < n - 1; part++) {
            sum += nums[part]; // Add the current element to the partition sum
            // Check if the sum of the current partition is greater than or equal to
            // the remaining sum of the array (total - sum)
            if (sum >= (total - sum)) {
                count++; // If true, increment the count
            }
        }

        return count; // Return the count of valid partitions
    }
};

// Driver function to test the 'waysToSplitArray' function
int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case: Example input
    vector<int> nums = {1, 2, 2, 2, 5, 0};
    int result = solution.waysToSplitArray(nums);

    // Print the result
    cout << "Number of ways to split the array: " << result << endl;

    return 0;
}
