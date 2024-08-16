#include <vector>
using namespace std;

// brute force approch O(n^2) time complexity and O(n) space complexity
vector<int> largestRange(vector<int> array) {
  // Write your code here.
  // we need to use HashMaps 
  set<int> hash(array.begin(),array.end());
  long long maxSize = 0;
  vector<int> result;
  for(int i = 0 ; i < array.size(); i++){
    int currentMax = 1;
    int currentNumber = array[i];
    while(hash.find(++currentNumber) != hash.end()) currentMax++;
    if(currentMax > maxSize){
      maxSize = currentMax;
      result = {array[i],currentNumber-1};
    }
  }
  return result;
}


// optimised version
// TC : O(n) SC : O(n)
//     <-----1------> here we are expanding like this 
#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
  // Idea is to check range from smallest to largest in range
  set<int> hash(array.begin(),array.end());
  int maxRange = 0;
  vector<int> result;

  // loop array
  for(auto curr : array){
     
    // check if already visted
    if(hash.find(curr) == hash.end()) { continue; } // element is deleted that means its already visited

    int left = curr - 1;
    int right = curr + 1;
    int currMax = 1;
    hash.erase(curr); // mark as visited
    while(hash.find(left) != hash.end()){
      hash.erase(left);
      left--;
      currMax++;
    }
    while(hash.find(right) != hash.end()){
      hash.erase(right);
      right++;
      currMax++;
    }
    if(currMax > maxRange){
      result = {left + 1, right - 1};
      maxRange = currMax;
    }
  }
  return result;
}
