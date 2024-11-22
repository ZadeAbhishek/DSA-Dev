#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int findMaximumZeroes(vector<int>& arr) {
    int n = arr.size();
    int zeroes = 0;

    while (true) {
        int max_prefix_size = 0;

        // Find the maximum prefix size without any zero
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                break;
            }
            max_prefix_size = i + 1;
        }

        // If no valid prefix, break the loop
        if (max_prefix_size == 0) {
            break;
        }

        // Decrement each element in the valid prefix by 1
        for (int i = 0; i < max_prefix_size; ++i) {
            arr[i] -= 1;
        }

        // Count the number of zeroes in the array
        zeroes = count(arr.begin(), arr.end(), 0);
    }

    return zeroes;
}

// Driver code to test the function
int main() {
    vector<int> arr = {2, 5, 9, 3, 5};
    int result = findMaximumZeroes(arr);
    cout << "Maximum number of zeroes: " << result << endl;

    return 0;
}