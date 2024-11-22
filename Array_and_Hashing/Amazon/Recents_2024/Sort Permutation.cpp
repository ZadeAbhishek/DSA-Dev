#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to calculate the minimum number of swaps required to sort the permutation
int calculateMinimumSwaps(const vector<int>& p) {
    int n = p.size();
    vector<bool> visited(n, false);
    int min_swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || p[i] == i + 1) {
            continue;  // Skip if already visited or already in correct position
        }

        int cycle_size = 0;
        int j = i;

        // Traverse the cycle and count its size
        while (!visited[j]) {
            visited[j] = true;
            j = p[j] - 1;  // Move to the next index in the cycle
            cycle_size++;
        }

        // Each cycle of size k requires (k - 1) swaps to sort
        if (cycle_size > 1) {
            min_swaps += (cycle_size - 1);
        }
    }

    return min_swaps;
}

// Function to determine if it's possible to sort in exactly the given moves
string sortPermutation(const vector<int>& p, const vector<int>& moves) {
    int min_moves = calculateMinimumSwaps(p);
    string result;

    for (int move : moves) {
        // Check if move count is exactly the minimum or possible with redundant moves
        if (move >= min_moves && (move - min_moves) % 2 == 0) {
            result += '1';  // Possible to sort in exactly `move` moves
        } else {
            result += '0';  // Not possible
        }
    }

    return result;
}

// Driver code to test the function
int main() {
    vector<int> p = {4, 3, 2, 1};  // Example permutation
    vector<int> moves = {3, 2, 4};  // Number of moves to check

    string result = sortPermutation(p, moves);
    cout << "Result: " << result << endl;  // Expected output: "011"

    return 0;
}