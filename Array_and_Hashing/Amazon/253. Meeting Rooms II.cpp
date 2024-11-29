#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Min-heap to keep track of end times of meetings in rooms
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 3: Process each meeting
        for (auto interval : intervals) {
            if (!minHeap.empty() && minHeap.top() <= interval[0]) {
                // Room becomes free, so remove the top
                minHeap.pop();
            }
            // Allocate the room (add current meeting end time to heap)
            minHeap.push(interval[1]);
        }

        // The size of the heap is the minimum rooms required
        return minHeap.size();
    }
};

// Driver Code
int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Minimum number of meeting rooms required: " 
         << solution.minMeetingRooms(intervals1) << endl; // Output: 2
    
    // Test case 2
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << "Minimum number of meeting rooms required: " 
         << solution.minMeetingRooms(intervals2) << endl; // Output: 1
    
    // Test case 3
    vector<vector<int>> intervals3 = {{1, 5}, {2, 3}, {4, 6}};
    cout << "Minimum number of meeting rooms required: " 
         << solution.minMeetingRooms(intervals3) << endl; // Output: 2
    
    // Test case 4
    vector<vector<int>> intervals4 = {{1, 10}, {2, 3}, {4, 5}, {6, 7}, {8, 9}};
    cout << "Minimum number of meeting rooms required: " 
         << solution.minMeetingRooms(intervals4) << endl; // Output: 3
    
    return 0;
}