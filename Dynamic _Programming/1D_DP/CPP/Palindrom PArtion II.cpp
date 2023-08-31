// Partition DP
// given a string create max partiton having valid palindrome
// for example ABC so valid partiotion will be A | B | C therefore 2 valid partiion
// for example ABBACDC ABBA|CDC 1 valid partition
#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <vector>

bool isPalindrome(std::string s, int i, int j)
{
	while (i < j)
	{
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}

	return true;
}

int get_Valid_Partition(std::string s, int index)
{
	// base case 
	if (index == s.size()) return 0;

	// main case
	int minPartion = INT_MAX;
	std::string currString = "";

	for (int currIndex = index; currIndex < s.size(); currIndex++)
	{
		currString += s[currIndex];
		int partition = INT_MAX;
		if (isPalindrome(s, index, currIndex))
		{
			partition = 1 + get_Valid_Partition(s, currIndex + 1);
			minPartion = std::min(partition, minPartion);
		}
	}

	return minPartion;
}

// with memoization
int get_Valid_Partition_memoization(std::string s, int index, std::vector<int> &dp)
{
	// base case 
	if (index == s.size()) return 0;

	//memoization case
	if (dp[index] != -1) return dp[index];

	// main case
	int minPartion = INT_MAX;
	std::string currString = "";

	for (int currIndex = index; currIndex < s.size(); currIndex++)
	{
		currString += s[currIndex];
		int partition = INT_MAX;
		if (isPalindrome(s, index, currIndex))
		{
			partition = 1 + get_Valid_Partition(s, currIndex + 1);
			minPartion = std::min(partition, minPartion);
		}
	}

	return dp[index] = minPartion;
}

// tabulation
int get_Valid_Partition_tabulation(std::string s)
{
	std::vector<int> dp(s.size() + 1, 0);
	dp[s.size()] = 0;

	for (int index = s.size() - 1; index >= 0; index--)
	{
		int minPartion = INT_MAX;
		std::string currString = "";
		for (int currIndex = index; currIndex < s.size(); currIndex++)
		{
			currString += s[currIndex];
			int partition = INT_MAX;
			if (isPalindrome(s, index, currIndex))
			{
				partition = 1 + dp[currIndex+1];
				minPartion = std::min(partition, minPartion);
			}
		}

		dp[index] = minPartion;
	}

	return dp[0];
}

int main()
{
	std::string s = "ABC";

	// we are sending string and starting index as parm
	// here are adding -1 at end becase it will made A | B | C |<--this last extra partition
	std::cout << get_Valid_Partition(s, 0) - 1 << "\n";

	std::vector<int> dp(s.size() + 1, -1);

	std::cout << get_Valid_Partition_memoization(s, 0, dp) - 1 << "\n";

	std::cout << get_Valid_Partition_tabulation(s) - 1 << "\n";

}