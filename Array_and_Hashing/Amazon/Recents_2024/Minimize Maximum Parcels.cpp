#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if we can achieve max_load as the maximum load
// ##BinarySearch
bool canAchieveMaxLoad(const vector<int>& parcels, int extra_parcels, int max_load) {
    int required_parcels = 0;

    for (int parcel : parcels) {
        if (parcel < max_load) {
            required_parcels += (max_load - parcel);
        }
        if (required_parcels > extra_parcels) {
            return false;
        }
    }
    
    return required_parcels <= extra_parcels;
}

int minimizeMaxParcels(vector<int>& parcels, int extra_parcels) {
    int left = *max_element(parcels.begin(), parcels.end());  // Current max load
    int right = left + extra_parcels;  // Max load if we gave all extra parcels to one agent

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAchieveMaxLoad(parcels, extra_parcels, mid)) {
            result = mid;  // Try to minimize further
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

// Driver code
int main() {
    vector<int> parcels = {7, 5, 1, 9, 1};
    int extra_parcels = 25;
    cout << "Minimum possible value of maximum parcels: " << minimizeMaxParcels(parcels, extra_parcels) << endl;
    // Expected output: 10

    return 0;
}