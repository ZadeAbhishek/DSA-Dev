#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwapsToSort(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> sortedArr;
    
    // Store the element along with its original index
    for (int i = 0; i < n; i++) {
        sortedArr.push_back({arr[i], i});
    }
    
    // Sort the array by value
    sort(sortedArr.begin(), sortedArr.end());

    // Visited array to keep track of visited elements
    vector<bool> visited(n, false);
    int swaps = 0;

    // Cycle decomposition to count swaps
    for (int i = 0; i < n; i++) {
        // If the element is already visited or in the correct position
        if (visited[i] || sortedArr[i].second == i) {
            continue;
        }

        // Find the size of the cycle
        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            // Move to the index of the element in sorted array
            j = sortedArr[j].second;
            cycle_size++;
        }

        // If there is a cycle of size > 1, then (cycle_size - 1) swaps are needed
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}

// Driver code
int main() {
    vector<int> p = {1, 3, 2, 4};
    cout << "Minimum swaps to sort: " << minSwapsToSort(p) << endl;  // Expected output: 2
    return 0;
}