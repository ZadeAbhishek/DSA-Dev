#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findSubarrayWithMinimumDistinctIntegers(vector<int>& array, int series1, int series2) {
        if (series1 == series2) {
            // If both specified numbers are the same, check if the number exists in the array
            return count(array.begin(), array.end(), series1) > 0 ? 1 : 0;
        }

        unordered_map<int, int> tracker;  // Track counts of each element in the window
        int formed = 0;
        int left = 0, right = 0;
        int answer = INT_MAX;

        while (right < array.size()) {
            int d1 = array[right];
            tracker[d1]++;

            // Increment `formed` when we encounter one of the target numbers
            if (d1 == series1 || d1 == series2) {
                if (tracker[d1] == 1) { // Only count if it’s the first occurrence
                    formed++;
                }
            }

            // Shrink the window from the left as much as possible while containing both series1 and series2
            while (left <= right && formed == 2) {
                int d2 = array[left];
                answer = min(answer, static_cast<int>(tracker.size()));  // Track minimum distinct elements

                // Remove `d2` from the tracker
                tracker[d2]--;
                if (tracker[d2] == 0) {
                    tracker.erase(d2);  // Remove from map if count is 0
                }

                // If `d2` is one of the target numbers, decrement `formed` when fully removed
                if ((d2 == series1 || d2 == series2) && tracker[d2] == 0) {
                    formed--;
                }
                left++;  // Move left pointer to shrink the window
            }

            right++;  // Expand the window by moving right pointer
        }

        return answer == INT_MAX ? 0 : answer;
    }
};