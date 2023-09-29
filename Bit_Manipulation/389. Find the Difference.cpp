class Solution {
public:
    char findTheDifference(string s, string t) {
       vector<int> hash(27,0);
       for(auto &x : s) hash[(x - 'a')]++;
       char result;
       for(auto &x : t) {
           if(hash[(x - 'a')]==0) result = x;
           hash[(x - 'a')]--;
       }
       return result;
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int x , y;
        x = y = 0;
        int n = s.size();
        int m = t.size();
        char result;
        while(y < m){
          if(s[x] != t[y]) result = t[y], y++;
          else x++,y++;
        }
        return result;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        s+=t;
        int c = 0;
        for(auto &x : s) c^=x;
        return c;
    }
};