#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> result)
{
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  cout << "\n";
}



class Solution
{
  void permutation(vector<int> &nums, vector<vector< int >> &result, vector< int > &vis, vector< int > &temp)
  {
   	// base case
    if (temp.size() == nums.size())
    {
      result.push_back(temp);
      return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (vis[i] == 0)
      {
        vis[i] = 1;
        temp.push_back(nums[i]);
        permutation(nums, result, vis, temp);
        temp.pop_back();
        vis[i] = 0;
      }
    }

    return;
  }

  public:
    vector<vector < int>> permute(vector<int> &nums)
    {
      vector<vector < int>> result;
      vector<int> vis(nums.size() + 1, 0);
      vector<int> temp;
      permutation(nums, result, vis, temp);
      return result;
    }
};



class Solution
{
  vector<vector < int>> result;
  void permutation(vector<int> &nums, int curr)
  {
    if (curr == nums.size())
    {
      result.push_back(nums);
      return;
    }

    for (int i = curr; i < nums.size(); i++)
    {
      swap(nums[curr], nums[i]);
      permutation(nums, curr + 1);
      swap(nums[curr], nums[i]);
    }

    return;
  }

  public:

    vector<vector < int>> permute(vector<int> &nums)
    {
      permutation(nums, 0);
      return result;
    }
};



int main()
{
  vector<int> s = { 2, 2, 3, 3 };

  Solution *solve = new Solution();
  vector<vector < int>> result = solve->permute(s);
  cout << "[ ";
  for (auto i = 0; i < result.size(); i++)
  {
    cout << "[ ";
    for (auto j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }

    cout << "]";
  }

  cout << " ]";
  cout << endl;
}