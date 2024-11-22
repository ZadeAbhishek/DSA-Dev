#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

using namespace std;

// Helper function to check if a given capacity can distribute all games among k pen drives
bool canDistributeGames(const vector<int>& gameSize, int k, int capacity) {
    int n = gameSize.size();
    int penDrivesUsed = 0;
    int left = 0, right = n - 1;

    // Try to pair games optimally within the capacity constraint
    while (left <= right) {
        if (gameSize[right] > capacity) {
            return false;  // If any single game exceeds capacity, it's impossible
        }

        // Use a new pen drive and try to add up to two games
        int currentPenDriveCapacity = 0;
        int gamesInCurrentPenDrive = 0;

        // Add the largest game that fits
        if (gameSize[right] <= capacity) {
            currentPenDriveCapacity += gameSize[right];
            gamesInCurrentPenDrive++;
            right--;
        }

        // Add the smallest game that fits if there is room and only if it does not exceed 2 games
        if (left <= right && gamesInCurrentPenDrive < 2 && currentPenDriveCapacity + gameSize[left] <= capacity) {
            currentPenDriveCapacity += gameSize[left];
            gamesInCurrentPenDrive++;
            left++;
        }

        // Increment pen drive usage counter
        penDrivesUsed++;

        // If we exceed the number of available pen drives, return false
        if (penDrivesUsed > k) {
            return false;
        }
    }

    return penDrivesUsed <= k;
}

int getMinSize(vector<int>& gameSize, int k) {
    sort(gameSize.begin(), gameSize.end());
    int low = gameSize.back();  // Minimum capacity must be at least the size of the largest game
    int high = INT_MAX;  // Sum of two largest games

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canDistributeGames(gameSize, k, mid)) {
            result = mid;  // Try to find a smaller feasible capacity
            high = mid - 1;
        } else {
            low = mid + 1;  // Increase capacity
        }
    }

    return result;
}

// Driver code to test the function
int main() {
    vector<int> gameSize = {9, 2, 4, 6};
    int k = 3;
    int result = getMinSize(gameSize, k);
    cout << "Minimum pen drive capacity required: " << result << endl; // Expected output: 9

    return 0;
}