#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// ## this question is part of median algorithm which is hard and for SDE 2 roles. This concept are present in algorithm book
int getDis(const vector<int>& dist_centers, const vector<int>& pfSums, int startIdx, int endIdx) {
    int midIdx = startIdx + (endIdx - startIdx) / 2;
    int retDis = 0;

    if (midIdx == startIdx) {
        retDis = pfSums[endIdx + 1] - pfSums[startIdx] - dist_centers[midIdx] * (endIdx - startIdx + 1);
    } else if (midIdx == endIdx) {
        retDis = dist_centers[midIdx] * (endIdx - startIdx + 1) - (pfSums[endIdx + 1] - pfSums[startIdx]);
    } else {
        retDis = dist_centers[midIdx] * (midIdx - startIdx + 1) - (pfSums[midIdx + 1] - pfSums[startIdx]) +
                 (pfSums[endIdx + 1] - pfSums[midIdx + 1]) - dist_centers[midIdx] * (endIdx - midIdx);
    }

    return retDis;
}

int minSumDistancesToWarehouses(vector<int>& dist_centers) {
    int dLen = dist_centers.size();
    if (dLen == 2) return 0;

    // Sort the distance centers
    sort(dist_centers.begin(), dist_centers.end());

    // Prefix sums
    vector<int> pfSums(dLen + 1, 0);
    for (int i = 1; i <= dLen; ++i) {
        pfSums[i] = pfSums[i - 1] + dist_centers[i - 1];
    }

    int retMinDis = INT_MAX;
    for (int i = 0; i < dLen - 1; ++i) {
        int leftDis = getDis(dist_centers, pfSums, 0, i);
        int rightDis = getDis(dist_centers, pfSums, i + 1, dLen - 1);
        retMinDis = min(retMinDis, leftDis + rightDis);
    }

    return retMinDis;
}

// Driver code to test the function
int main() {
    vector<int> dist_centers = {1, 5, 9, 12};
    cout << "Minimum Sum of Distances to Warehouses: " << minSumDistancesToWarehouses(dist_centers) << endl;

    return 0;
}