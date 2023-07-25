#include<bits/stdc++.h>
using namespace std;

// Pangram every letter must be present in sentace 

int main() {
    // hashmap
    unordered_map<char,bool> table;
    int i = 97; // ascci of a = 97 z = 122
    while(i<123){
        table.insert({char(i),false});
        i++;
    }
    string s = "The quick brown fox jumps over the lazy dog";
    i = 0;
    while(i != s.size()){
        if(table.count((char)tolower(s[i]))){
            table[s[i]] = true;
        }
        i++;
    }
    i = 97;
    while(i < 123){
        if(table[(char)i]){
        i++;
        continue;
        }
        else{
            cout<<false;
            return false;
        }
    }
    cout<<true; 
   return true;
}
