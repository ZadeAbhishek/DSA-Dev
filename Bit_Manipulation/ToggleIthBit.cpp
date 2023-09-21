// Toggle ith bit basically Xor
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 15;
    int bits = 3;
    int mask = (1 << (bits-1));
    cout<<(n ^ mask)<<"\n";
    return 0;
}