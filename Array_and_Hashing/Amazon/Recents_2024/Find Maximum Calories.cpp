#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long findMaximumCalories(vector<int>& height) {
    // Step 1: Sort the heights in ascending order
    sort(height.begin(), height.end());
    int n = height.size();

    // Step 2: Initialize the total calorie burn
    long totalCalories = 0;

    // Step 3: Calculate the maximum calories burned with the jumping pattern
    // Start with the highest to lowest, then alternate
    int left = 0;
    int right = n - 1;

    // Calculate initial jump from highest to lowest
    totalCalories += pow(height[right] - height[left], 2);
    int prevHeight = height[left];
    left++;

    // Alternate jumps to maximize calorie burn
    while (left < right) {
        // Jump from previous position to the current right
        totalCalories += pow(prevHeight - height[right], 2);
        prevHeight = height[right];
        right--;

        // Jump from previous position to the current left
        if (left < right) {
            totalCalories += pow(prevHeight - height[left], 2);
            prevHeight = height[left];
            left++;
        }
    }

    return totalCalories;
}

// Driver code to test the function
int main() {
    vector<int> height = {5, 2, 5};
    cout << "Maximum Calories Burned: " << findMaximumCalories(height) << endl; // Expected output: 43

    return 0;
}