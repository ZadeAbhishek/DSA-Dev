
// recussicve method
#include <vector>
using namespace std;

void getSum(vector<int> array,int index, int TotalSum, int &maxSum){
  // base condition
  if(index >= array.size()){
    maxSum = max(maxSum,TotalSum);
   return;
  }
  // main condition
  // case 1 if i choose
  getSum(array,index+2,TotalSum + array[index],maxSum);
  // case 2 if i dont choose
  getSum(array,index+1,TotalSum,maxSum);

  return;
}


int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.
  if(array.size() == 0) return 0;
  int TotalSum = 0;
  int maxSum = INT_MIN;
  getSum(array,0,TotalSum,maxSum);
  return maxSum;
}


// iterrative method
#include <vector>
#include <algorithm>

using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
    if (array.size() == 0) return 0;
    if (array.size() == 1) return array[0];

    // Initialize an array to store the maximum sum at each index
    vector<int> maxSums(array.size());

    // The maximum sum at the first index is the value at the first index
    maxSums[0] = array[0];
    // The maximum sum at the second index is the maximum of the first two values
    maxSums[1] = max(array[0], array[1]);

    // Fill the rest of the maxSums array
    for (int i = 2; i < array.size(); i++) {
        // The max sum at the current index is the maximum of either:
        // 1. Not choosing the current element (max sum up to the previous element)
        // 2. Choosing the current element (current element value + max sum up to the element before the previous one)
        maxSums[i] = max(maxSums[i - 1], array[i] + maxSums[i - 2]);
    }

    // The last element in maxSums array contains the result
    return maxSums.back();
}
