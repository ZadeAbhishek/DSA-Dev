// desp : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include<bits/stdc++.h>
using namespace std;

int main(){}

class Solution
{
	public:

		void get_combination(string &digits, string &output, int index, vector<string> &map, vector<string> &result)
		{
			// base case
			if (index == digits.size())
			{
				result.push_back(output);
				return;
			}

			// main case
			int number = digits[index] - '0';
			string alpha = map[number];
			for (int i = 0; i < alpha.size(); i++)
			{
				output.push_back(alpha[i]);
				get_combination(digits, output, index + 1, map, result);
				output.pop_back();
			}
		}

	vector<string> letterCombinations(string digits)
	{
		// recussion and backTraking problem
		string output = "";
		if (digits.size() == 0) return {};

		int index = 0;
		vector<string> result;
		vector<string> map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		get_combination(digits, output, 0, map, result);
		return result;
	}
};
