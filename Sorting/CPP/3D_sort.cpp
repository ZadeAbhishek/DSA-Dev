#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void operator<< (ostream &cout,vector<vector<int>> arr){
         for(auto x : arr){
            for(auto y : x){
                cout<<y<<" ";
            }
            cout<<"\n";
         }
    }

bool cmt(vector<int> x, vector<int> y){
    return x[x.size()-1] < y[y.size()-1];

}

int main(){
    vector<vector<int>> arr = {{0,1,1},{1,3,6},{2,3,1},{1,2,2}};
    cout<<arr;
    sort(arr.begin(),arr.end(),cmt);
    cout<<"\n";
    cout<<arr;

}