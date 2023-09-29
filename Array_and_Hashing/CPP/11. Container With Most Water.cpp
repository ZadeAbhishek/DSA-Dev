#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = INT_MIN;

        // Use two-pointer approach to find the maximum area
        while (left < right) {
            // Calculate the height as the minimum of the two heights
            int height = min(heights[left], heights[right]);
            
            // Calculate the width as the difference between right and left pointers
            int width = right - left;

            // Calculate the area
            int area = height * width;

            // Update the maximum area if the current area is greater
            maxArea = max(maxArea, area);

            // Move the pointers based on the shorter height
            if (heights[left] < heights[right]) {
                left++;
            } else if (heights[left] > heights[right]) {
                right--;
            } else {
                // If both heights are equal, move both pointers towards the center
                left++;
                right--;
            }
        }

        return maxArea;
    }
};

int main(){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << "Maximum Area: " << s.maxArea(arr) << endl;
    return 0;
}
