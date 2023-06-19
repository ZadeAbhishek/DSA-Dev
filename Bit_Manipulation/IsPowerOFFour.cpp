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

int main(){
   int x = 0;
   cin>>x;
   cout<<isPowerOfFour_1(x);

}