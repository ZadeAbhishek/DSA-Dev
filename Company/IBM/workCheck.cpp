#include <bits/stdc++.h>
using namespace std;

// Helper function to check if the word can be segmented
bool checkWord(const vector<string>& table, const string& s) {
    unordered_set<string> wordSet(table.begin(), table.end()); // Convert to a set for O(1) lookups
    vector<bool> dp(s.size() + 1, false); // dp[i] is true if s[0...i-1] can be segmented
    dp[0] = true; // An empty string can always be segmented

    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            string word = s.substr(j, i - j);
            if (dp[j] && wordSet.find(word) != wordSet.end()) {
                dp[i] = true;
                break; // No need to continue if we already found a valid segmentation
            }
        }
    }
    return dp[s.size()];
}

int main() {
    vector<string> table = {"IBM", "I", "LOVE"}; // Word list
    string s = "ILOVEIBM"; // Input string
    cout << (checkWord(table, s) ? "Yes" : "No") << endl; // Output result
}