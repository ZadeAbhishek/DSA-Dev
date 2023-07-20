// ip "geeks"
// c = 'e'
// op "gksforgks"

#include<iostream>
#include<string.h>
using namespace std;


string remove_char(string &s, char r){
    int n = s.size();
    int j = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] != r) s[j++] = s[i];
    };
    s[j] = '\0';
    return s;
}

int main(){
    string s;
    cin>>s;
    char r;
    cin>>r;
    cout<<remove_char(s,r)<<"\n";
}