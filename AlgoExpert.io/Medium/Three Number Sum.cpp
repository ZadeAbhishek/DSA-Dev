#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  unordered_map<int,int> hash;
  for(auto num : array) hash.insert({num,num}); 
   // 12 -> 12
   // 3 -> 3
   // hash[12] -> 12
  // iterate over the array again'
  // 0   2 + 6 == 8  8 - 0 = 8 0 - 8 = -8
  set<vector<int>> tempResult;
  for(int i = 0 ; i < array.size() ; i++){
     for(int j = i + 1 ; j < array.size() ; j++){
       int currSum = targetSum - (array[i] + array[j]);
       if(hash.count(currSum) && array[i] != currSum && array[j] != currSum){
            vector<int> temp = {array[i],array[j],currSum};
            sort(temp.begin(),temp.end());
            tempResult.insert(temp);
       }
   }

 }
   vector<vector<int>> result;
   for( auto currentElement : tempResult){
     result.push_back(currentElement);
   } 
  return result;
}
