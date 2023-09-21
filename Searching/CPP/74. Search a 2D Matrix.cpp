#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = (m * n) - 1;
        int mid = -1;
        int row, col, curr;

        while (low <= high) {
            // Calculate the middle index
            mid = low + (high - low) / 2;
            row = mid / n; // Calculate the row index of the middle element
            col = mid % n; // Calculate the column index of the middle element

            // Get the current element at the middle index
            curr = matrix[row][col];

            // Base case: if the current element is equal to the target, return true
            if (curr == target)
                return true;
            else if (curr < target)
                low = mid + 1; // Search in the right half of the matrix
            else
                high = mid - 1; // Search in the left half of the matrix
        }

        return false; // Target not found in the matrix
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    Solution s;
    cout << s.searchMatrix(matrix, 3) << endl; // Output: 1 (True, as 3 is present in the matrix)
}

/*
Time Complexity:
The time complexity of the searchMatrix function is O(log(mn)), where m is the number of 
rows and n is the number of columns in the matrix. The binary search algorithm is used to 
find the target element in the flattened matrix, and it performs the search in O(log(mn)) 
time.

Space Complexity:
The space complexity of the searchMatrix function is O(1). The function only uses a constant 
amount of extra space to store variables like low, high, mid, row, col, and curr. The space
 consumption does not depend on the size of the input matrix, so it is considered constant 
 or O(1).

*/
