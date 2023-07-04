#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<unordered_set>


std::unordered_map<int,int> dp;
std::unordered_map<std::string,bool> hash;
std::unordered_set<std::string> setHash;

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

// optimised
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
            if(setHash.find(temp)!=setHash.end()) memo[i] = memo[j+1]?1:0;
             
        }
    }
    return memo[0];
    

}

bool solve3(std::string s){
    //base case 

    //Dp check
    if(s.size() == 1 && hash[s] != true) return false;
    if(hash[s] == true) return hash[s];
    

    for(int i = 0; i < s.size() ; i++){
        std::string part1 = s.substr(0,i+1);
        std::string part2 = s.substr(i+1,s.size()-i);
        std::cout<<part1<<" "<<part2<<"\n";
        if(solve2(part1) && solve2(part2)) return hash[s] = true;
    }

    return hash[s] = false;

}

int main(){
    std::string s ="aaaaaaa";
    std::vector<std::string> wordDict = {"aa","aaaa"};
    for(auto s : wordDict) hash.insert({s,true});
    setHash.insert(wordDict.begin(),wordDict.end());
    std::cout<<solve2(s);
}