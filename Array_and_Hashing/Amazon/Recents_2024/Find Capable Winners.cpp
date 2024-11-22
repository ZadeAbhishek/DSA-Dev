#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// ##nextPermutation
// Revised `canDefeat` function
bool canDefeat(const vector<int>& X, const vector<int>& Y) {
    // Generate all possible arrangements of Y's boosters and check if X can win in each
    vector<int> perm = Y;
    int countWinPermutations = 0;

    do {
        int winCount = 0;
        for (int i = 0; i < 3; ++i) {
            if (X[i] > perm[i]) {
                winCount++;
            }
        }
        if (winCount >= 2) {
            countWinPermutations++;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    // Return true if X can win in all permutations of Y
    return countWinPermutations >= 4;
}

int findCapableWinners(vector<int>& power_a, vector<int>& power_b, vector<int>& power_c) {
    int n = power_a.size();
    int capableWinnersCount = 0;

    // Create a vector to store sorted power boosters for each player
    vector<vector<int>> players;
    for (int i = 0; i < n; ++i) {
        vector<int> boosters = {power_a[i], power_b[i], power_c[i]};
        sort(boosters.begin(), boosters.end());  // Sort to create [min, mid, max] representation
        players.push_back(boosters);
    }

    // Check each player to see if they can defeat all other players
    for (int i = 0; i < n; ++i) {
        bool isCapableWinner = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && !canDefeat(players[i], players[j])) {
                isCapableWinner = false;
                break;
            }
        }
        if (isCapableWinner) {
            capableWinnersCount++;
        }
    }

    return capableWinnersCount;
}

// Driver code to test the function
int main() {
    vector<int> power_a = {9, 2};
    vector<int> power_b = {5, 3};
    vector<int> power_c = {11, 1};
    
    int result = findCapableWinners(power_a, power_b, power_c);
    cout << "Number of capable winners: " << result << endl; // Expected output: 1

    return 0;
}