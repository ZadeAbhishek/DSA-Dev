/*
Time limit: 1.00 s
Memory limit: 512 MB



Your task is to calculate the number of bit strings of length n.
For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
Input
The only input line has an integer n.
Output
Print the result modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
8
*/


// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define mod 1000000007

// int main(){
//     long n = 0;
//     cin>>n;
//     ll possible = 1;
//     for(auto i = 1 ; i <= n ; i++){
//         possible = (possible * 2) % mod;
//     }
//     cout<<possible<<endl;
//     return 0;
// }

// More Optimsied and intuative code 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
 // Correct modulus value

// Function to perform modular exponentiation
ll modular_exponentiation(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod; // Ensure base is within mod

    while (exp > 0) {
        // If exp is odd, multiply the result with base
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        // Square the base and reduce exp by half
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long n;
    cin >> n;

    // Compute 2^n % mod using modular exponentiation
    ll mod = 1000000007;
    ll result = modular_exponentiation(2, n, mod);
    cout << result << endl;

    return 0;
}