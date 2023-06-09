#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * It is a binary operator that takes two numbers, 
 * left shifts the bits of the first operand, and the 
 * second operand decides the number of places to shift. 
 * In other words, left-shifting an integer “a” with an integer “b” 
 * denoted as ‘(a<<b)’ is equivalent to multiplying a with 2^b (2 raised to power b). 
 */

int main(){
    int x = 5; // 101
    int y = 5;
    x >>= 1; // 5 -> 2  101 -> 010   101/
    y <<= 1; // 5 -> 10 101 -> 1010
    cout<<x<<" "<<y;
}

