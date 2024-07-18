#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int matchStrings(string str1, string str2, int i, int j, vector<vector<int>> &dp) {
    // Base case: if either string is exhausted
    if (i >= str1.size()) {
        return str2.size() - j;  // insert remaining characters of str2
    }
    if (j >= str2.size()) {
        return str1.size() - i;  // insert remaining characters of str1
    }
    
    // If the value is already computed, return it
    if (dp[i][j] != INT_MAX) return dp[i][j];

    int minPoints = INT_MAX;
    
    // If characters are the same, no operation is needed
    if (str1[i] == str2[j]) {
        minPoints = matchStrings(str1, str2, i + 1, j + 1, dp);
    } else {
        // Compute minimum cost of replace, insert, delete
        int replace = matchStrings(str1, str2, i + 1, j + 1, dp);
        int insert = matchStrings(str1, str2, i, j + 1, dp);
        int deleteOp = matchStrings(str1, str2, i + 1, j, dp);
        
        minPoints = 1 + min({replace, insert, deleteOp});
    }
    
    dp[i][j] = minPoints;  // Store the result in the dp array
    return minPoints;
}

int levenshteinDistance(string str1, string str2) {
    vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), INT_MAX));
    return matchStrings(str1, str2, 0, 0, dp);
}