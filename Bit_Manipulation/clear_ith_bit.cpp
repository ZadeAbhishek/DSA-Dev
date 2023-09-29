#include<bits/stdc++.h>
using namespace std;

int main(){
    int bit = 13;
    int i = 4;
    
    // check ith bit set or not
    int mask = 1<<(i-1); // create mask ex 0100
    bit = bit & (~mask); // ~mask = 1011
    cout<<bit<<endl;

}