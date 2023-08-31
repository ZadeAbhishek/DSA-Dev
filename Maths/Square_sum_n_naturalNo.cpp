// WAP to find sum of sqaure of n natural number
#include<iostream>
using namespace std;

// formula (n(n+1)(2n+1))/6

long long int getSum(int n){
    return (n * (n+1) * ((2*n)+1) ) /6;
}

int main(){
    cout<<getSum(100)<<"\n";
}

