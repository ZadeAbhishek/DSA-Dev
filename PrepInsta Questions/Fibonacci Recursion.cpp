#include<bits/stdc++.h>
using namespace std;


int fibno(int n){
    if(n<=1) return n;
    return fibno(n-1) + fibno(n-2);
}

int main(){
    int n = 4;
    cout<< fibno(n)<<"\n";
    return 0;
}