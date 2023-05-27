#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    void printVector(vector<int> result){
         for(int i = 0;i<result.size();i++){
         cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
    
    int rob(vector<int> &A,vector<int> &dp,int h)
    { 
        

        if(h >= size(A)) return 0;

        if(dp[h] != -1) return dp[h];

        return dp[h] = max(rob(A,dp,h + 1), A[h] + rob(A,dp,h + 2));
    }

    int rob(vector<int> &A)
    {
      vector<int> dp(size(A),-1);
      int resX = rob(A,dp,1);
      A.pop_back();
      vector<int> dp2(size(A),-1);
      int resY = rob(A,dp2,0);
      return max(resX,resY);
    }
};

int main()
{
    vector<int> cost = {200,3,140,20,10};
    Solution *solve = new Solution();
    cout << solve->rob(cost);
}