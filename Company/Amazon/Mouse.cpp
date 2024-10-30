#include <bits/stdc++.h>
using namespace std;

int minTimeToCollectApples(vector<int>& positions, int k) {
    int n = positions.size();

    // Sort positions to help calculate minimum distance
    sort(positions.begin(), positions.end());

    // We will store the minimum time in a variable
    int minTime = INT_MAX;

    // Consider all possible windows of k apples
    for (int i = 0; i <= n - k; i++) {
        // Case 1: All apples are on one side (either left or right)
        // The time taken would be the distance to the furthest apple
        int leftMost = positions[i];
        int rightMost = positions[i + k - 1];

        // Two possible strategies:
        // 1. Go left to the leftmost apple and then to the rightmost one.
        // 2. Go right to the rightmost apple and then to the leftmost one.
        int option1 = abs(leftMost) + abs(rightMost - leftMost);
        int option2 = abs(rightMost) + abs(leftMost - rightMost);

        // Take the minimum of the two options
        minTime = min(minTime, min(option1, option2));
    }

    return minTime;
}

int main() {
    // Example input
    vector<int> positions = {-20, -10, 10, 20, 50};
    int k = 3; // Number of apples to collect

    int result = minTimeToCollectApples(positions, k);
    cout << "Minimum time to collect " << k << " apples: " << result << " seconds" << endl;

    return 0;
}