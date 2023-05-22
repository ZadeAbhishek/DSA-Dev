#include<bits/stdc++.h>
using namespace std;

 template<class T>
 
 void operator<< (ostream& Cout,vector<T> result){
    for(auto i : result) Cout<<i<<" ";
    Cout<<"\n";
 }   

/*

The Dutch National Flag algorithm is a sorting algorithm that partitions 
an array containing elements of three distinct values 
(for example, 0s, 1s, and 2s) into three parts, in a single traversal of the array. 
The algorithm is named after the Dutch national flag, 
which has three horizontal stripes of red, white, and blue.

*/

int main (){
     vector<int> List = {0,1,1,1,2,1,2};
     cout<<List;

     int start = 0;
     int end = size(List);
     int curr = 0;

     while(curr < end)
     {
        if(List[curr] == 0) swap(List[curr++],List[start++]);
        else if(List[curr] == 1) curr++;
        else swap(List[curr],List[end--]);
     }

    cout<<List;

}