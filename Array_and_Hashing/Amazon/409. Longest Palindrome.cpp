// ##Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        // get all even numbers string and one odd to it if available
        unordered_map<char,int> hash;
        for(auto x : s) hash[x]++;
        int checkOdd = 0;
        int even = 0;
        for(auto &x : hash){
            char c = x.first;
            int count = x.second;
            if(count % 2 == 0) even += (count);
            else {
                if(count > 2) even += (count - 1);
                checkOdd = 1;
            }
        }

        return even + (checkOdd?1:0);
    }
};