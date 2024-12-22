/*
Time limit: 1.00 s
Memory limit: 512 MB



You are given a string of length n and a dictionary containing k words. In how many ways can you create the string using the words?
Input
The first input line has a string containing n characters between a–z.
The second line has an integer k: the number of words in the dictionary.
Finally there are k lines describing the words. Each word is unique and consists of characters a–z.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 5000
1 \le k \le 10^5
the total length of the words is at most 10^6

Example
Input:
ababc
4
ab
abab
c
cb

Output:
2

Explanation: The possible ways are ab+ab+c and abab+c.
*/

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Recursive function to solve the problem
long long solve(const string &text, unordered_map<string, string> &hash, int index, int n, vector<long long> &dp) {
    // Base case: if we've reached the end of the text
    if (index == n) {
        return 1;
    }

    // If already computed, return the stored result
    if (dp[index] != -1) return dp[index];

    long long totalMatch = 0;
    string temp = "";
    
    // Loop through the remaining portion of the text
    for (int i = index; i < n; i++) {
        temp += text[i]; // Add current character to temp
        if (hash.count(temp)) {
            // Recurse with the remaining text and add matches
            totalMatch = (totalMatch + solve(text, hash, i + 1, n, dp)) % MOD;
        }
    }

    // Store the result modulo MOD
    return dp[index] = totalMatch;
}


int solveTabulation(const string &text, unordered_map<string, string> &hash){
    int n = text.size();
    vector<int> dp(n + 1,0);
    dp[0] = 1; // Base case number string of len 0 is 1
    // outerloop for string len
    for(int i = 1; i <= n; i++){
        string str = "";
        for(int j = i - 1; j >= 0; j--){
            str = text[j] + str; // so we dont need to reverse each time
            if(hash.count(str)) dp[i] += dp[j] % MOD;
        }
    }
    return dp[n];
}

int main() {
    string text;
    cin >> text;
    int lengthK;
    cin >> lengthK;

    unordered_map<string, string> hash;
    for (int i = 0; i < lengthK; i++) {
        string temp;
        cin >> temp;
        hash[temp] = temp;
    }

    int n = text.size();
    vector<long long> dp(n, -1); // Initialize DP array with -1
    long long result = solve(text, hash, 0, n, dp);
    cout << result << "\n"; // Print the result modulo MOD
    long long result2 = solveTabulation(text, hash);
    cout << result2 << "\n"; // Print the result modulo MOD
    return 0;
}

