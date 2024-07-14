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
