#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
using namespace std;


class Solution {
    unordered_map<char,unsigned int> s1; 
public:
   bool isAnagram(string s, string t) {
       for(auto  i = 0; i < s.size(); i++){
           if(!s1.count(s[i])) s1.insert({s[i],1});
           else s1[s[i]]++;
        }
      for(auto  i = 0; i < t.size(); i++){
           if(!s1.count(t[i])) return false;
           else s1[t[i]]--;
        }
        for(auto  i = 0; i <= 128; i++) if(s1[(char)i] != 0) return false;
        return true;
   }

    bool isAnagram_2(string s, string t) {
 
     // anagram so idea is to use two array of 2 * 128 bytes 
    signed int arr_string[128] = { 0 }; // sc->o(n);

    for(auto iterator : s) arr_string[(signed int)iterator]++; //T(size(s))

    for(auto iterator : t) arr_string[(signed int)iterator]--; //T(size(t))

    for(auto i = 0 ; i < 128 ; i++) if(arr_string[i] != 0) return false; // T(128) 

    return true;  

   }
};


int main (){
     string  s = "Aabbcccc";
     string  t = "Aabbcccc"; 
    Solution* solve = new Solution();    
    bool result = solve->isAnagram_2(s,t);
    cout<<result<<" "<<endl;

}