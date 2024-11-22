#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int calculateBeautyValues(const vector<int>& arr, const vector<vector<int>>& pairs) {
    int n = arr.size();
    vector<bool> used(n, false); // Track used indexes
    vector<int> beautifulArray;   // Store elements in the beautiful array

    // Process each pair and append the subarray to the beautiful array
    for (const auto& pair : pairs) {
        int start = pair[0];
        int end = pair[1];
        for (int i = start; i <= end; i++) {
            beautifulArray.push_back(arr[i]);
            used[i] = true;
        }
    }

    // Calculate the count of values exactly lesser than the values at the unused indexes
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) { // Check unused indexes
            for (int value : beautifulArray) {
                if (value < arr[i]) {
                    count++;
                }
            }
        }
    }

    return count;
}

// Driver code to test the function
int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 5};
    vector<vector<int>> pairs = {{0, 1}, {3, 4}, {0, 0}, {3, 4}};
    
    int result = calculateBeautyValues(arr, pairs);
    cout << "The beauty value is: " << result << endl; // Expected output: 12

    return 0;
}