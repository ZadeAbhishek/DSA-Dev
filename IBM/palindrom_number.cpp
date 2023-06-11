#include<bits/stdc++.h>
using namespace std;

int main() {
    
    // int x = 2222222;

    // string s = to_string(x); 

    string s = "aba";
        
    int j = size(s) - 1 , k = 0;

    while(s[j--] == s[k++] && j - k >= 1);

    if(s[j+1] == s[k-1]) cout<<true;
    
        else cout<<false;
    
    }