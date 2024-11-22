#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

// Function to calculate the median of a subarray
int median(const vector<int>& arr, int start, int end) {
    int length = end - start + 1;
    if (length % 2 == 0) {
        return (arr[start + length / 2 - 1] + arr[start + length / 2]) / 2;
    } else {
        return arr[start + length / 2];
    }
}

// Function to calculate the minimum total distance
// ##Median ##standardDeviation
int getMinTotalDistance(vector<int>& dist_centers) {
    // Sort the distribution centers
    sort(dist_centers.begin(), dist_centers.end());
    int n = dist_centers.size();

    // Initialize the minimum distance sum to a large number
    int minDistanceSum = INT_MAX;

    // Try different partition points
    for (int i = 1; i < n; i++) {
        // Calculate medians for the two partitions
        int median1 = median(dist_centers, 0, i - 1);
        int median2 = median(dist_centers, i, n - 1);

        int currentDistanceSum = 0;

        // Calculate distance sum to the nearest median for each center
        for (int center : dist_centers) {
            int distanceToClosestWarehouse = min(abs(center - median1), abs(center - median2));
            currentDistanceSum += distanceToClosestWarehouse;
        }

        // Update minimum distance sum
        minDistanceSum = min(minDistanceSum, currentDistanceSum);
    }

    return minDistanceSum;
}

// Driver code to test the function
int main() {
    vector<int> dist_centers = {1, 5, 9, 13};
    int result = getMinTotalDistance(dist_centers);
    cout << "Minimum total distance: " << result << endl; // Expected output: Depends on input

    return 0;
}