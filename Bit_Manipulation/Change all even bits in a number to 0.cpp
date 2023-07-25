#include<bits/stdc++.h>
using namespace std;

/*

0xAAAAAAAA = 10101010101010101010101010101010

0x55555555 = 1010101010101010101010101010101

Yes, for 0xAAAAAAAA, all even number is 1, and odd number is 0

for 0x55555555, all even number is 0, and odd number is 1

*/

class Solution {
  public:
    long long int convertEvenBitToZero(long long int n) {
        // code here
        return (n & 0xAAAAAAAA);
    }
};

int main(){}