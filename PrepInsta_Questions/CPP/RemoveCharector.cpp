// Write a code to Remove all characters from string except alphabets
// o(n) but space is double the original string
#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main (){
    char string[100];
    int i = 0;
    //cout<<"Etr string";
    cin.getline(string,sizeof string);
    char temp[100];
    for(auto it : string){
        if(((it >= 'a' && it <= 'z') ||(it >= 'A' && it <= 'Z'))){
           temp[i]  = it;
           i++;
        }
    }
    puts(temp);
    cout<<temp;
    return 0;
}
