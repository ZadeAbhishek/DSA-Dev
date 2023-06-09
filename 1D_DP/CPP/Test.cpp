#include<bits/stdc++.h>
using namespace std;

// w = {4,5,1}
// c = {1,2,3}
// W = 3
// 4 > 3 no 
// 5 > 3 no
// 1 > 3 yes W = 3 - 1 = 2 
// 4 and 5 already used 
// max weight 3 

// w = {1,2,3}
// c = {50,20,30}
// W = 2
// 1 > 2 yes W = 1
// 2 > 1 no
// 3 > 1 no
// max <= currWrigh max = curW

// 2 and 3 we return final abswer


int dp(int W, vector<int> w , vector<int> cost , int CMax , vector<int> memo, int bag, int CurrCost)
{
      // base case 
      if(bag > W) return 0;
      if(bag == W) return CurrCost;
      // iterator s dp

      for(auto index = 0 ; index < size(w) ; index++)
      {
        if(memo[index] != 0) continue;
        memo[index] = 1;
        bag += w[index];
        CurrCost += cost[index];
        int temp =  dp(W,w,cost,CMax,memo,bag,CurrCost);
        if(temp == 0) CMax = max((CurrCost-cost[index]),CMax);
        else CMax = max(temp,CMax);
        CurrCost -= cost[index];
        bag -= w[index];
        memo[index] = 0; 
        
      }

      return CMax;
}


int main ()
{
    int W = 50;
    vector<int> w = {10, 20, 30};
    vector<int> c = {60, 100, 120};
    int CMax = INT_MIN;
    vector<int>memo(size(w),0); // use to check if curr element is used already
    int bag = 0;
    int CurrCost = 0;
    cout<<dp(W,w,c,CMax,memo,bag,CurrCost);
    return 0;
}

// time comlexity of algorithm TC:O(2^N) either we taking elemnt or not taking element 
// O(N) space complexity