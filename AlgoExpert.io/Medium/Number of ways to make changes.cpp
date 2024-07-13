#include <vector>
using namespace std;

void find(vector<int> denoms,int &target, int currSum, int &maxDenomination,int index){
  // base condition
  if(currSum > target) return;
  if(currSum == target){
    maxDenomination++;
    return;
  }

  // since we have unlimited denomination selection
  for(int i = index ; i < denoms.size(); i++){
    find(denoms,target,(currSum + denoms[i]),maxDenomination,i);
  }
  return;
}

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  // Write your code here.
  int target = n;
  int maxDenomination = 0;
  find(denoms,target,0,maxDenomination,0);
  return maxDenomination;
}


// optimised ways 
#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    // Create a vector to store the number of ways to make change for each amount
    vector<int> ways(n + 1, 0);
    
    // There's one way to make change for zero amount
    ways[0] = 1;

    // Iterate over each denomination
    for (int denom : denoms) {
        // Update the ways array for all amounts greater than or equal to the current denomination
        for (int amount = denom; amount <= n; amount++) {
            ways[amount] += ways[amount - denom];
        }
    }

    // The number of ways to make change for the target amount n is stored in ways[n]
    return ways[n];
}
