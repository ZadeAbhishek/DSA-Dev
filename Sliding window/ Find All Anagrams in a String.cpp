// we can optimised more of this 

class Solution {
public:
    
    bool check_anagram(string s,vector<int> aux_p){
        vector<int> temp(200,0);
        
        for(auto x : s) temp[(int)x]++;
        
        int i = 0;
        
        while(i < 200) {
            if(!(temp[i] == aux_p[i])) return false;
            i++;
        }
        return true;
        
    } 
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> aux_p(200,0);
        
        vector<int> result;
        
        for(auto x : p) aux_p[(int)x]++; // compelte aux with p string
        
        int x = 0 , y = size(p);
        
        while(y <= size(s))
        {
           bool res = check_anagram(s.substr(x,size(p)),aux_p);
            
            if(res) {
                result.push_back(x);
                res = false;
            }
            
            x++;
            y++;
        }
        
        return result;
    }
};


// optimised version