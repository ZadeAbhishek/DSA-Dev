#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<unordered_set>


std::unordered_map<int,int> dp;
std::unordered_map<std::string,bool> hash;
std::unordered_set<std::string> setHash;

//not workig
bool solve(std::string s, int index){
    //base case 
    if(index == s.size()) return false;

    //Dp check
    if(dp[index]) return true;

    for(int i = index; i < s.size() ; i++){
        std::string part1 = s.substr(index,i-index+1);
        std::cout<<part1<<"\n";
        if(hash.count(part1) && solve(s,i+1)) return dp[index] = true;
    }

    return dp[index] = false;

}


// working
// optimised most better than solve 3
bool solve2(std::string s){
    //base case 
    int size = s.size();
    int memo[size+1];
    memset(memo,0,sizeof memo);
    memo[size] = 1;
    for(int i = size-1 ; i >= 0 ; i--){
         std::string temp;
        for(int j = i ; j < size ; j++){
            temp.push_back(s[j]);
            if(setHash.find(temp)!=setHash.end() && memo[i] != 1) memo[i] = memo[j+1]?1:0;
             
        }
    }
    return memo[0];
    

}

 bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string>word_set(wordDict.begin(),wordDict.end());
        int n=s.size();
        std::vector<bool>dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            if(!dp[i])continue;
            for(int j=i+1;j<=n;j++){
                if( word_set.count(s.substr(i,j-i)))
                dp[j]=1,std::cout<<j<<"\n";
            }
        }
        return dp[n];
}

bool solve3(std::string s){
    //base case
    if(s.size() == 1 && hash.count(s) && hash[s] == true) return true;

    if(s.size() == 1 && !hash.count(s)) return false; 

    //Dp check


    if(hash.count(s)) return hash[s];
    

    for(int i = 0; i < s.size()-1 ; i++){
        std::string part1 = s.substr(0,i+1);
        std::string part2 = s.substr(i+1,s.size()-i);
        if(solve3(part1) && solve3(part2)) return hash[s] = true;
    }

    return hash[s] = false;

}

int main(){
    std::string s ="leetcode";
    std::vector<std::string> wordDict = {"leet","code"};
    // for(auto s : wordDict) hash.insert({s,true});
    // setHash.insert(wordDict.begin(),wordDict.end());
    std::cout<<wordBreak(s,wordDict);
}