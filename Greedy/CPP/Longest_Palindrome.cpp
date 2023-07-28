#include<bits/stdc++.h>
using namespace std;
  
  
  int longestPalindrome(const string &s) 
    {
        int count[128]{};
        for (auto c : s) ++count[c];
        
        // count all old alphabets
        for (auto num : count) count[0] += num & 1;

        // delete all alphabates and only keep one at end i.e all even + one odd
        return s.size() - count[0] + (count[0] > 0);
    }

int main(){
    string s = "abccccdd";
    cout<<longestPalindrome(s);

}