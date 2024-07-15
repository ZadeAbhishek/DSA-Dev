#include <vector>
using namespace std;

void find(vector<int> denoms,int &target, int currSum, int &maxDenomination,int index,int checkDenoms){
  // base condition
  if(currSum > target) return;
  if(currSum == target){
    maxDenomination = min(maxDenomination,checkDenoms);
    return;
  }

  // since we have unlimited denomination selection
  for(int i = index ; i < denoms.size(); i++){
    find(denoms,target,(currSum + denoms[i]),maxDenomination,i,checkDenoms+1);
  }
  return;
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  // Write your code here.
    // Write your code here.
  int checkDenoms = 0;
  int target = n;
  int maxDenomination = INT_MAX;
  find(denoms,target,0,maxDenomination,0,checkDenoms);
  return maxDenomination == INT_MAX?-1:maxDenomination;
}


///

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int find(vector<int>& denoms, int target, vector<int>& dp) {
    // Base case: if target is 0, no coins are needed
    if (target == 0) return 0;
    
    // If the target is negative, return an invalid large number
    if (target < 0) return INT_MAX;
    
    // Check if the result is already computed
    if (dp[target] != -1) return dp[target];
    
    int minCoins = INT_MAX;
    
    // Try every coin in the denomination array
    for (int denom : denoms) {
        int result = find(denoms, target - denom, dp);
        if (result != INT_MAX) {
            minCoins = min(minCoins, result + 1);
        }
    }
    
    // Store the result in the dp array
    dp[target] = minCoins;
    return dp[target];
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    vector<int> dp(n + 1, -1); // Initialize dp array with -1 indicating uncomputed states
    int result = find(denoms, n, dp);
    return result == INT_MAX ? -1 : result;
}
