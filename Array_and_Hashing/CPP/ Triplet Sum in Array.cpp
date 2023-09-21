#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool find3Numbers(int A[], int n, int X) {
        // Sorting the array in ascending order.
        sort(A, A + n);

        // Iterating through each element as a potential first element of the triplet.
        for (int i = 0; i < n; i++) {
            int curr = A[i];    // Current element as the first element of the triplet.
            int left = i + 1;   // Pointer to the next element after the current element.
            int right = n - 1;  // Pointer to the last element of the array.

            // Using a two-pointer technique to find the remaining two elements of the triplet.
            while (left < right) {
                int tripletSum = curr + A[left] + A[right];

                if (tripletSum == X) {
                    return true;  // Triplet found with the required sum.
                } else if (tripletSum < X) {
                    left++;       // Current triplet's sum is too small, moving left pointer to try larger elements.
                } else {
                    right--;      // Current triplet's sum is too large, moving right pointer to try smaller elements.
                }
            }
        }
        
        // Triplet not found that sums up to X.
        return false;
    }
};

int main() {
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int X = 22;
    
    Solution sol;
    if (sol.find3Numbers(A, n, X)) {
        cout << "Triplet found!" << endl;
    } else {
        cout << "Triplet not found." << endl;
    }
    
    return 0;
}

/*
Time Complexity:

The time complexity of the find3Numbers function is dominated by the sorting step, which 
takes O(n log n) time using the sorting algorithm from the C++ STL. The subsequent loop 
runs in O(n^2) time in the worst case. Therefore, the overall time complexity of the program
is O(n^2 + n log n), which simplifies to O(n^2) since n^2 dominates n log n for large 
values of n.

*/