#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  unordered_map<int,int> hash;
  for(auto num : array) hash.insert({num,num});
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
