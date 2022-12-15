#include<bits/stdc++.h>
using namespace std;


int main (){


    string s = "uoy evol I";
    int i = 0 , j = size(s) - 1;
    char temp;
    while(i <= j) temp = s[i], s[i] = s[j], s[j] = temp ,i++, j--;   
    cout<<s<<endl;
}