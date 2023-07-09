#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>


   uint32_t reverseBits(uint32_t n) {
         int sum = 0;
       for(int i = 0 ; i < 32 ; i++){
            int x = n & 1; // get lsb
            int reverse = x<<(31-i); // ex if last bit is 1 and i is 0 then 31 - 0  i.e mask of 31bith will me created.
            sum = sum | reverse; // using or operation to add bit to sum
            n = n >> 1; // right shift to get next lsb
       }
       return sum;
    }

int main(){
   uint32_t n = 43261596;
   std::cout<<reverseBits(n)<<"\n";
}