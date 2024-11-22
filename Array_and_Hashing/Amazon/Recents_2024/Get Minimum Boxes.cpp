// brute force approch
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinimumBoxes(vector<int>& boxes, int capacity) {
    int n = boxes.size();
    sort(boxes.begin(), boxes.end());
    
    int min_unloads = n; // Start with the maximum unloads possible (all boxes)
    
    for (int left = 0; left < n; ++left) {
        int min_box = boxes[left];
        
        for (int right = left; right < n; ++right) {
            int max_box = boxes[right];
            
            if (max_box <= capacity * min_box) {
                int kept_boxes = right - left + 1;
                min_unloads = min(min_unloads, n - kept_boxes);
            } else {
                break; // No need to check further if the condition fails
            }
        }
    }
    
    return min_unloads;
}

// Driver code to test the function
int main() {
    vector<int> boxes = {1, 4, 3, 2};
    int capacity = 2;
    int result = getMinimumBoxes(boxes, capacity);
    cout << "Minimum boxes to unload: " << result << endl; // Expected output: 1

    return 0;
}

// optimised approch 
// ##slidingWindow
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinimumBoxes(vector<int>& boxes, int capacity) {
    int n = boxes.size();
    sort(boxes.begin(), boxes.end());
    
    int min_unloads = n;  // Start with maximum unloads possible (unload all boxes)
    int left = 0;

    // Sliding window with right expanding
    for (int right = 0; right < n; ++right) {
        // Check if the current window [left...right] satisfies the condition
        while (boxes[right] > capacity * boxes[left]) {
            left++;  // Shrink the window from the left until the condition holds
        }
        
        // Calculate the unloads for the current window [left...right]
        int kept_boxes = right - left + 1;
        min_unloads = min(min_unloads, n - kept_boxes);
    }
    
    return min_unloads;
}

// Driver code to test the function
int main() {
    vector<int> boxes = {1, 4, 3, 2};
    int capacity = 2;
    int result = getMinimumBoxes(boxes, capacity);
    cout << "Minimum boxes to unload: " << result << endl; // Expected output: 1

    return 0;
}