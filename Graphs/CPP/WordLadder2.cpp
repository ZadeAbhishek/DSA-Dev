 

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
          // SO this can be solved using bfs 
        unordered_set<string> hash(wordList.begin(),wordList.end());
        vector<vector<string>> res;
        queue<vector<string>> q;
        q.push({beginWord});
        int level = 0;
        while(!q.empty()){
            auto currArr = q.front();
            q.pop();
            auto curr = currArr[currArr.size()-1];
            if(currArr.size()>level){
                level++;
                for(auto x : currArr){
                   hash.erase(x);
                }
            }

            if(currArr.back() == endWord){
                if(res.size() == 0) res.push_back(currArr);
                else if(res[0].size() == currArr.size()) res.push_back(currArr);
            }
            for(auto x = 0 ; x < curr.size() ; x++){
                 auto orignal = curr;
                for(auto y = 'a' ; y <= 'z' ; y++){
                    curr[x] = y;
                    if(hash.find(curr) != hash.end()){
                        currArr.push_back(curr);
                        q.push(currArr);
                        currArr.pop_back();
                    }
                }
                curr = orignal;
            }
        }
        return res;
    }
};