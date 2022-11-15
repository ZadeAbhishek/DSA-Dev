#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int x = 121;

    string s = to_string(x); 
        
    int j = size(s) - 1 , k = 0;

    while(s[j--] == s[k++] && j - k != 1);

    if(j - k == 1) cout<<true;
    
        else cout<<false;
    
    }