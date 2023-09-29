/*
Bitwise Xor of an upperCase or Lowercase char with ' 'will 
toggle the third significant bit, Uppercase becomes lowercase and Viseversa

*/

#include<bits/stdc++.h>
using namespace std;

char InvertCase(char c){
    return (c ^ ' ');
}

int main(){
    char c;
    cin>>c;
    cout<<InvertCase(c)<<endl;
}