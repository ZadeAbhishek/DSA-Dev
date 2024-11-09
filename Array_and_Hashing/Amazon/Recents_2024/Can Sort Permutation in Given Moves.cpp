#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int calculateMinSwaps(const vector<int>& p) {
    int n = p.size();
    unordered_map<int, bool> visited; // Hashmap to track visited elements
    int cycles = 0;

    // Find cycles in the permutation using hashmap
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int j = i;
            int cycle_length = 0;

            // Traverse through the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = p[j] - 1; // Move to the next index in the cycle
                cycle_length++;
            }

            if (cycle_length > 1) {
                cycles++;
            }
        }
    }

    // The minimum swaps needed to sort the permutation
    return n - cycles;
}

string getLongestSubstring(const vector<int>& p, const vector<int>& moves) {
    int min_swaps = calculateMinSwaps(p);
    string result;

    // Check each move
    for (int move : moves) {
        // Check if it's possible to sort with exactly `move` swaps
        if (move >= min_swaps && (move % 2 == min_swaps % 2)) {
            result += '1';
        } else {
            result += '0';
        }
    }

    return result;
}

// Example usage
int main() {
    vector<int> p = {2, 3, 1, 4};
    vector<int> moves = {2, 3};

    string result = getLongestSubstring(p, moves);
    cout << result << endl; // Output should be "10"

    return 0;
}