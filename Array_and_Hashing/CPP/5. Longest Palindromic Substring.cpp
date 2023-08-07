#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    string longestPalindrome(string s) {
     if(s.size() <= 1) return s;
     // idea is to use matrix here 
     vector<vector<int>> tab(s.size(),vector<int>(s.size(),0));
     string res;
     int start = 0;
     long max = INT_MIN;

     for(auto diff = 0 ; diff < size(s) ; diff++){
        for(auto i = 0, j = diff ; j < size(s); i++ , j++ ){
            if(diff <= 1){
            if(diff == 0) tab[i][j] = 1;
            if(diff == 1) tab[i][j] = (s[i] == s[j])? 2:0;
            }
            else {
            if(s[i] == s[j] && tab[i+1][j-1]) tab[i][j] = tab[i+1][j-1]+1;
            else if(s[i] == s[j] && !tab[i+1][j-1]) tab[i][j] = tab[i+1][j-1];
            else tab[i][j] = 0;
            }

            if(tab[i][j]){
                if((j-i+1) > max){
                
                start = i;
                max = (j-i+1);
                }
            }
        }
     }
 
     if(max != INT_MAX) res = s.substr(start,max); 

     return res;     
    }
};


//pointr approch 
class Solution {
public:
    string longestPalindrome(string s) {
        
        string ans="";
        int start=0;
        int end=0;
        int len=0;
        int n=s.size();

        for(int i=1;i<n;i++)
        {
            // for odd
            int st=i-1;
            int en=i+1;
            while(st>=0 && en<n && s[st]==s[en])
            {
                if(en-st+1>len)
                {
                    len=en-st+1;
                    start=st;
                    end=en;
                }
                st--;
                en++;
            }

            // for even
            st=i-1;
            en=i;
            while(st>=0 && en<n && s[st]==s[en])
            {
                if(en-st+1>len)
                {
                    len=en-st+1;
                    start=st;
                    end=en;
                }
                st--;
                en++;
            }
        }

        for(int i=start;i<=end;i++)
        {
            ans+=s[i];
        }

        return ans;
    }
};

// brut force approch 

class Solution {
private: 
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
}; 


int main(){}