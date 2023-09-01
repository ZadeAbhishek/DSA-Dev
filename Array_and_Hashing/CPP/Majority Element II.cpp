#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to merge two sorted arrays
    vector<int> merge(vector<int> &x, vector<int> &y) {
        int len1 = x.size();
        int len2 = y.size();
        vector<int> result;
        int i, j;
        i = j = 0;
        while (i < len1 && j < len2) {
            if (x[i] < y[j]) {
                result.push_back(x[i]);
                i++;
            } else {
                result.push_back(y[j]);
                j++;
            }
        }
        while (i < len1) {
            result.push_back(x[i]);
            i++;
        }
        while (j < len2) {
            result.push_back(y[j]);
            j++;
        }
        return result;
    }

    // Function to perform merge sort
    vector<int> sort(vector<int> &arr, int low, int high) {
        vector<int> result;
        if (low == high) {
            result.push_back(arr[low]);
            return result;
        }
        int mid = (low + high) / 2;
        vector<int> x = sort(arr, low, mid);
        vector<int> y = sort(arr, mid + 1, high);
        result = merge(x, y);
        return result;
    }

    vector<int> majorityElement(vector<int> &nums) {
        // Sort the input array
        vector<int> sorted = sort(nums, 0, nums.size() - 1);

        vector<int> temp;
        int count = 1;
        int prev = sorted[0];

        if (count > sorted.size() / 3)
            temp.push_back(sorted[0]);

        for (auto i = 1; i < sorted.size(); i++) {
            if (sorted[i] == sorted[i - 1])
                count++;
            else
                count = 1;

            if (count == sorted.size() / 3 + 1) {
                temp.push_back(sorted[i]);
            }
        }

        return temp;
    }
};

int main() {
    Solution solution;
    
    // Test your majorityElement function with an example input
    vector<int> nums = {3, 2, 3};
    vector<int> result = solution.majorityElement(nums);

    cout << "Majority Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
