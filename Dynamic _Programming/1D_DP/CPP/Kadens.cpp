#include<iostream>
#include<vector>
#include<math.h>



int main(){
  std::vector<int> arr = {-5,-4,-6,-4,-6,-2,-1};
  int currSum = 0;
  int maxSum = 0;
  int maxNegative = 0;
  
  // Mix of negative and postive this will work
  for(auto x : arr){
     currSum += x;
     maxSum = maxSum>currSum?maxSum:currSum;
     currSum = currSum<0?0:currSum; 
  }

  // only negative this will work
  currSum = 0;
  for(auto x : arr){
     currSum += x;
     maxNegative = maxNegative>abs(currSum)?maxNegative:abs(currSum);
     currSum = currSum<0?currSum:0; 
  }

  std::cout<<maxSum<<" "<<maxNegative;
}