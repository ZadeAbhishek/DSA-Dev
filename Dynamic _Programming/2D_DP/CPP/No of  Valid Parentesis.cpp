#include<bits/stdc++.h>
using namespace std;
 

    bool isValid(char t,char s) {
        if(t == '{' && s == '}') return true;
        else if(t == '(' && s == ')') return true;
        else if(t == '[' && s == ']') return true;
        else return false;

    } 


    int getValidityCount(string &s, int start , int end, vector<vector<int>> &memo){
        // base case 
        if(start > end) return 0;
        
        // memoization
        if(memo[start][end] != -1) return memo[start][end];
        // Solver
        int maxCount = 0;
        for(int curr = start ; curr < end ; curr++){
            int currMax = 0;
            if(!isValid(s[curr],s[end])) currMax = 0 + getValidityCount(s,start,curr-1,memo) + getValidityCount(s,curr+1,end-1,memo);
            else currMax = 1 + getValidityCount(s,start,curr-1,memo) + getValidityCount(s,curr+1,end-1,memo);

            maxCount = max(maxCount,currMax); 
        }
        return memo[start][end] = maxCount; 
        
    }

    int longestValidParentheses(string s) {
        // Partition DP
        int string_Lenght = s.size();
        s.push_back('#');
        s.insert(s.begin(),'#');
        vector<vector<int>> meme(string_Lenght+1,vector<int>(string_Lenght+1,-1));
        return getValidityCount(s,1,string_Lenght,meme);
    }


int main(){
   string s = "((()()))";
   cout<<longestValidParentheses(s);
}