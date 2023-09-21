/**
 * Given an integer array nums, return true if you can partition the array into two subsets 
 * such that the sum of the elements in both subsets is equal or false otherwise.
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 */

/**
 *Given an integer array nums, return true if you can partition the array into two subsets 
 *such that the sum of the elements in both subsets is equal or false otherwise.
 *Input: nums =[1,5,11,5]
 *Output: true
 *Explanation: The array can be partitioned as[1, 5, 5] and[11].
 */

class Solution
{
	public:

		bool solve(int index, vector<int> &nums, int target, vector<vector< int>> &memo)
		{
			// base 
			if (index >= nums.size() || target < 0) return false;

			if (target == 0) return true;

			//memoization
			if (memo[index][target] != -1) return memo[index][target];

			// case 1 will include element
			bool inc = solve(index + 1, nums, target - nums[index], memo);

			// case 2 will not include
			bool not_inc = solve(index + 1, nums, target - 0, memo);

			return memo[index][target] = inc || not_inc;
		}

	bool canPartition(vector<int> &nums)
	{
		// knap sack problem

		int total = accumulate(nums.begin(), nums.end(), 0);

		if (total & 1) return false;	// if total is odd we can't divide;

		int target = total / 2;	// if yes find target in sun array

		vector<vector < int>> memo(nums.size() + 1, vector<int> (target + 1, -1));

		return solve(0, nums, target, memo);
	}
};

//tabulation we can optimese this more
class Solution
{
	public:

		bool canPartition(vector<int> &nums)
		{
			// knap sack problem
			int total = accumulate(nums.begin(), nums.end(), 0);

			if (total & 1) return false;	// if total is odd we can't divide;

			vector<vector < int>> table(nums.size() + 1, vector<int> (total + 1, 0));

			for (int i = 0; i <= nums.size(); i++)
			{
				table[i][0] = 1;	// using recusrion base case we can say
			}

			for (int index = nums.size() - 1; index >= 0; index--)
			{
				for (int target = 0; target <= (total / 2); target++)
				{
				 		// case 1 will include element

					int inc = false;
					if (target - nums[index] >= 0) inc = table[index + 1][target - nums[index]];

					// case 2 will not include
					int not_inc = table[index + 1][target - 0];

					table[index][target] = inc || not_inc;
				}
			}

			return table[0][total / 2];
		}
};
