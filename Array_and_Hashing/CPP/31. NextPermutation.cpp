#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the first element that is smaller than its next element
        int start = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                start = i;
                break;
            }
        }
        
        // Calculate the next greater element after 'start'
        if (start != -1) {
            for (int i = nums.size() - 1; i > start; i--) {
                if (nums[i] > nums[start]) {
                    swap(nums[start], nums[i]);
                    break;
                }
            }
        }
        
        // Reverse all elements after 'start'
        int end = nums.size() - 1;
        start += 1; 
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }  
    }
};

int main() {
    Solution solution;

    // Test case: Find the next permutation
    vector<int> nums = {1, 2, 3};
    cout << "Original Permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    solution.nextPermutation(nums);
    cout << "\nNext Permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
