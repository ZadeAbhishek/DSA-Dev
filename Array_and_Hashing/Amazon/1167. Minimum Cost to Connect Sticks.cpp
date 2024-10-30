#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to connect sticks with minimal cost
// ##priority_queueu ##minHeap
int connectSticks(vector<int>& sticks) {
    if (sticks.size() <= 1) return 0;

    priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }

    return totalCost;
}

// Function to run a single test case
void runTestCase(const vector<int>& sticks, int expected) {
    vector<int> sticksCopy = sticks;  // Copy to avoid modifying original test data
    int result = connectSticks(sticksCopy);
    cout << "Result: " << result << " | Expected: " << expected 
         << " | " << (result == expected ? "Pass" : "Fail") << endl;
}

int main() {
    // Test Case 1: Simple example
    runTestCase({2, 4, 3}, 14);  // Expected output: 14

    // Test Case 2: Different small numbers
    runTestCase({1, 8, 3, 5}, 30);  // Expected output: 30

    // Test Case 3: Single stick
    runTestCase({5}, 0);  // Expected output: 0

    // Test Case 4: More varied numbers
    runTestCase({5, 2, 4, 7, 6}, 54);  // Expected output: 51

    // Test Case 5: Ascending sequence
    runTestCase({1, 2, 3, 4, 5}, 33);  // Expected output: 33

    // Complex Test Case 1: Larger numbers
    runTestCase({10, 15, 20, 30, 50}, 270);  // Expected output: 220

    // Complex Test Case 2: Large dataset
    runTestCase({100, 200, 300, 400, 500, 600, 700, 800, 900}, 8600);  // Expected output: 8600

    // Complex Test Case 3: All elements are the same
    runTestCase({10, 10, 10, 10, 10}, 90);  // Expected output: 90

    // Complex Test Case 4: Large numbers with varying gaps
    runTestCase({1000, 500, 2000, 1500, 3000}, 11500);  // Expected output: 11500

    // Complex Test Case 5: Edge case - empty vector
    runTestCase({}, 0);  // Expected output: 0

    return 0;
}