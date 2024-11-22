#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
// ##slidingWindow
int maximumPossibleRacers(const vector<int>& speed, int k) {
    int max_length = 0;
    int left = 0;
    unordered_map<int, int> countMap;
    int max_freq = 0;

    for (int right = 0; right < speed.size(); ++right) {
        countMap[speed[right]]++;
        max_freq = max(max_freq, countMap[speed[right]]);

        // Number of racers that we need to "remove" to make the segment uniform
        int racers_to_remove = (right - left + 1) - max_freq;

        if (racers_to_remove > k) {
            // If more than k racers need to be removed, shrink the window from the left
            countMap[speed[left]]--;
            if (countMap[speed[left]] == 0) {
                countMap.erase(speed[left]);
            }
            left++;
        }

        // Update the maximum length of any valid window
        max_length = max(max_length, right - left + 1);
    }

    return max_length;
}

// Driver code to test the function
int main() {
    vector<int> speed = {1, 2, 2, 2, 1, 1, 1, 2};
    int k = 2;
    int result = maximumPossibleRacers(speed, k);
    cout << "Maximum possible number of racers in a contiguous segment with the same speed: " << result << endl; // Expected output: 5

    return 0;
}