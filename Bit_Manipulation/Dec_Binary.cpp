// Binary reprsentation of Decimal
#include<bits/stdc++.h>
using namespace std;


string Binary(int x){
    string s = "";
    for(int i = 32 ; i >= 0; i--){
        int mask = 1<<i;
        if(mask & x) s.push_back('1');
        else s.push_back('0');
    }
    return s;
}

int main(){
    int x;
    cin>>x;
    cout<<Binary(x)<<"\n";
}