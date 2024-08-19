#include <vector>

using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
  // fail case
  if(arrayOne.size() != arrayTwo.size()){ return false; }
// Base case for recursion
if (arrayOne.empty() && arrayTwo.empty()) {
    return true;
} 
if (arrayOne.empty() || arrayTwo.empty()) {
    return false;
}
if (arrayOne.size() == 1 && arrayTwo.size() == 1) {
    return arrayOne[0] == arrayTwo[0];
}
  if(arrayOne[0] != arrayTwo[0]){ return false; }
 
  vector<int> subArrayOneSmall;
  vector<int> subArrayOneBig;
  vector<int> subArrayTwoSmall;
  vector<int> subArratTwoBig;

  for(int i = 1; i < arrayOne.size(); i++){
    if(arrayOne[0] > arrayOne[i]){
      subArrayOneSmall.push_back(arrayOne[i]);
    }
    else{
      subArrayOneBig.push_back(arrayOne[i]);
    }
    if(arrayTwo[0] > arrayTwo[i]){
      subArrayTwoSmall.push_back(arrayTwo[i]);
    }
    else{
      subArratTwoBig.push_back(arrayTwo[i]);
    }
  }

  return sameBsts(subArrayOneSmall,subArrayTwoSmall) && sameBsts(subArrayOneBig,subArratTwoBig);
}
