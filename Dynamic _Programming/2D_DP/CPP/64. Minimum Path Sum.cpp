/**
 *Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
 *which minimizes the sum of all numbers along its path.
 *Note: You can only move either down or right at any point in time.
 * 
 *Input: grid =[[1,3,1],
 *              [1,5,1],
 *              [4,2,1]]
 *Output: 7
 *Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 */
#include <bits/stdc++.h>
using namespace std;

void operator<<(std::ostream &Cout, std::vector<std::vector < int>> matrix)
{
	for (auto x: matrix)
	{
		for (auto y: x) Cout << y << " ";
		Cout << "\n";
	}
}

int solve(vector<vector < int>> &grid, int &col, int &row, int i, int j, vector< vector< int>> &dp)
{
	// base case
	if (i == col - 1 && j == row - 1) return grid[i][j];

	//memoization
	if (dp[i][j] != -1) return dp[i][j];

	int down = INT_MAX;
	int right = INT_MAX;

	if (i + 1 < col) down = grid[i][j] + solve(grid, col, row, i + 1, j, dp);
	if (j + 1 < row) right = grid[i][j] + solve(grid, col, row, i, j + 1, dp);

	return dp[i][j] = min(down, right);
}

int minPathSum_top_down_memo(vector<vector < int>> &grid)
{
	int col = grid.size();
	int row = grid[0].size();
	vector<vector < int>> dp(col + 1, vector<int> (row + 1, -1));
	return solve(grid, col, row, 0, 0, dp);
}

// bottom up aaproch
int minPathSum_bottom_up(vector<vector < int>> &grid)
{
	int col = grid.size();
	int row = grid[0].size();
	vector<vector < int>> dp(col + 2, vector<int> (row + 2, INT_MAX));

	for (int i = col - 1; i >= 0; i--)
	{
		int down = INT_MAX;
		int right = INT_MAX;
		for (int j = row - 1; j >= 0; j--)
		{
			if (dp[i + 1][j] == INT_MAX) down = INT_MAX;
			else down = grid[i][j] + dp[i + 1][j];

			if (dp[i][j + 1] == INT_MAX) right = INT_MAX;
			else right = grid[i][j] + dp[i][j + 1];

			dp[i][j] = (down == INT_MAX && right == INT_MAX) ? grid[i][j] : min(down, right);
		}
	}

	return dp[0][0];
}

int main()
{
	vector<vector < int>> grid = {
		{ 9, 1, 4, 8 }
	};

	cout << minPathSum_bottom_up(grid) << "\n";
	cout << minPathSum_top_down_memo(grid) << "\n";
}