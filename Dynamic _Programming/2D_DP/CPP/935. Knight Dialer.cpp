
// https://leetcode.com/problems/knight-dialer/description/


#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


	int dail[4][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
		{ 10, 0, 11 }
	};

	int dir[8][2] = {{ 1, 2 },{-1, -2},{-1, 2},{ 1, -2 },{ 2, 1 },{-2, -1},{-2, 1},{ 2, -1 }};
	bool valid(int x, int y)
	{
		if ((x == 3 && y == 0) || (x == 3 && y == 2)) return false;

		if (x < 0 || y < 0 || x > 3 || y > 2) return false;

		return true;
	}

	long long knight(int n, int x, int y, vector<vector < int>> &dp)
	{
		// base case if n == 0 return
		if (n == 0) return 0;

		if (n == 1) return 1;

		if (valid(x, y) && dp[n][dail[x][y]] != -1) return dp[n][dail[x][y]];

		long long result = 0;

		for (int i = 0; i < 8; i++)
		{
			int currx = x + dir[i][0];
			int curry = y + dir[i][1];

			if (valid(currx, curry))
			{
				result += knight(n - 1, currx, curry, dp);
				result %= mod;
			}
		}

		return dp[n][dail[x][y]] = result;
	}

	int knightDialer(int n)
	{
		long long res = 0;

		vector<vector < int>> dp(n + 1, vector<int> (15, -1));

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (valid(i, j))
				{
					res += knight(n, i, j, dp);
					res %= mod;
				}
			}
		}

		return res;
	}

int main(){

    cout<<knightDialer(3131)<<"\n";
}