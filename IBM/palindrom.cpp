#include<bits/stdc++.h>
using namespace std;


int main(){
    string s = "aa";

    if(size(s)== 1) return true;
    // to check weather string is pallindrome
    int j = size(s) - 1 , k = 0;
    while(s[j--] == s[k++] && j != k && j > 0 && k < size(s) - 1);

    if(j == k && s[j + 1] == s[k - 1]) cout<<true;
    else if(j == 0 && k == size(s)-1) cout<< true;
    else cout<<false;
}