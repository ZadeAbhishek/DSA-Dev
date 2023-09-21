#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isConnected(string s,string t){
        int c=0;
        for(int i=0;i<s.length();i++)
            c+=(s[i]!=t[i]);
        return c==1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;        
        vector<vector<string>> nodes;   
        unordered_set<string> dict(wordList.begin(),wordList.end());
        
        if (!dict.count(endWord)) return ans;
        dict.erase(beginWord);
        
        
        bool reached = false;
        nodes.push_back({beginWord});
        
        while (dict.size() && !reached) {                        
            vector<string> last = nodes.back();
            vector<string> curr;
                        
            for (int i = 0; i < last.size() && !reached; i++) {
                unordered_set<string> visited;
                string from = last[i];                                
                // check all nodes that connect
                // to the nodes of the previous level                
                for (auto& to : dict) {                    
                    if (visited.count(to)) continue;
                    if (!isConnected(from, to)) continue;                                        
                    // if one of them is "endWord" then we can stop 
                    // because this level is the shortest distance from begin
                    if (to == endWord) {                        
                        reached = true; 
                        break;
                    }
                    
                    // otherwise,
                    // add nodes for the current level
                    curr.push_back(to);   
                    visited.insert(to);                    
                }   
                // delete the visited to prevent forming cycles            
                for (auto& visited : visited) {                
                    dict.erase(visited);
                }
            }
            
            // found endWord this level
            if (reached) break;
            
            // can not add any new nodes to our level
            if (!curr.size()) break;
            
            // otherwise, record all nodes for the current level
            nodes.push_back(curr);            
        }
        
        // try but not find
        if (reached == false) return ans;
        
        // move backward
        ans.push_back({endWord});          
        for (int level = nodes.size() - 1; level >= 0; level--) {                        
            int alen = ans.size();
            while (alen) {
                vector<string> path = ans.back();
                ans.pop_back();
                string from = path.front();                
                for (string &to : nodes[level]) {                    
                    if (!isConnected(from, to)) continue;
                                        
                    vector<string> newpath = path;
                    newpath.insert(newpath.begin(), to);
                    ans.insert(ans.begin(), newpath);
                }    
                alen--;
            }             
        }
        return ans;
    }
};

void operator<<(ostream &OUT,vector<vector<string>> list){
    for(auto &x : list){
        for(auto &y : x){
            OUT<<y<<" ";
        }
        cout<<"\n";
    }
    return;
}

int main(){

    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string start = "hit";
    string end = "cog";
    Solution solve;
    cout<<solve.findLadders(start,end,wordList);
}