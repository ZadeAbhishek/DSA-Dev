#include<bits/stdc++.h>
using namespace std;

long arr[1000000];

long Factorial(long n)
{
    if(n == 1) return 1;

    else if(arr[n]) return arr[n];
    
    else return arr[n] = n * Factorial(n - 1);
}



int main (){

    long n; 
    cin>>n;
    cout<<Factorial(n);
}