// Check if a number is a power of 8:

#include<bits/stdc++.h>
using namespace std;


int isPowerOfEight_1(int x){
   if(x == 0) return 0;
   
   while(x != 1){
    if(x % 8 != 0) return 0;
    x /= 8;
   }
   return 1;
}

int isPowerOfEight_2(int x){
    // check if it is power of 2
    if(!(x & (x-1))){
      int mask = 0xB6DB6DB6; // 1011 0110 1101 1011 0110 1101 1011 0110 power of eight bit is zero
      return !(x & mask);
    }
    return 0;
}

int isPowerOfEight_3(int x){
    // check if it is power of 2
    // x = 8 % (8-1) == 1 
    return !(x & (x-1)) && (x % 7 == 1);
}

int main(){
   int x = 0;
   cin>>x;
   cout<<isPowerOfEight_3(x);
}