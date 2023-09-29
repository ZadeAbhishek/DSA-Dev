#include<bits/stdc++.h>
using namespace std;

bool vov(char x){
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true;
    return false;
}


string reverseVovel(string s){
    // idea is to store vovle in array with index 
    vector<int> index;
    vector<char> vovle;

    for(auto i = 0 ; i < s.size() ; i++) if(vov(s[i])) index.push_back(i), vovle.push_back(s[i]);
    reverse(index.begin(),index.end());
    int i = 0;
    for(auto x : index) s[x] = vovle[i++];

    return s;
}


/*

optimised

class Solution {
public:
    bool checkForVowel(char chr){
        if(chr=='a' || chr=='e' || chr=='i' || chr=='o' || chr=='u' || chr=='A' || chr=='E' || chr=='I' || chr=='O' || chr=='U' )
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0,j=n-1;
        while(i<j){
            if(checkForVowel(s[i]) && checkForVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(checkForVowel(s[i]))
                j--;
            else if(checkForVowel(s[j]))
                i++;
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};



*/

int main(){
    string s = "hello";
    cout<<reverseVovel(s)<<"\n";
}