// Calcualate Xor from 1 to n
#include<bits/stdc++.h>
using namespace std;

// instead of using forr loop xor each elemnt from 1 to n
// we can see there is pattern
// 1 = 1
// 2 = 1 ^ 2 = 3 
// 3 = 3 ^ 3 = 0
// 4 = 4 ^ 0 = 4
// 5 = 4 ^ 5 = 1  5 % 4 == 1 return 1
// 6 = 1 ^ 6 = 7  6 % 4 == 2 return n+1
// 7 = 7 ^ 7 = 0  7 % 4 == 3 return 0
// 8 = 8 ^ 0 = 8  8 % 4 == 0 return n


int GetN_Xor(int n){
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    return 0;
}

int main(){
    int n = 2;
    cout<<GetN_Xor(n)<<"\n";
}