#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int count = 0;

        // Iterate through each column of the strings
        for (int i = 0; i < strs[0].size(); i++) {
            // Check each adjacent pair of strings
            for (int j = 1; j < strs.size(); j++) {
                // If the character in the current column of the previous string is greater
                // than the character in the current column of the current string, it violates
                // the non-decreasing order condition.
                if (strs[j - 1][i] > strs[j][i]) {
                    count++; // Increment the count of columns to be deleted
                    break;   // No need to check the rest of the strings in this column
                }
            }
        }

        return count; // Return the count of columns to be deleted
    }
};

int main() {
    Solution solution;

    // Test the minDeletionSize function
    vector<string> strings = {"cba", "daf", "ghi"};
    int result = solution.minDeletionSize(strings);
    cout << "Minimum Deletion Size: " << result << endl;

    return 0;
}
