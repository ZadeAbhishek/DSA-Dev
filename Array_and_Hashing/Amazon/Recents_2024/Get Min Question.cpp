#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Most Fuck all Questions of all time This was 

// ##Greedy
long long getMinimumCost(vector<int>& costs, int pairCost, int k) {
    long long minCost = 0;

    // Sort costs in descending order
    sort(costs.rbegin(), costs.rend());

    // Calculate the minimum cost using pairs
    for (int i = 0; i < k; i++) {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        // Check if there are enough books left to pair
        if (leftIndex >= costs.size()) break;

        // If only one book is left, add its cost directly
        if (rightIndex >= costs.size()) {
            minCost += costs[leftIndex];
        } else {
            // Otherwise, add the minimum of pairCost or the sum of the two book costs
            minCost += min(pairCost, costs[leftIndex] + costs[rightIndex]);
        }
    }

    // Add remaining unpaired books, if any
    for (int i = 2 * k; i < costs.size(); i++) {
        minCost += costs[i];
    }

    return minCost;
}

// Driver function to test getMinimumCost
int main() {
    // Test case
    vector<int> costs = {1, 2, 3,4};
    int pairCost = 2;
    int k = 1;

    long long result = getMinimumCost(costs, pairCost, k);
    cout << "Output: " << result << endl;

    return 0;
}