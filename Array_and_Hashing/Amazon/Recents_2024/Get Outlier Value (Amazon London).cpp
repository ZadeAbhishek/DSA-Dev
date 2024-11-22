#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int getOutlierValue(const vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0); // Total sum of all elements in the array
    int n = arr.size();
    vector<int> outline;  // To store potential outliers

    // Use two pointers to check last two elements as possible outliers
    int pt1 = n - 1;  // Pointing to the last element
    int pt2 = n - 2;  // Pointing to the second last element

    while (pt2 >= 0) {
        int lastElement = arr[pt1];        // Last element (possible outlier)
        int secondLastElement = arr[pt2];  // Second last element (possible outlier)

        // Calculate the remaining sum if we treat lastElement and secondLastElement as outliers
        int remainingSum = totalSum - lastElement - secondLastElement;

        // Check if removing both lastElement and secondLastElement results in remainingSum matching either
        if (remainingSum == secondLastElement) {
            outline.push_back(lastElement);  // lastElement is a potential outlier
        }
        if (remainingSum == lastElement) {
            outline.push_back(secondLastElement);  // secondLastElement is a potential outlier
        }

        pt2--;  // Move to the next element on the left
    }

    // Sort and return the greatest outlier
    sort(outline.begin(), outline.end());
    return !outline.empty() ? outline.back() : -1;
}

// Driver code to test the function
int main() {
    vector<int> arr = {10, 3, 7, 20, 5};  // Example input
    int result = getOutlierValue(arr);
    cout << "Outlier: " << result << endl;  // Expected output: 16 (assuming 16 is the outlier)

    return 0;
}