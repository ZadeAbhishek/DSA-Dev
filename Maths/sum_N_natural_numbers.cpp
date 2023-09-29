// WAP to find Sum of N Natural Numbers
#include<iostream>
using namespace std;

// formula n(n+1)/2

long long getsum(int n){
    return (n*(n+1))/2;
}

int main(){
    cout<<getsum(100000)<<"\n";
}