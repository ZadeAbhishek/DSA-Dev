#include<bits/stdc++.h>
using namespace std;


int main (){


    string s = "]ecitcarP smhtiroglA arodef-derahs@rekcah[";
    int i = 0 , j = size(s) - 1;
    char temp;
    while(i <= j) temp = s[i], s[i] = s[j], s[j] = temp ,i++, j--;   
    cout<<s<<endl;
}