#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// ##minHeap
long getMaximumSum(const vector<int>& health, const vector<int>& serverType, int k) {
    unordered_map<int, int> typeHealthMap;
    
    // Sum health values for each server type
    for (size_t i = 0; i < serverType.size(); i++) {
        typeHealthMap[serverType[i]] += health[i];
    }
    
    // Min-heap to store top k highest health sums
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (const auto& [type, totalHealth] : typeHealthMap) {
        minHeap.push(totalHealth);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // Sum the top k values from the heap
    long result = 0;
    while (!minHeap.empty()) {
        result += minHeap.top();
        minHeap.pop();
    }
    
    return result;
}

// Driver code to test the function
int main() {
    vector<int> health = {10, 15, 20, 5, 25};
    vector<int> serverType = {1, 1, 2, 2, 3};
    int k = 2;

    long result = getMaximumSum(health, serverType, k);
    cout << "Maximum health sum with up to " << k << " types: " << result << endl;

    return 0;
}