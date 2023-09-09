#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap(nums.begin(), nums.end());
        for(int i = 1; i < k; i++) heap.pop();
        return heap.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Convert k to the index of the kth largest element (0-based index)
        k = (nums.size()) - k;

        int start = 0;          // Initialize the start index for binary search
        int end = nums.size() - 1; // Initialize the end index for binary search
        int index = start;      // Initialize an index variable for partitioning

        while (start <= end) {
            int pivot = nums[end]; // Choose the pivot element (usually the last element)
            int i = start - 1;    // Initialize a variable for the partitioning index

            // Partition the array such that elements less than or equal to the pivot
            // are moved to the left, and elements greater than the pivot are moved to the right
            for (int j = start; j < end; j++) {
                if (nums[j] <= pivot) {
                    i++;
                    // Swap nums[i] and nums[j]
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }

            i++;
            // Swap nums[i] and nums[end] to place the pivot in its correct position
            int temp = nums[end];
            nums[end] = nums[i];
            nums[i] = temp;

            // If the desired kth largest element is on the left side of the pivot
            if (k < i) {
                end = i - 1;   // Update the end index for the left subarray
                start = 0;     // Reset the start index for the left subarray
            }
            // If the desired kth largest element is on the right side of the pivot
            else if (k > i) {
                start = i + 1; // Update the start index for the right subarray
            }
            // If the desired kth largest element is at the pivot position
            else {
                return nums[i]; // Return the kth largest element
            }
        }

        return -1; // Return -1 if k is out of bounds
    }
};


void drive() {
    vector<int> nums = {2,1,7,88,964};
    // sort(nums.begin(),nums.end());
    // reverse(nums.begin(),nums.end());
    int k = 4;

    Solution3 sol1;
    Solution2 sol2;

    cout << "Using Solution1: " << sol1.findKthLargest(nums, k) << endl;
    cout << "Using Solution2: " << sol2.findKthLargest(nums, k) << endl;
}

int main() {
    drive();
    return 0;
}
