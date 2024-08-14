#include <vector>
#include <algorithm>
using namespace std;

vector<int> subarraySort(vector<int> array) {
    int n = array.size();
    int minOutOfOrder = INT_MAX;
    int maxOutOfOrder = INT_MIN;

    // Find the minimum and maximum out-of-order elements
    for (int i = 0; i < n; i++) {
        if (i > 0 && array[i] < array[i - 1]) {
            minOutOfOrder = min(minOutOfOrder, array[i]);
        }
        if (i < n - 1 && array[i] > array[i + 1]) {
            maxOutOfOrder = max(maxOutOfOrder, array[i]);
        }
    }

    // If the array is already sorted, return {-1, -1}
    if (minOutOfOrder == INT_MAX) {
        return {-1, -1};
    }

    // Determine the correct positions for minOutOfOrder and maxOutOfOrder
    int left = 0;
    while (array[left] <= minOutOfOrder) {
        left++;
    }

    int right = n - 1;
    while (array[right] >= maxOutOfOrder) {
        right--;
    }

    return {left, right};
}