/*
*Given a string s, find the first non-repeating character 
 in it and return its index. If it does not exist, return -1.

*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(128,0);
        for(auto x : s) hash[(int)x]++;
        for(auto x = 0 ; x < s.size() ; x++) if(hash[(int)s[x]] == 1) return x; 
        return -1;
    }
};

