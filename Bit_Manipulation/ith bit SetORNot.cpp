#include<bits/stdc++.h>
using namespace std;

int main(){
    int bit = 2;
    int i = 1;
    
    // check ith bit set or not
    int mask = 1<<(i-1); // create mask of 0100 shift 1 two times
    if(bit & mask) cout<<"True";
    else cout<<"False"; 

}
