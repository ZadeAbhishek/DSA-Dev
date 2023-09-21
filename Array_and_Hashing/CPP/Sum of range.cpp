/* given an array we have to find some of given range for Q queries 

for example 

arr = {1, 2, 3, 4, 5}

i/p

1 2 3 4 5
2
0 2
2 3

o/p
6
12

we can update array elements any time

there are two ways to implement this if number of queries are larger with repspect low update
second approch is best is best but if updation is larger then  then approch one is best for best/averege TC 
we can use segmented Tree


Explanation:

The code implements two approaches to calculate the sum of elements in a given range [start, end] in an array.
Approach 1 (getSum1) is a naive approach that directly calculates the sum of elements by iterating through the array within the given range.
Approach 2 (getSum2) is an efficient approach that utilizes prefix sums to optimize repeated range sum queries. It first calculates the prefix sums array and then uses it to find the sum of elements in the specified range.
In the main function, both approaches are demonstrated by computing the sum of elements in the range [3, 4] for the given array. The results for both approaches are printed.
*/

#include<iostream>
using namespace std;

// Approach 1: Naive method to get the sum of elements in a given range [start, end]
// Parameters:
// - arr: Pointer to the array
// - start: Start index of the range
// - end: End index of the range
// Returns:
// - The sum of elements in the specified range
int getSum1(int *arr, int start, int end) {
    if (start > end)
        return -1;
    int sum = 0;
    for (int i = start; i <= end; i++)
        sum += arr[i];
    return sum;
}

// Approach 2: Efficient method to get the sum of elements in a given range [start, end]
// Parameters:
// - arr: Pointer to the array
// - start: Start index of the range
// - end: End index of the range
// - n: Size of the array
// Returns:
// - The sum of elements in the specified range
int getSum2(int *arr, int start, int end, int n) {
    // Create a sum array by calculating prefix sums from left to right
    if (start > end)
        return -1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i] += sum;
        sum = arr[i];
    }
    // Calculate the sum in the given range using prefix sums
    return (start - 1 <= 0) ? arr[end] - 0 : arr[end] - arr[start - 1];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int siz = 5;
    cout << getSum1(arr, 3, 4) << "\n"; // Output: 9 (sum of elements in the range [3, 4])
    cout << getSum2(arr, 3, 4, siz) << "\n"; // Output: 9 (sum of elements in the range [3, 4])
    // Approach 2 can be more efficient for multiple queries on the same array
    // since we calculate prefix sums once and use them for all queries.
    // However, if there are frequent array updates, Approach 1 may be more efficient.
    return 0;
}