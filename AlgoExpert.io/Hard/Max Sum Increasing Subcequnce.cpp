#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
    vector<pair<int,int>> sumArray(array.size(),{0,0});
    sumArray[0] = {array[0],-1}; // sum + previous index
    int maxSum = array[0];
    int maxIndex = 0;
  
    for(int i = 1 ; i < array.size(); i++){
        sumArray[i].first = array[i];
        sumArray[i].second = -1;
        for(int j = 0; j < i; j++){
            if(array[i] > array[j] && sumArray[i].first < sumArray[j].first + array[i]){
                sumArray[i].first = sumArray[j].first + array[i];
                sumArray[i].second = j;
            }
        }

        if(maxSum < sumArray[i].first){
            maxSum = sumArray[i].first;
            maxIndex = i;
        }
    }
   
    vector<int> temp;
    while(maxIndex != -1){
        temp.push_back(array[maxIndex]);
        maxIndex = sumArray[maxIndex].second;
    }
    
    reverse(temp.begin(),temp.end());
    return {{maxSum},temp};
}