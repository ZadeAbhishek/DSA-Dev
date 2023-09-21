// Same floyd's Hair and Rabit problem
// FInd the same repeating number in array 
// Only one number in array is going to repeat
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1; // Handle the edge case of an empty array
        }

        // Initialize two pointers, slow and fast
        int slow = nums[0];
        int fast = nums[0];

        // Move slow one step at a time and fast two steps at a time until they meet
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break; // Loop detected, exit the loop
            }
        }

        // Reset one of the pointers and continue moving them at the same pace
        int slow2 = nums[0];
        while (slow2 != slow) {
            slow2 = nums[slow2];
            slow = nums[slow];
        }

        return slow; // The meeting point is the duplicate number
    }
};

int main() {
    vector<int> Array = {1, 3, 4, 2, 2};
    Solution* solve = new Solution();
    int result = solve->findDuplicate(Array);
    cout << "The duplicate number is: " << result << endl;
    return 0;
}
