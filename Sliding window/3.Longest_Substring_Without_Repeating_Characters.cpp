#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(string s) {
    if(s.empty()) return false;
    int result = 0;
    int start = 0;

    vector<bool> char_in_string;
    char_in_string.resize(256);

    for(auto i = 0 ; i < s.size() ; ++i){
        while(char_in_string[s[i]]){
            char_in_string[s[start++]] = false; //wrks like slidding windows 
        }
        char_in_string[s[i]] = true;

        result = max(result,i-start+1);
    }
    return result;
}


int main(){
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s)<<endl;

}