#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> &arr, vector<int> temp, vector<vector<int>> &result){
    int n = arr.size();
   //	The expression i & (1 << j) checks whether the j-th bit in the binary representation of i is 1. 
    for(auto i = 0 ; i < pow(2,n) - 1 ; i++){
        temp.clear();
        for(auto j = 0 ; j < n ; j++){
            if(i & (1<<j)) temp.push_back(arr[j]);
        }
        result.push_back(temp);
    }
    return result;
}


int main(){

   vector<int> arr = {0,1,2};
   vector<int> temp;
   vector<vector<int>> result;
   powerSet(arr,temp,result);
   
   for(auto k : result){
    for(auto x : k){
        cout<<x<<" ";
    }
    cout<<endl;
   }

}