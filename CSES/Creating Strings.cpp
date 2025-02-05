/*
Time limit: 1.00 s
Memory limit: 512 MB



Given a string, your task is to generate all different strings that can be created using its characters.
Input
The only input line has a string of length n. Each character is between a–z.
Output
First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.
Constraints

1 \le n \le 8

Example
Input:
aabac

Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa

 */

#include<bits/stdc++.h>
using namespace std;


void getPer(string s, set<string>& result, string curr, vector<int>& vis){
     if(curr.size() == s.size()){
        result.insert(curr);
        return;
     }

     for(auto i = 0 ; i < s.size(); i++){
         if(vis[i] != 1){
            vis[i] = 1;
            getPer(s,result,curr + s[i],vis);
            vis[i] = 0;
         }
     }

     return;
}

int main(){
    string s;
    cin>>s;

    set<string> result;
    vector<int> vis(s.size(),0);
    string temp = "";
    getPer(s,result,temp,vis);
    cout<<result.size()<<endl;
    for(auto x : result) cout<<x<<endl;
    return 0;
}