#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:

    int countNegatives(vector<vector < int>> &grid)
    {
      int count = 0;
      int result = 0;
      for (auto it: grid)
      {
        result = bs(it);	// get indexx of first negative element
        if (result == -1) continue;
        int total = it.size() - result;	// get the total negative number
        count += total;	// add to count 
      }

      return count;
    }

 	// Aim for this BInary search to find index of First negative elements
  int bs(vector<int> &arr)
  {
    int high = arr.size() - 1;
    int low = 0;
    int mid;
    while (high >= low)
    {
     	// base case
      if (high == low)
      {
       	// if element is negative return index
        if (arr[high] < 0) return high;
       	// else return -1
        else return -1;
      }

      mid = (low + high) / 2;
     	// if element is postive move to right side part
      if (arr[mid] >= 0) low = mid + 1;
     	// else move to left part
      else if (arr[mid] < 0) high = mid;
    }

    return -1;
  }
};

// TC O(rows) chat GPT- solution
class Solution2
{
  public:
    int countNegatives(std::vector<std::vector < int>> &grid)
    {
      int rows = grid.size();
      int cols = grid[0].size();

      int count = 0;
      int row = rows - 1;
      int col = 0;

      while (row >= 0 && col < cols)
      {
        if (grid[row][col] < 0)
        {
          count += cols - col;
          row--;
        }
        else
        {
          col++;
        }
      }

      return count;
    }
};

int main()
{
  Solution2 solution;

 	// Test Case 1
  std::vector<std::vector < int>> grid1 = {
		{ 4, 3, 2, -1 },
    { 3, 2, 1, -1 },
    { 1, 1, -1, -2 },
    {-1, -1, -2, -3
    }
  };

  int result1 = solution.countNegatives(grid1);
  std::cout << "Test Case 1: Number of negative numbers in grid1 is " << result1 << std::endl;

 	// Test Case 2
  std::vector<std::vector < int>> grid2 = {
		{ 3, 2 },
    { 1, 0 }
  };

  int result2 = solution.countNegatives(grid2);
  std::cout << "Test Case 2: Number of negative numbers in grid2 is " << result2 << std::endl;

 	// Test Case 3
  std::vector<std::vector < int>> grid3 = {
		{ 1, -1 },
    {-1, -1
    }
  };

  int result3 = solution.countNegatives(grid3);
  std::cout << "Test Case 3: Number of negative numbers in grid3 is " << result3 << std::endl;

  return 0;
}