/*
Time limit: 1.00 s
Memory limit: 512 MB

A border of a string is a prefix that is also a suffix of the string but not the whole string. For example, the borders of abcababcab are ab and abcab.
Your task is to find all border lengths of a given string.
Input
The only input line has a string of length n consisting of characters a–z.
Output
Print all border lengths of the string in increasing order.
Constraints

1 \le n \le 10^6

Example
Input:
abcababcab

Output:
2 5
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string text = "";
    cin>>text;
    vector<int> result;
    for(int i = 1 ; i < text.size() ; i++){
       string prefix = text.substr(0,i);
       string suffix = text.substr(text.size() - i,i);
       if(prefix == suffix) result.push_back(prefix.size());
    }
    for(auto &x : result){
      cout<<x<<" ";
    }
    cout<<"\n";
    return 0;

}