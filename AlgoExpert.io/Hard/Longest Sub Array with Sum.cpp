vector<int> longestSubarrayWithSum(vector<int> array, int targetSum) {
  int start = -1;
  int end = -1;
  int maxLenght = INT_MIN;
  for(int i = 0 ; i < array.size(); i++){
      int sum = 0;
     for(int j = i ; j < array.size(); j++){
        sum += array[j];
        if(sum == targetSum && maxLenght < j - i + 1){
            maxLenght = (j - i + 1);
            start = i;
            end = j;
        }
     }
  }
  if(maxLenght == INT_MIN){
    return {};
  }
  return {start,end};
}


// more optimised approch 

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestSubarrayWithSum(vector<int> array, int targetSum) {
    unordered_map<int, int> prefixSumMap; // To store prefix sums and their indices
    int prefixSum = 0;
    int maxLength = 0;
    int start = -1, end = -1;

    prefixSumMap[0] = -1; // Initialize to handle cases where subarray starts from index 0

    for (int i = 0; i < array.size(); i++) {
        prefixSum += array[i];

        // Check if prefixSum - targetSum exists in the map
        if (prefixSumMap.find(prefixSum - targetSum) != prefixSumMap.end()) {
            int prevIndex = prefixSumMap[prefixSum - targetSum];
            if (i - prevIndex > maxLength) {
                maxLength = i - prevIndex;
                start = prevIndex + 1;
                end = i;
            }
        }

        // Add the current prefix sum to the map if it's not already present
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
            prefixSumMap[prefixSum] = i;
        }
    }

    if (maxLength == 0) {
        return {}; // No subarray found
    }
    return {start, end};
}

int main() {
    vector<int> array = {1, 2, 3, 7, 5};
    int targetSum = 12;
    vector<int> result = longestSubarrayWithSum(array, targetSum);

    if (!result.empty()) {
        cout << "Longest subarray indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No subarray with the target sum found." << endl;
    }

    return 0;
}
