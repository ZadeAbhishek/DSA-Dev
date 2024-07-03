#include <vector>
using namespace std;


/*
Problem: Smallest Difference Pair

You are given two non-empty arrays of integers. Write a function that finds the pair of numbers
(one from the first array, one from the second array) whose absolute difference is closest to zero.
Return these two numbers as a pair. If there are multiple pairs with the same smallest difference,
return the pair with the smallest first number, or if those are also the same, the smallest second number.

Function Signature:
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo);

Input:
- arrayOne: A non-empty vector of integers.
- arrayTwo: A non-empty vector of integers.

Output:
- A vector containing two integers, one from each input array, that have the smallest absolute difference.

Example:
vector<int> arrayOne = {-1, 5, 10, 20, 28, 3};
vector<int> arrayTwo = {26, 134, 135, 15, 17};

vector<int> result = smallestDifference(arrayOne, arrayTwo);
// Output: {28, 26}

Constraints:
- The arrays are not necessarily sorted.
- Both arrays will contain at least one element.
- The elements in the arrays can be positive, negative, or zero.
- You can assume that there is always a pair of numbers that will have the smallest difference.

Approach:
- First, sort both arrays.
- Use two pointers to traverse both arrays and find the pair with the smallest difference.
- Update the smallest difference and the result pair when a smaller difference is found.
- Return the result pair.

Notes:
- Make sure to handle cases where the arrays contain negative numbers.
- Aim for an efficient solution with a time complexity better than O(n^2).
*/

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(),arrayOne.end());
  sort(arrayTwo.begin(),arrayTwo.end());
  int i = 0; 
  int j = 0;
  int minDifference = INT_MAX;
  vector<int> ans;
  while(i < arrayOne.size() && j < arrayTwo.size()){
    if(arrayOne[i] == arrayTwo[j]) return {arrayOne[i],arrayTwo[j]};
    if(abs(arrayOne[i] - arrayTwo[j]) < minDifference){
      minDifference =  abs(arrayOne[i]- arrayTwo[j]);
      ans = {arrayOne[i],arrayTwo[j]};
    }
     
    if(arrayOne[i] < arrayTwo[j]) {
        i++;
    }
    else j++;
  }
   return ans;
}
 