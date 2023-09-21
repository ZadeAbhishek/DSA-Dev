#include<bits/stdc++.h>
#include <iostream>
using namespace std;

 template<class T>
 
 void operator<< (ostream& Cout,vector<T> result){
    for(auto i : result) Cout<<i<<" ";
    Cout<<"\n";
 }   

class Solution {
    private:
     template<class T>
     void sort(vector<T> &arr){
        int pass = arr.size()-1;
        int i =0;
        int j =1;
        while(pass!=0){

            i = 0 , j= 1; // each pass we will compare elements setting up last element
            while(i < pass) // last element is setted therefore pass - 1 or < pass
            { 
                if(arr[i] >= arr[j]) swap(arr[i],arr[j]);
                i++,j++;
            }    
            
           // cout<<arr;
            
            pass--;
        }

     }


   public:
   template<class T>
   void BubleSort(vector<T> &arr){
     sort(arr);
     return;
    }
};

int main (){
     vector<int> List = {-7,11,9,3,6,10,66,78,96,12,36,105,700,64,3,6};   
     int len = List.size();
     cout<<"Before Sort \n";
     cout<<List;
    Solution* solve = new Solution();
    solve->BubleSort(List);
    cout<<"After Sort \n";
    cout<<List;

}