#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
     int maxSum = INT_MIN; // To handle cases where all elements are negative
    int currSum = 0;

    for(auto num : array){
        currSum += num;
        maxSum = max(maxSum, currSum);
        currSum = max(currSum, 0);
    }

    return maxSum;
}