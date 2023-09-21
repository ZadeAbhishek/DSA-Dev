/*
Given a set of numbers where all elements occur an even number of times except one number, find
the odd occurring number.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4,2,2,1,5,6,7,5,6,7,4,1,10};
    long long res = 0;
    for(auto x : arr) res ^= x;
    cout<<res<<endl;
    return 0;
}