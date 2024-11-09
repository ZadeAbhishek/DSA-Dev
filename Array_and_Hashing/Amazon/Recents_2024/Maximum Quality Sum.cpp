#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maximumQualitySum(vector<int>& packets, int channels) {
    int n = packets.size();

    // Condition: if there are more channels than packets, return -1
    if (channels > n) {
        return -1;
    }

    // Step 1: Sort packets in ascending order
    sort(packets.begin(), packets.end());

    long long sumOfMedians = 0;

    // Step 2: Calculate the sum of the largest packets as medians for the last `channels - 1` channels
    for (int i = n - (channels - 1); i < n; ++i) {
        sumOfMedians += packets[i];  // Single packet is the median for each of these channels
    }

    // Step 3: Calculate the median for the remaining packets in the first channel
    vector<int> remainingPackets(packets.begin(), packets.begin() + (n - channels + 1));
    int m = remainingPackets.size();

    if (m % 2 == 1) {
        // Odd number of elements, take the middle element
        sumOfMedians += remainingPackets[m / 2];
    } else {
        // Even number of elements, take the average of the two middle elements
        sumOfMedians += ceil((remainingPackets[m / 2 - 1] + remainingPackets[m / 2]) / 2.0);
    }

    // Step 4: Return the final sum of medians
    return static_cast<int>(sumOfMedians);
}

// Driver code to test the function
int main() {
    vector<int> packets = {1, 2, 3, 4, 5};
    int channels = 2;
    cout << "Maximum Quality Sum: " << maximumQualitySum(packets, channels) << endl; // Expected output: 8

    // Test case where channels > packets
    packets = {1, 2};
    channels = 4;
    cout << "Maximum Quality Sum: " << maximumQualitySum(packets, channels) << endl; // Expected output: -1

    return 0;
}