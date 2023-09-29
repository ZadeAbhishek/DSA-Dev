/*
Question: Array into sub-array

You have been given an array A of N integers. 
Divided it into 3 non-empty sub-arrays, such that sum of each sub-array can be represented in form of 2^k. K is a whole number.

Eg. A = [1, 2, 3, 1]

A can be divided into [1], [2], [3, 1]. These have sum of 1 = 2^0, 2 = 2^1, and 4 = 2^2. 
You can add 1 at any index of array. You can do add any number of time. 

You need to find minimum number of times, 1 should be added such that all three sub-array is in 2^k form.

Input: 
T : Number of test cases.
N : length of array
A : array

Constrains
1 <= N <= 1000
1 <= A[i] <= 100
All input are integers.

Input Format:
First line contain T
Second line contain size of array.
Third line contain array of votes received

Output Format: 
Each separate line for each testcase results.

Sample input:
1
3
2 1 3

Sample output:
1

Explanation: 
This can be divided into [2], [1], and [3, 1]; which does satisfy 2^k form.
*/

#include<bits/stdc++.h>
using namespace std;

// Function to calculate the difference between n and the next larger power of 2
int checkPower(int n){
    int i = -1;
    while(n > pow(2, ++i));
    return pow(2, i) - n;
}

// Function to solve the problem for a single test case
int solve(vector<int> &A, int N){
    // Calculate the total sum of the elements in the array A
    int total = accumulate(A.begin(), A.end(), 0);
    
    // Initialize sumA and minAddition
    int sumA = 0;
    int minAddition = INT_MAX;

    // Iterate over the first partition
    for (int first = 0; first < N - 2; first++) {
        sumA += A[first];
        int powA = checkPower(sumA);

        // Initialize sumB
        int sumB = 0;

        // Iterate over the second partition
        for (int second = first + 1; second < N - 1; second++) {
            sumB += A[second];
            int powB = checkPower(sumB);

            // Calculate the minimum addition needed for the third partition
            minAddition = min(minAddition, (powA + powB + checkPower(total - (sumA + sumB))));
        }
    }

    return minAddition;
}

int main() {
    int T;
    cin >> T;
    vector<int> results;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N; // Length of array
        vector<int> A(N);

        // Read the elements of the array
        for (int j = 0; j < N; j++) {
            cin >> A[j];
        }

        // Call the solve function for the current test case and store the result
        int result = solve(A, N);
        results.push_back(result);
    }
    
    cout << endl;
    
    // Print the results for each test case
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}



/*
1
3
2 1 3

1
5
2 1 3 4 5

*/
