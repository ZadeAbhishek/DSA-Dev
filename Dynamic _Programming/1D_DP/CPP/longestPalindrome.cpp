#include <bits/stdc++.h>
using namespace std;



// this solution is O(n^3) :-> O(n^2) for loop * o(n) for pallindrome logic 
class Solution {
public:
    string ans;
    vector<string> anws;
    bool pallindrome(string s){
        
        stack<char> table;
        for(auto x = 0 ; x < size(s) ; x++){
            table.push(s[x]);
        }
        string y = s;
        for(auto x = 0 ; x < size(s) ; x++){
            y[x] = table.top();
            table.pop();
        }
        
        if(s == y) return true;
        
        else return false;
    }
    
    string longestPalindrome(string s, int x, string res) {
        for(auto i = 0 ; i < size(s) ; i++){
             res.clear();
            for(auto j = i ; j < size(s) ; j++){
                res.push_back(s[j]);
                if(pallindrome(res)){
                    anws.push_back(res);
                    //ans = res;
                }
            }
        }
         int y = 0;
       for(auto x : anws){
          if(size(x) > y){
            y = size(x);
            ans = x;
          }
       }
        return ans;
    }
    
    string longestPalindrome(string s) {
    if(size(s) == 1) return s;
    string result = "";
    string t = longestPalindrome(s,0,result);  
    return t;    
    }
};


class Solution2 {
public:

    
    string longestPalindrome(string s) {
     // idea is to use matrix here 
     vector<vector<char>> tab(size(s),vector<char>(size(s)));
     string res;
     int max = 0;
     // we are going to irrterate using diff of string
     // for example conside babad
     // for each individual char they are pallindrome i.e for i = j s[i][j] = 1;
     // next irr ie ba is not there s[0][1] = 0;
     // when we check bab first we will check if s[i] == s[j] yes it is equal and s[i-1] and s[j-1] = 1 
     // then s[i][j] == s[i-1][j-1] + 2 <-- 2 for current charector

     for(auto diff = 0 ; diff < size(s) ; diff++){
        for(auto i = 0, j = i + diff ; j < size(s); i++ , j++ ){
            if(diff == 0){
                tab[i][j] = 1;
            }
            else if(diff == 1){
                tab[i][j] = (s[i] == s[j])? 2:0;
            }
            else {
                if(s[i] == s[j] && tab[i+1][j-1]){
                    tab[i][j] = tab[i+1][j-1] + 2;
                }
            }
            if(tab[i][j]){
                if((j-i+1) > max){
                res = s.substr(i,j-i+1);
                max = (j-i+1);
                }
            }

        }
     }
     return res;     
    }
};



int main (){
string s = "babad";
  Solution2 *solve =  new Solution2();
  cout<<solve->longestPalindrome(s);
}