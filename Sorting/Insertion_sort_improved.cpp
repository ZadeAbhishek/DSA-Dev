#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> result){
         for(int i = 0;i<result.size();i++){
         cout<<result[i]<<" ";
        }
        cout<<"\n";
    }

class Solution {
    private:

   public:
   void InsertionSort(vector<int> &arr){
      
      for(auto i = 1 ; i < size(arr) ; i++)
      {
             int temp_indez = i;
             
             while(arr[temp_indez] < arr[temp_indez-1] && temp_indez > 0)
             {
                int temp_var = arr[temp_indez];
                arr[temp_indez] = arr[temp_indez-1];
                arr[temp_indez-1] = temp_var;
                temp_indez--;
             }
      }
    }
};





int main (){
     vector<int> List = {7,11,9,3,6,10,66,78,96,12,36,105,700,64,3,6,0,-1};   
     int len = List.size();
     for(int i = 0;i<len;i++){
         cout<<List[i]<<" ";
        }
       cout<<"\n";
    Solution* solve = new Solution();
    solve->InsertionSort(List);
    for(int i = 0;i<List.size();i++){
         cout<<List[i]<<" ";
        }

}