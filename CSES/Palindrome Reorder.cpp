/*
Time limit: 1.00 s
Memory limit: 512 MB



Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input
    string s = "";
    cin >> s;

    // Frequency hash map for characters A–Z
    vector<int> hash(26, 0); // Only 26 needed for A-Z
    for (char x : s) {
        hash[x - 'A']++; 
    }

    // Variables to track odd character and build the result
    char oddChar = ' ';
    int oddCount = 0;
    string result = "";

    // Iterate through the hash map to process frequencies
    for (int x = 0; x < hash.size(); x++) {
        if (hash[x] % 2 != 0) { // Odd frequency
            oddCount++;
            oddChar = (char)('A' + x); // Store the odd character
            hash[x]--; // Use one instance of the odd character
            if (oddCount > 1) { // More than one odd character means no solution
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }

        // Add half of the even characters to the result
        for (int i = 0; i < hash[x] / 2; i++) {
            result += (char)('A' + x);
        }
    }

    // Build the final palindrome
    string reverseResult = result; // Copy result for reverse
    reverse(reverseResult.begin(), reverseResult.end()); // Reverse to form the second half
    if (oddCount == 1) {
        result += oddChar; // Add the odd character in the middle
    }
    result += reverseResult; // Add the reversed half

    cout << result << endl;
    return 0;
}