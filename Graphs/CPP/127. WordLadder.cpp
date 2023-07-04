#include<bits/stdc++.h>
using namespace std;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // SO this can be solved using bfs 
        unordered_set<string> hash(wordList.begin(),wordList.end()); // this is set
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        hash.erase(beginWord);
        while(!q.empty()){
            auto c = q.front();
            q.pop();
            auto curr = c.first;
            auto step = c.second;
            if(curr == endWord) return step;
            for(auto x = 0 ; x < curr.size() ; x++){
                 auto orignal = curr;
                for(auto y = 'a' ; y <= 'z' ; y++){
                    curr[x] = y;
                    if(hash.find(curr) != hash.end()){
                        q.push({curr,step+1});
                        hash.erase(curr);
                    }
                }
                curr = orignal;
            }
        }
        return 0;
    }

int main(){
    vector<string> word = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength("hit","cog",word);
}