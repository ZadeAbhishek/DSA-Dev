#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int rob(vector<int> &A, vector<int> &dp, int h)
    {
      if (h >= size(A)) return 0;

      if (dp[h] != -1) return dp[h];

      return dp[h] = max(rob(A, dp, h + 1), A[h] + rob(A, dp, h + 2));
    }

  int rob(vector<int> &A)
  {
    vector<int> dp(size(A), -1);
    int resX = rob(A, dp, 1);
    A.pop_back();
    vector<int> dp2(size(A), -1);
    int resY = rob(A, dp2, 0);
    return max(resX, resY);
  }
};

class Solution2
{
  public:
    int rob(vector<int> A, int x)
    {
      A[x + 1] = max(A[x + 1], A[x + 0]);
      for (auto i = x + 2; i < size(A); i++) A[i] = max(A[i - 1], A[i] + A[i - 2]);
      return A[size(A) - 1];
    }

  int rob(vector<int> &A)
  {
    if (size(A) == 0) return 0;
    if (size(A) == 1) return A[0];
    if (size(A) == 2) return max(A[0], A[1]);
    int resX = rob(A, 1);
    A.pop_back();
    int resY = rob(A, 0);
    return max(resX, resY);
  }
};

int main()
{
  vector<int> cost = { 200, 3, 140, 20, 10 };

  Solution2 *solve = new Solution2();
}