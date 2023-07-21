// demo of fuction pointer for int to char
#include<bits/stdc++.h>
using namespace std;

/* we can add edge cases here */
char convert(int x){return (char)x;}

int main(){

    char (*covert_pointer)(int);

    covert_pointer = convert;

    char result = covert_pointer(97);

    cout<<result<<"\n";
}