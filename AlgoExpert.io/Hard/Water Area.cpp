// This function is O(n) SC AND TC

#include <vector>
#include <algorithm>  // For max and min functions

using namespace std;

int waterArea(vector<int> heights) {
    if (heights.empty()) return 0;

    vector<int> leftLargest(heights.size(), 0);
    vector<int> rightLargest(heights.size(), 0);

    int maxLeft = heights[0];
    int maxRight = heights[heights.size() - 1];
    int total = 0;

    // Fill leftLargest array
    for (int i = 0; i < heights.size(); i++) {
        leftLargest[i] = maxLeft;
        maxLeft = max(maxLeft, heights[i]);
    }

    // Fill rightLargest array
    for (int i = heights.size() - 1; i >= 0; i--) {
        rightLargest[i] = maxRight;
        maxRight = max(maxRight, heights[i]);
    }

    // Calculate total water area
    for (int i = 0; i < heights.size(); i++) {
        int currentMin = min(leftLargest[i], rightLargest[i]);
        if (currentMin > heights[i]) {
            total += currentMin - heights[i];
        }
    }

    return total;
}

// this approch is O(n) tc and O(1) sc
#include <vector>
#include <algorithm>  // For min and max functions

using namespace std;

int waterArea(vector<int> heights) {
    if (heights.empty()) return 0;

    int left = 0;
    int right = heights.size() - 1;
    int maxLeft = heights[left];
    int maxRight = heights[right];
    int total = 0;

    while (left < right) {
        if (heights[left] < heights[right]) {
            if (heights[left] >= maxLeft) {
                maxLeft = heights[left];  // Update maxLeft
            } else {
                total += maxLeft - heights[left];  // Water trapped on the left
            }
            left++;
        } else {
            if (heights[right] >= maxRight) {
                maxRight = heights[right];  // Update maxRight
            } else {
                total += maxRight - heights[right];  // Water trapped on the right
            }
            right--;
        }
    }

    return total;
}