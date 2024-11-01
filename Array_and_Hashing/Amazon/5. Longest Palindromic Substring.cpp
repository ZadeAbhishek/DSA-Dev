// ##DP
// Midle Expansion technique will work
class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int start = 0;
        int end = s.size() - 1;
        
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        // may be two pointer approch we can use here
        if(s.size() < 2) return s;
        int maxSize = 0; 
        string result = "";
        for(auto i = 0 ; i < s.size(); i++){
            string temp = "";
            for(auto j = i ; j < s.size(); j++){
                temp += s[j];
                if(isPalindrome(temp) && temp.size() > maxSize){
                    maxSize = temp.size();
                    result = temp;
                }
            }
        }
        return result;
    }
};


class Solution {
    int maxLenght = 0;
    string st = "";
    string result = "";
    int leftMax = 0;
    int rightMax = 0;
    void checkPalindrome(int start, int end){
          while(start >= 0 && end < st.size() && st[start] == st[end]){
              if(end - start + 1 > maxLenght){
                leftMax = start;
                rightMax = end;
                maxLenght = rightMax - leftMax + 1; 
              }
              start--;
              end++;
          }
    }
public:
    string longestPalindrome(string s) {
        // Midle Expansion technique will work
        st = s;

        for(int i = 1 ; i < st.size(); i++){
             checkPalindrome(i-1,i+1);
             checkPalindrome(i-1,i);
        }
        return s.substr(leftMax,(rightMax - leftMax + 1));

    }
};