#include<bits/stdc++.h>
using namespace std;

// back traking solution
// Tc complexity here is O(3^N); // since we have 3 possiblity
// Sc o(1);
// tle mara 
class Solution {
public:
    
    bool isValid(string &s){
        int balance = 0;
        for(auto &x : s){
            if(x == '*') continue;
            
            if(x == '(') balance += 1;
            else balance -= 1;

            if(balance < 0) return false;
        }

        if(balance == 0) return true;

        else return false;
    }


    bool getCombinations(string s , int s_size, int start){
         // base case
         if(start >= s_size) return false;

         if(isValid(s)) return true;

         for(int i = start ; i < s_size ; i++){

             if(s[i] == '*'){

                // case 1
                bool nc = getCombinations(s,s_size,start+1);
                s[i] = '(';
                bool  open = getCombinations(s,s_size,start+1);
                s[i] = ')';
                bool close = getCombinations(s,s_size,start+1);
                s[i] = '*'; 
                return open || close || nc;             
             }
             continue; 
         }

         return false;
    }



    bool checkValidString(string s) {
       int s_Size = s.size();
       return getCombinations(s,s_Size,0); 
    }
};

class Solution {
public:

    bool getCombination(string &s , int &s_size , int index , int openCount, vector<vector<int>> &dp){
        // base case
        if(index == s_size){
            // check if any open left
            if(openCount == 0) return true;
            else return false;
        }

        if(dp[index][openCount] != -1) return dp[index][openCount];

        bool ans = false;
        if(s[index] == '*'){
           ans |= getCombination(s,s_size,index+1,openCount+1,dp);
           if(openCount > 0) ans |= getCombination(s,s_size,index+1,openCount-1,dp);
           ans |= getCombination(s,s_size,index+1,openCount,dp);

        }
        else{
            if(s[index] == '(') ans = getCombination(s,s_size,index+1,openCount+1,dp);
            else{
                if(openCount > 0) ans = getCombination(s,s_size,index+1,openCount-1,dp);
            }
        }

        return dp[index][openCount] = ans;
    }


    bool checkValidString(string s) {
       int s_size = s.size();
       vector<vector<int>> dp(s_size+1,vector<int>(s_size+1,-1));
       return getCombination(s,s_size,0,0,dp);
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> open;
        stack<int> star;

        for(int i = 0; i < n ; i++){
            if(s[i]=='(')open.push(i);
            else if(s[i]=='*')star.push(i);
            else{
                if(open.empty() && star.empty())return false;
                if(!open.empty())open.pop();
                else star.pop();
            }
        }

        // cout<<open.size()<<" "<<star.size()<<endl;

        if(!open.empty()){
            if(open.size()>star.size())return false;
            else{
                while(!open.empty()){
                    if(open.top()>star.top())return false;
                    star.pop();
                    open.pop();
                }
            }
        }

        return true;
    }
};

int main(){
    Solution2 s;
    string k = "(*))";
    cout<<s.checkValidString(k)<<endl;
}

// expected false