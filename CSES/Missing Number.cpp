/*
You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.
Input
The first input line contains an integer n.
The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
Output
Print the missing number.
Constraints

2 \le n \le 2 \cdot 10^5

Example
Input:
5
2 3 1 5

Output:
4
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> temp;
    int n = 0;
    cin>>n;

    for(int i = 1 ; i < n; i++){
        int t = 0;
        cin>>t;
        temp.push_back(t);
    }
    int total = n * (n+1) / 2;
    int tempTotal = 0;
    for(auto x : temp) tempTotal += x;
    cout<<total - tempTotal<<"\n";
    return total - tempTotal;
}