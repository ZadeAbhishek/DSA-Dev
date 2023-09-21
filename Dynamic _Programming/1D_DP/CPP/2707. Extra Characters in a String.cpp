#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of extra characters needed to form words from the dictionary in the given string.
    int minExtraChar(string s, vector<string>& dictionary) {
        int max_length = s.size() + 1; // Initialize the maximum length.

        vector<int> dp(s.size()+1, max_length); // Create a dynamic programming array to store the minimum extra characters needed for each substring.

        dp[0] = 0; // Initialize the base case where no extra characters are needed for an empty substring.

        unordered_set<string> dic(dictionary.begin(), dictionary.end()); // Create an unordered set for quick lookup of words in the dictionary.

        for(int i = 1; i <= max_length-1; i++) {
            dp[i] = dp[i-1] + 1; // Initialize dp[i] with the assumption of adding one extra character.

            // Iterate through all possible substrings ending at position 'i'.
            for(int j = 1; j <= i; j++) {
                // Check if the current substring (s.substr(i-j, j)) exists in the dictionary.
                if(dic.find(s.substr(i-j, j)) != dic.end()) {
                    // If it does, update dp[i] to the minimum of its current value and dp[i-j] (previous minimum).
                    dp[i] = min(dp[i], dp[i-j]);
                }
            }
        }

        return dp.back(); // The value at the end of the dp array represents the minimum extra characters needed to form words from the dictionary in the given string.
    }
};


int main() {
    Solution solution;

    // Example usage:
    std::string s = "leetcode";
    std::vector<std::string> dictionary = {"leet", "code"};

    int result = solution.minExtraChar(s, dictionary);

    std::cout << "Minimum extra characters needed: " << result << std::endl;

    return 0;
}
