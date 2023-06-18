// Count the number of set bits in number 
#include<bits/stdc++.h>
using namespace std;

int countSet(unsigned int n){
    int count = 0;
    while(n){
    count += n & 1;
    n>>=1;
    }
    return count;
}


int main(){
    cout<<countSet(7)<<endl;
}