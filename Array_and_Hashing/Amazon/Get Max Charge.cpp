#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

// Memoization map to store already computed results
unordered_map<string, long> memo;

long helper(vector<int>& charge) {
    // Base case: if there is only one system, return its charge
    if (charge.size() == 1) return charge[0];

    // Generate a unique key for the current configuration for memoization
    string key;
    for (int c : charge) key += to_string(c) + ",";

    // Check if result for this configuration is already computed
    if (memo.find(key) != memo.end()) return memo[key];

    long max_charge = LONG_MIN;

    // Try removing each element except the first and last
    for (int i = 1; i < charge.size() - 1; i++) {
        // Create a new charge array after removing the i-th element
        vector<int> new_charge = charge;
        new_charge[i - 1] += new_charge[i + 1]; // Combine neighbors
        new_charge.erase(new_charge.begin() + i, new_charge.begin() + i + 2); // Remove i and its neighbor

        // Recurse and update max_charge
        max_charge = max(max_charge, helper(new_charge));
    }

    // Edge case: If we have only two elements, removing one of them
    if (charge.size() == 2) {
        max_charge = max(charge[0], charge[1]);
    }

    // Store result in memo
    memo[key] = max_charge;
    return max_charge;
}

long getMaxCharge(vector<int>& charge) {
    memo.clear(); // Clear the memoization map before starting
    return helper(charge); // Start the recursive process
}

int main() {
    vector<int> charge = {-3, 1, 4, -1, 5, -9};
    cout << "Max Charge: " << getMaxCharge(charge) << endl;
    return 0;
}