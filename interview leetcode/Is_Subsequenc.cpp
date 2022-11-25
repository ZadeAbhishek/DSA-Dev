class Solution {
public:
    bool isSubsequence(string s, string t) {
        // assuming t i always big
        
        int x = 0 , y = 0; // pointer
        
        int i = 0;
        
        while(i < size(t))
        {
            if(x > size(s)) break;
            
            if(t[i] == s[x]) x++;
            
            i++;
        }
        
     if(x >= size(s)) return true;
     else return false;
    }
};