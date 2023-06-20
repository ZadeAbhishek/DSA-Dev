// Count the number of set bits in number 
#include<bits/stdc++.h>
using namespace std;

int countSet_1(unsigned int n){ // Tc : logn
    int count = 0;
    while(n){
    count += n & 1;
    n>>=1;
    }
    return count;
}


// Brain Kernighans Algorithm
// this is same for 7,15 as previos algorithm
unsigned int countSet_2(int n){ // Tc : o(set bits)
    unsigned int count = 0;
    while(n!=0) n &= (n-1),count++;
    return count;
}


int main(){
    cout<<countSet_2(13)<<endl;
}