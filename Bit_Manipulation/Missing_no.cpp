// Find missing number in an array:
#include<bits/stdc++.h>
using namespace std;


int missing(vector<int> &x){
    int Xor = 0;
    for(auto i = 0; i < x.size() ; i++) Xor ^= x[i];
    for(auto i = 1; i <= x.size() ; i++) Xor ^= i;
    return Xor;
}

int main(){
    vector<int> x = {3,0,1};
    cout<<missing(x)<<"\n";
}
