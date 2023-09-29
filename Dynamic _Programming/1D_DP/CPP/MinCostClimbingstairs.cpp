#include<bits/stdc++.h>
using namespace std;

class Solution {
 int Min = INT_MAX;
 int memo[1001] = {0};
 int climb(vector<int>& cost, int steps){
    // we know the step number by steps
    // check steps and return minimum
    // if step is at last ot lat secon postion return current value
    // becuase we take one ot two steps to reach end
    if(steps == cost.size()-1 || steps == cost.size()-2){
      return cost[steps];
    }

    // if present in memo return same value
    if(memo[steps]) return memo[steps];
    // climb one steps
    int OneStep = climb(cost,steps+1);
    // climb two steps
    int SecStep = climb(cost,steps+2);
    
    // store value to memo
    memo[steps] = min(OneStep,SecStep) + cost[steps];

    return memo[steps];
 }
public:
    int minCostClimbingStairs(vector<int>& cost) {
      // recussion is required with one - Dimentaional Array
      // if only two elment return the least one since 
      // we can take 1 or 2 steps 
      if(cost.size() == 2) return min(cost[0],cost[1]);

      //climb from index 0  
      int x = climb(cost,0);

      //climb from index 1
      int y = climb(cost,1);

      return min(x,y);
    }
};

int main (){
  vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
  Solution *solve = new Solution();
  cout<<solve->minCostClimbingStairs(cost);
}