/*
Time limit: 1.00 s
Memory limit: 512 MB



A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.
Input
The only input line has an integer n.
Output
Print 2^n lines that describe the Gray code. You can print any valid solution.
Constraints

1 \le n \le 16

Example
Input:
2

Output:
00
01
11
10
*/

#include<bits/stdc++.h>
using namespace std;

string btd(int num, int len){
    string bnum = "";
    // convert to binary
    while(num > 0){
        bnum  = (num % 2 == 0 ? "0" : "1") + bnum;
        num = num / 2;
    }
    // check len
    while(bnum.size() < len)
        bnum = "0" + bnum;

    return bnum;    
}

int main(){
    auto n = 0;
    cin >> n;
    auto num = 1 << n;
    for(auto i = 0 ; i < num ; i++){
        auto gray = (i ^ (i >> 1)); // i ^ 1 divides i by 2 this is done to flip digit doing xor and get next Gray code
        cout << btd(gray,n)<<endl;
    }
}
