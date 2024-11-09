#include <iostream>
#include <vector>
#include <string>

using namespace std;


// ## check the question how cleverly they have manipulated this 
/*
Can Rearrange Binary String

You are given a binary string, binary, consisting only of characters '0' and '1'. You are allowed to perform the following operation zero or more times:

Choose any subsequence of binary.
Sort this subsequence.
Replace the chosen subsequence in binary with its sorted version.
Additionally, you are given an array arr of length n, where each element of arr is a string of the same length as binary. Each string in arr consists of characters '0', '1', and the wildcard character '?'. The '?' character can be replaced with either '0' or '1' arbitrarily.

For each string in arr, after replacing every '?' character with either '0' or '1', you need to determine whether it is possible to rearrange the binary string into the modified string using the sorting operation described above. If it is possible, store "YES" as the corresponding answer; otherwise, store "NO".

Notes:

A subsequence of a string is obtained by deleting some (possibly zero) characters from the string without changing the order of the remaining characters.
Each computation for the elements of arr is independent of the others. The binary string is reset to its original state before checking each string in arr.

*/
vector<string> getBinaryMatchResults(const string& binary, const vector<string>& arr) {
    vector<string> results;
    int count0 = 0, count1 = 0;

    // Count the number of '0's and '1's in the binary string
    for (char c : binary) {
        if (c == '0') count0++;
        else if (c == '1') count1++;
    }

    // Process each string in arr
    for (const string& target : arr) {
        int target0 = 0, target1 = 0, questionMarks = 0;

        // Count '0's, '1's, and '?' in the current target string
        for (char c : target) {
            if (c == '0') target0++;
            else if (c == '1') target1++;
            else if (c == '?') questionMarks++;
        }

        // Determine if it's possible to match the counts using '?' replacements
        int needed0 = count0 - target0;
        int needed1 = count1 - target1;

        // Check if '?' can fulfill the remaining needed counts exactly
        if (needed0 >= 0 && needed1 >= 0 && (needed0 + needed1) == questionMarks) {
            results.push_back("YES");
        } else {
            results.push_back("NO");
        }
    }

    return results;
}

int main() {
    string binary = "101100";
    vector<string> arr = {"?110?1", "111???"};
    vector<string> result = getBinaryMatchResults(binary, arr);

    for (const string& res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}