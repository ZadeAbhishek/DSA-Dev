// Remove last set bit Rightmost bit
// ex N = 13 
// n & (n-1) == 1101 & 1110 == 1100 rightMost bit is set

#include<bits/stdc++.h>
using namespace std;
int main(){
   unsigned int n = 8;
   cout<<(n & (n-1))<<"\n";
}