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

     void sort(vector<int> &arr){
        int pass = arr.size()-1;
        while(pass!=0){
            int i =0;
            int j =1;
            while(i < pass){
                if(arr[i] >= arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                i++;
                j++;
            }
            //cout<<arr;
            pass--;
        }

     }


   public:
   void BubleSort(vector<int> &arr){
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