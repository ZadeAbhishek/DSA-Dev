// Check if a number is a power of 4:

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfFour_1(int n){
   if(n == 0) return 0;

   while(n != 1){
      if(n % 4 != 0) return 0; // this help usto know if number is negative of note
      n /= 4;  
   }
   return (n == 1)?1:0;
}

bool isPowerOfFour_2(int n){

// check if it is power of 2
if(!(n & (n-1))){
    //check all even bits or bits that are in the power of four
    int mask = 0xAAAAAAAA; // 1010 1010 1010 1010 1010 1010 1010 1010 here all bits the power of 4 are zero  
    return !(n & mask);
}
    return 0;
}

// N is a power of 4, if it is a power of 2 and if modulus of n by 3 will give remainder 1.
bool isPowerOfFour_3(int n){
 return !(n & n - 1) && (n % 3  == 1);
}



int main(){
   int x = 0;
   cin>>x;
   cout<<isPowerOfFour_3(x);
}