// Minimum characters to be added at front to make string palindrome
// https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
// leetcode https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/
#include <bits/stdc++.h>
using namespace std;

// without memoization tc 2^N after N^2;

int solve(string &s, int start, int end, vector<vector < int>> &dp)
{
	// base case
	if (start >= end) return 0;	// either we reach end of exit

	// memoization
	if (dp[start][end] != -1) return dp[start][end];

	if (s[start] == s[end]) return dp[start][end] = solve(s, start + 1, end - 1, dp);	// no change check next
	else
	{
		// insert needed to be done check if need infront or back
		int possibility1 = solve(s, start + 1, end, dp);
		int possibility2 = solve(s, start, end - 1, dp);

		return dp[start][end] = 1 + min(possibility1, possibility2);
	}
}

int minInsertions(string str)
{
	vector<vector < int>> dp(str.size(), vector<int> (str.size(), -1));
	return solve(str, 0, str.size() - 1, dp);
}

int main()
{
	string x = "tcitkg";
	cout << minInsertions(x) << "\n";
}