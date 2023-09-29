// Dynamic is efficient this will caluse TLE after sometime

class Tries{
     Tries* children[26] = {};
     bool isWord = false;

     public:
     void insert(string word){
         Tries* curr = this;
         for(auto c : word){
             c -= 'a';
             if(curr->children[c] == nullptr){
                 curr->children[c] = new Tries();
             }
             curr = curr->children[c];
         }
         curr->isWord = true;
     }

     bool checkWord(string word){
         Tries* curr = this;
         for(auto c : word){
             c -= 'a';
             if(curr->children[c] == nullptr) return false;
             curr = curr->children[c];
         }
        return curr->isWord; 
     }

     bool checkWordPre(string word){
         Tries* curr = this;
         for(auto c : word){
             c -= 'a';
             if(curr->children[c] == nullptr) return false;
             curr = curr->children[c];
        }
        return true;
     }
};

class Solution {
    Tries *t = new Tries(); 
 public:
    
    bool checkWords(Tries* t,string s){
        if(s.size() == 0) return true;
        int n = s.size();
        for(auto i = 1 ; i <= n ; i++){
            string temp = s.substr(0,i);
            string temp2 = s.substr(i,n-i);
            if(t->checkWord(temp) && checkWords(t,temp2)) return true;
        }
        return false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict) t->insert(x); // insert into tries

        return checkWords(t,s);

    }
};


// Modified with dp
class Tries{
     Tries* children[26] = {};
     bool isWord = false;

     public:
     void insert(string word){
         Tries* curr = this;
         for(auto c : word){
             c -= 'a';
             if(curr->children[c] == nullptr){
                 curr->children[c] = new Tries();
             }
             curr = curr->children[c];
         }
         curr->isWord = true;
     }

     bool checkWord(string word){
         Tries* curr = this;
         for(auto c : word){
             c -= 'a';
             if(curr->children[c] == nullptr) return false;
             curr = curr->children[c];
         }
        return curr->isWord; 
     }

     bool checkWordPre(string word){
         Tries* curr = this;
         for(auto c : word){
             c -= 'a';
             if(curr->children[c] == nullptr) return false;
             curr = curr->children[c];
        }
        return true;
     }
};

class Solution {
    Tries *t = new Tries(); 
 public:
    
    bool checkWords(Tries* t,string s,unordered_map<string,int> &dp){
        if(s.size() == 0) return true;
        if(dp[s]) return true;
        int n = s.size();
        for(auto i = 1 ; i <= n ; i++){
            string temp = s.substr(0,i);
            string temp2 = s.substr(i,n-i);
            if(t->checkWord(temp) && checkWords(t,temp2,dp)) return dp[s] = true;
        }
        return dp[s] = false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict) t->insert(x); // insert into tries
        unordered_map<string,int> dp;
        return checkWords(t,s,dp);

    }
};