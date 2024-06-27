// solution 
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  // Basic code
  for(int i = 0 ; i < array.size() ; i++){
    for(int j = i + 1 ; j < array.size() ; j++){
      if(array[i] + array[j] == targetSum) return {array[i],array[j]};     
}
}
  return {};
}


// solution 2 
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  // using sets
  unordered_set<int> sets;
  for(auto& x : array){
     if(sets.find(targetSum - x) != sets.end()){
 return {x,targetSum - x};
     }
    sets.insert(x);
} 
  return {};
}
