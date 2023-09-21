#include<bits/stdc++.h>
using namespace std;

/*

Brute force is to aplly linear search O(n)

Optimised O(log n) binary search

0 1 2 3 4 5 6 
2 5 6 0 0 1 2 

t = 3
h = 6 low = 0 mid = 3
h = 6 low = 4 mid = 5
h = 6 low = 6 mid = 6 // return


0 1 2 3 4
1 0 1 1 1

h = 4 l = 0 m = 2

*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
      int start = 0;
        int end = nums.size() - 1;
        
        // Check if the array is empty, return -1 if empty
        if (nums.size() == 0) return -1;

        // Check if there is only one element in the array
        if (start == end) {
            if (nums[start] == target) return true; // Return the index if target found, else return -1
            else return false;
        }
         
        // Binary search algorithm
        while (start <= end) {
            int mid = (start + end) / 2; // Calculate the middle index

            if (nums[mid] == target) return true; // Return the index if target found

            // edges case and main case for this problem
            if(nums[mid] == nums[end] && nums[mid] == nums[start]) end--,start++;

            // Check if the left half of the array is sorted
            else if (nums[start] <= nums[mid]) {
                // Check if the target is within the sorted left half
                if (nums[start] <= target && nums[mid] > target) {
                    end = mid - 1; // Update the end index to search in the left half
                } else {
                    start = mid + 1; // Update the start index to search in the right half
                }
            } else { // If the right half is sorted
                // Check if the target is within the sorted right half
                if (nums[mid] < target && nums[end] >= target) {
                    start = mid + 1; // Update the start index to search in the right half
                } else {
                    end = mid - 1; // Update the end index to search in the left half
                }
            }
        }

        return false; // Return -1 if the target is not found in the array
    }
};

int main(){}