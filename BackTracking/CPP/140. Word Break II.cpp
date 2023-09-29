#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(string s, unordered_set<string> &hash, vector<string> &result, vector<string> & temp){
        // base case
        if(s.size() == 0){
            string x = "";
            for(auto &i : temp) x += i + " ";
            x.pop_back();
            result.push_back(x);
            return;
        }

        string curr = "";
        for(int i = 0 ; i < s.size(); i++){
            curr.push_back(s[i]);
            if(hash.find(curr) != hash.end()){
                temp.push_back(curr);
                solve(s.substr(i+1),hash,result,temp);
                temp.pop_back();
            }
        }

        return;
    }



    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        // back tracking works here
        unordered_set<string> hash(wordDict.begin(),wordDict.end());
        vector<string> result;
        vector<string> temp;
        solve(s,hash,result,temp);
        return result;
    }
};


int main(){}