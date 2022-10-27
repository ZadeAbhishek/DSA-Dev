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
    void sort(vector<int> &arr){
       // basically swap kind of (O^2)
       for(auto i = 0 ; i < arr.size() ; i++){
            for(auto j = 0 ; j < arr.size() ; j++){ 
                // if i change < to > to reverse order mai me sort honga
                if(arr[i] < arr[j]){
                    swap(arr[i],arr[j]);
                }
            }
        }
    }
   public:
   void SelectionSort(vector<int> &arr){
     sort(arr);
     return;
    }
};

int main (){
     vector<int> List = {7,11,9,3,6,10,66,78,96,12,36,105,700,64,3,6};   
     int len = List.size();
     for(int i = 0;i<len;i++){
         cout<<List[i]<<" ";
        }
       cout<<"\n";
    Solution* solve = new Solution();
    solve->SelectionSort(List);
    for(int i = 0;i<List.size();i++){
         cout<<List[i]<<" ";
    }
}