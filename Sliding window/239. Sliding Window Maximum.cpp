#include <iostream>
#include <vector>
#include<queue>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int x = 0, y = 0;  // Initialize two pointers for the sliding window
        std::vector<int> result;  // Store the maximum values for each window
        std::priority_queue<std::pair<int, int>> heap;  // A max heap to keep track of elements in the window

        while (y < nums.size()) {  // Iterate through the array
            int curr_Length = (y - x + 1);  // Current window length

            // If the current length is less than or equal to k, add the element to the heap and move the window
            if (curr_Length <= k) {
                heap.push({nums[y], y});  // Add the current element to the max heap along with its index
                y++;  // Move the right pointer to expand the window
            }
            
            // If the current length equals k, process the window and update the result
            if (curr_Length == k) {
                // Remove elements from the heap that are no longer in the current window (before the left pointer)
                while (!heap.empty() && heap.top().second < x) heap.pop();
                
                result.push_back(heap.top().first);  // The maximum element in the current window is at the top of the heap
                x++;  // Move the left pointer to slide the window to the right
            }
        }

        return result;  // Return the list of maximum elements for each window
    }
};


int main() {
    Solution solution;  // Create an instance of the Solution class

    // Example input array and window size
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // Call the maxSlidingWindow function
    std::vector<int> result = solution.maxSlidingWindow(nums, k);

    // Display the result
    std::cout << "Maximum values in each sliding window: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
