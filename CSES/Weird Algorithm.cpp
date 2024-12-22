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
    long long n = 0;
    cin>>n;
    while(n != 1){
        cout<<n<<" ";
        if(n % 2 == 0) n = n / 2;
        else n = n * 3 + 1;
    }
    cout<<n<<"\n";
    return 0;
}