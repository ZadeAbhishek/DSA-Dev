#include <vector>
using namespace std;

// The time complexity remains O(n!)
void calculatePermutation(vector<int>& array, vector<int>& vis, vector<vector<int>> &result,vector<int> temp){
  // base case
  if(temp.size() == array.size()){
    if(temp.size() > 0) result.push_back(temp);
    return;
  }
  for(int index = 0; index < array.size(); index++){
    if(vis[index] == -1){
      vis[index] = 1;
      temp.push_back(array[index]);
      calculatePermutation(array,vis,result,temp);
      temp.pop_back();
      vis[index] = -1;
    }
  }
  return;
}

vector<vector<int>> getPermutations(vector<int> array) {
  // Write your code here
  vector<int> vis(array.size(),-1);
  vector<vector<int>> result;
  vector<int> temp;
  calculatePermutation(array,vis,result,temp);
  return result;
}
