#include<bits/stdc++.h>
using namespace std;


int main(){
    string s = "121";
    // to check weather string is pallindrome
    int j = size(s) - 1 , k = 0;
    cout<<s[j]<<"\n";
    cout<<s[k]<<"\n";
    while(s[j--] == s[k++] && j != k){
        cout<<s[j]<<"\n";
        cout<<s[k]<<"\n";
    }

    if(j == k && s[j + 1] == s[k - 1]) cout<<true;
    else cout<<false;
}