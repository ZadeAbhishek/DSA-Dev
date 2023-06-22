// Count Number of bits to be flipped to convert A to B:
#include<bits/stdc++.h>
using namespace std;

// A ^ B get no of set flips to flips
// n & n-1 gernighan alogirthm to count set flips

int Flips(int A, int B){
    int n = A ^ B;
    int c = 0;
    while(n){
        n = n & (n-1);
        c++;
    }
    return c;
}

int main(){
    int A,B;
    cin>>A>>B;
    cout<<Flips(A,B)<<endl;
}