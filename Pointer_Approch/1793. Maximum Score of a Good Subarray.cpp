class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) {
        int left = k, right = k;  // Initialize two pointers at index k.
        int min_val = nums[k];    // Initialize the minimum value with the element at index k.
        int max_score = min_val;  // Initialize the maximum score with the value at index k.

        while (left > 0 || right < nums.size() - 1) {
            if (left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1])) {
                right++;  // Move the right pointer to the right if it's smaller or if it's at the end.
            } else {
                left--;   // Move the left pointer to the left if it's smaller or if it's at the beginning.
            }
            min_val = std::min(min_val, std::min(nums[left], nums[right]));  // Update the minimum value.
            max_score = std::max(max_score, min_val * (right - left + 1));   // Update the maximum score.
        }
        
        return max_score;  // Return the maximum score.
    }
};