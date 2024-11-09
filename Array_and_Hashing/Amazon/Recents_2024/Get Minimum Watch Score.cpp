#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

int getMinScore(const vector<int>& watch_history, int series1, int series2) {
    int n = watch_history.size();
    int left = 0;
    int min_score = INT_MAX;
    int last_series1 = -1, last_series2 = -1;  // Track the last positions of series1 and series2
    unordered_set<int> distinct_elements;  // Track distinct elements in the current window

    for (int right = 0; right < n; ++right) {
        distinct_elements.insert(watch_history[right]);

        // Update the last seen positions of series1 and series2
        if (watch_history[right] == series1) {
            last_series1 = right;
        }
        if (watch_history[right] == series2) {
            last_series2 = right;
        }

        // If both series1 and series2 are present in the current window
        if (last_series1 != -1 && last_series2 != -1) {
            // Move the left pointer to the minimum position of last_series1 and last_series2
            left = min(last_series1, last_series2);

            // Calculate the distinct count in the current valid window
            min_score = min(min_score, static_cast<int>(distinct_elements.size()));

            // Shrink the window from the left if possible
            distinct_elements.erase(watch_history[left]);
            left++;  // Move the left pointer to exclude the first element in the window
        }
    }

    return min_score == INT_MAX ? 0 : min_score;
}

// Driver code to test the function
int main() {
    vector<int> watch_history = {1, 3, 2, 1, 4};
    int series1 = 1, series2 = 2;
    
    int result = getMinScore(watch_history, series1, series2);
    cout << "Minimum watch score: " << result << endl; // Expected output: 2

    return 0;
}