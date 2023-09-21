#include<bits/stdc++.h>
using namespace std;

 template<class T>
 
 void operator<< (ostream& Cout,vector<T> result){
    for(auto i : result) Cout<<i<<" ";
    Cout<<"\n";
 }   

class Solution {
    private:

   public:
   void InsertionSort(vector<int> &arr){
      int temp_indez = INT_MIN;
      for(auto i = 1 ; i < size(arr) ; i++){ 
      temp_indez = i;
      while(arr[temp_indez] < arr[temp_indez-1] && temp_indez > 0) swap(arr[temp_indez],arr[temp_indez-1]),temp_indez--;
      cout<<arr;
      }
    }
};





int main (){
     vector<int> List = {7,11,9,3,6,10,66,78,96,12,36,105,700,64,3,6,0,-1};   
     int len = List.size();
    cout<<List;
    Solution* solve = new Solution();
    solve->InsertionSort(List);
    cout<<List;

}