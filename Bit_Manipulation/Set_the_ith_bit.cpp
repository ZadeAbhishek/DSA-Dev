#include<bits/stdc++.h>
using namespace std;

int main(){
    int bit = 4;
    int i = 2;
    
    // check ith bit set or not
    int mask = 1<<(i-1); // create mask of 0100 shift 1 two times
    bit = bit | mask; 
    cout<<bit<<endl;

}