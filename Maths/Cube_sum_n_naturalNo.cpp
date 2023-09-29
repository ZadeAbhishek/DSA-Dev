// WAP to find sum of cude n natural number
#include<iostream>
#include<math.h>
using namespace std;

// formula (n(n+1)/2)^2

long long int getSum(int n){
    return  pow((n * (n + 1))/2,2);
}

int main(){
    cout<<getSum(100)<<"\n";
}