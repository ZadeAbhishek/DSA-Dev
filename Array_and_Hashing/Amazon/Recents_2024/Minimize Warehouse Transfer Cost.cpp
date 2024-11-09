#include <iostream>
#include <vector>
#include <numeric>  // For std::accumulate
#include <cmath>    // For std::abs

using namespace std;

long long minimizeWarehouseTransferCost(const vector<int>& warehouses) {
    int n = warehouses.size();
    long long total_items = accumulate(warehouses.begin(), warehouses.end(), 0LL);
    int target = total_items / n;

    long long cumulative_balance = 0;
    long long min_cost = 0;
    
    // ##Kadane
    for (int items : warehouses) {
        int balance = items - target;
        cumulative_balance += balance; // get current balance 
        min_cost += abs(cumulative_balance);  // add cost to it
    }

    return min_cost;
}

// Driver code to test the function
int main() {
    // Example test case
    vector<int> warehouses = {6,6,6};

    long long result = minimizeWarehouseTransferCost(warehouses);
    cout << "Minimum transfer cost to balance warehouses: " << result << endl;

    return 0;
}