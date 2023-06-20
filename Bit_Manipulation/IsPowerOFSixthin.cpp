// Check if a number is a power of 16:

#include<bits/stdc++.h>
using namespace std;


int isPowerOf16_1(int x){
   if(x == 0) return 0;
   
   while(x != 1){
    if(x % 16 != 0) return 0;
    x /= 16;
   }
   return 1;
}

int isPowerOf16_2(int x){
    // check if it is power of 2
    if(!(x & (x-1))){
      int mask = 0xEEEEEEEE; // 1110 1110 1110 1110 1110 1110 1110 1110 power of 16 bit is zero
      return !(x & mask);
    }
    return 0;
}

int isPowerOf16_3(int x){
    // check if it is power of 2
    // x = x % (16-1) == 1 
    return !(x & (x-1)) && (x % 15 == 1);
}

int main(){
   int x = 0;
   cin>>x;
   cout<<isPowerOf16_1(x);
}