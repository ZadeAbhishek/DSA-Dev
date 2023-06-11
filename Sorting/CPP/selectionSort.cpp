#include<bits/stdc++.h>
using namespace std;

 template<class T>

void operator<< (ostream& Cout,vector<T> result){
    for(auto i : result) Cout<<i<<" ";
    Cout<<"\n";
 }   

class Solution {
    private:
    void sort(vector<int> &arr){
       // basically swap kind of (O^2)
       for(auto i = 0 ; i < arr.size() ; i++){
            for(auto j = i ; j < arr.size() ; j++){ 
                // if i change < to > to reverse order mai me sort honga
                if(arr[i] > arr[j]){
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
     cout<<List;
    Solution* solve = new Solution();
    solve->SelectionSort(List);
    cout<<List;
}