// matrix chain multiplication

class Solution
{
	public:

		int solve(int arr[], int start, int end, vector<vector < int>> &dp)
		{
			// apply partition dp
			if (start == end) return 0;

			//memoizatio,
			if (dp[start][end] != -1) return dp[start][end];

			int minMultiply = INT_MAX;

			for (int mid = start; mid < end; mid++)
			{
				int checkleft = arr[start - 1] *arr[mid] *arr[end] + solve(arr, start, mid, dp) + solve(arr, mid + 1, end, dp);

				if (checkleft < minMultiply) minMultiply = checkleft;
			}

			return dp[start][end] = minMultiply;
		}

	int matrixMultiplication(int N, int arr[])
	{
		// code here
		vector<vector < int>> dp(N + 1, vector<int> (N + 1, -1));

		return solve(arr, 1, N - 1, dp);
	}
};