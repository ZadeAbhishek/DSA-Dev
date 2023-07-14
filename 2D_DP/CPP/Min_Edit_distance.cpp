// given two strings we have to give min number of operation to make them eqaul
// for example "ABCD" "BCD" here min operation will be 1 as we are deleting only A
// allowed operation are delete,Add,replace

// this can be solved using dp 
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>


// TC exponetial SC o(1)
int min_Distance(std::string s , std::string t,int i , int j){
    // base case (if any one string is bigger tan other so we need to perform add string operation therefore just return lenght)
    if(i >= s.size()) return t.size() - j - 1;
    if(j >= t.size()) return s.size() - i - 1;
    //int ans = INT_MAX;
    if(s[i] == t[j]) return min_Distance(s,t,i+1,j+1);
    else{
        // if not equal 
        
        // insert
        int insert = 1 + min_Distance(s,t,i,j+1);
        // delete
        int del = 1 + min_Distance(s,t,i+1,j);
        // replace
        int replace = 1 + min_Distance(s,t,i+1,j+1);

        return std::min(insert,std::min(del,replace));
 
    }
}


// TC O(n * m) n  = s.length  m = t.lenght
// SC O(n * m) + Aluxilary stack space
int min_Distance_dp(std::string s , std::string t,int i , int j, std::vector<std::vector<int>> &dp){
    // base case (if any one string is bigger tan other so we need to perform add string operation therefore just return lenght)
    if(i >= s.size()) return t.size() - j - 1;
    if(j >= t.size()) return s.size() - i - 1;

    // dp case
    if(dp[i][j] != -1) return dp[i][j];

    //int ans = INT_MAX;
    if(s[i] == t[j]) return min_Distance_dp(s,t,i+1,j+1,dp);
    else{
        // if not equal 
        
        // insert
        int insert = 1 + min_Distance_dp(s,t,i,j+1,dp);
        // delete
        int del = 1 + min_Distance_dp(s,t,i+1,j,dp);
        // replace
        int replace = 1 + min_Distance_dp(s,t,i+1,j+1,dp);

        return dp[i][j] = std::min(insert,std::min(del,replace));
 
    }
}


int min_Distance_tab(std::string s , std::string t){

    std::vector<std::vector<int>> dp(s.size()+1,std::vector<int>(t.size()+1,-1));
   
    for(int i = 0 ; i <= s.size() ; i++) dp[i][t.length()] = s.length()-i-1;
    for(int j = 0 ; j <= t.size() ; j++) dp[s.length()][j] = t.length()-j-1;

    for(int i = s.size()-1 ; i >= 0 ; i--){
        for(int j = t.size()-1 ; j >= 0 ; j--){
         int ans = 0;   
        if(s[i] == t[j]) ans =  dp[i+1][j+1];
    else{
        // if not equal 
        
        // insert
        int insert = 1 + dp[i][j+1];
        // delete
        int del = 1 + dp[i+1][j];
        // replace
        int replace = 1 + dp[i+1][j+1];

        ans = std::min(insert,std::min(del,replace));
 
    }
    dp[i][j] = ans; 
 }
    }
    return dp[0][0];
}

// we can optimised more see love babar video on this topic



int get_Min_Distance(std::string s , std::string t){
     // base case
     if(s.size() == 0) return t.size();
     if(t.size() == 0) return s.size();

     std::vector<std::vector<int>> dp(s.size()+1,std::vector<int>(t.size()+1,-1));

     return min_Distance_tab(s, t);

}

int main(){
    std::string s = "ABCD";
    std::string t = "BCDAASD";
    std::cout<<get_Min_Distance(s,t); 
}