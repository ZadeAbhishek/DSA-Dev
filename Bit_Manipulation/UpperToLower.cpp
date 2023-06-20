// Bitwise Or of a Uppercase Charector with ' ' will set the third significant bit and will get lowercase charector 

#include<bits/stdc++.h>
using namespace std;

// we can convert uppercase to lowercase bu or char with space (c | ' ')

char toLower(char c){
    return (c | ' ');
}

int main(){
    char c;
    cin>>c;
    cout<<toLower(c)<<endl;
}