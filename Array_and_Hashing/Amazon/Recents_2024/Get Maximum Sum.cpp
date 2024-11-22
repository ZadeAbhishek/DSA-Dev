#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ##minHeap
long getMaximumSum(const vector<vector<int>>& data, const vector<int>& factor, int x) {
    int n = data.size();
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to track top x elements

    // Process each row
    for (int i = 0; i < n; ++i) {
        vector<int> row = data[i];
        sort(row.rbegin(), row.rend()); // Sort in descending order

        // Take the top 'factor[i]' elements from each row
        for (int j = 0; j < min(factor[i], (int)row.size()); ++j) {
            if (minHeap.size() < x) {
                minHeap.push(row[j]); // Add to heap if we haven't reached x elements yet
            } else if (row[j] > minHeap.top()) {
                minHeap.pop(); // Remove smallest in heap
                minHeap.push(row[j]); // Add larger element
            }
        }
    }

    // Check if we have exactly x elements
    if (minHeap.size() < x) {
        return -1; // Not enough elements to satisfy the requirement
    }

    // Calculate the maximum sum from the top x elements
    long maxSum = 0;
    while (!minHeap.empty()) {
        maxSum += minHeap.top();
        minHeap.pop();
    }

    return maxSum;
}

// Driver code to test the function
int main() {
    vector<vector<int>> data = {
        {10, 20, 30},
        {5, 15, 25},
        {1, 2, 3}
    };
    vector<int> factor = {2, 2, 1};
    int x = 4;

    long result = getMaximumSum(data, factor, x);
    cout << "Maximum sum: " << result << endl; // Expected output: 90

    return 0;
}