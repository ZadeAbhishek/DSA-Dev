#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the length of the longest increasing subsequence (LIS)
int lengthOfLIS(const vector<int>& arr) {
    vector<int> lis;
    for (int num : arr) {
        auto pos = lower_bound(lis.begin(), lis.end(), num);
        if (pos == lis.end()) {
            lis.push_back(num);
        } else {
            *pos = num;
        }
    }
    return lis.size();
}

// Function to calculate the minimum moves required to sort the array
int minMovesToSort(const vector<int>& arr) {
    int n = arr.size();
    int lisLength = lengthOfLIS(arr);
    return n - lisLength;
}

// Driver code
int main() {
    vector<int> p = {2, 3, 1, 4};
    cout << "Minimum moves to sort: " << minMovesToSort(p) << endl;  // Expected output: 1
    return 0;
}