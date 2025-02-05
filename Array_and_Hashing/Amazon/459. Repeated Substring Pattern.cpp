class Solution {
    bool check(string s, string x){
        int stringSize = x.size();
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == x[j]){
                j++;
                j %= stringSize;
            }
            else {
                return false;
            }
        }
        return j == 0; // Ensure the string fully cycles
    }
public:
    bool repeatedSubstringPattern(string s) {
        unordered_set<string> hash;
        string tempStr = "";
        
        // Store only valid prefixes (whose lengths divide `s.size()`)
        for(int i = 0; i < s.size() - 1; i++){
            tempStr += s[i];
            if(s.size() % tempStr.size() == 0) {
                hash.insert(tempStr);
            }
        }

        hash.erase(s);
        
        // Check if any valid prefix repeats to form `s`
        for(auto &x : hash){
            if(s.find(x) != string::npos) return true;
        }
        
        return false;
    }
};


// underatand this approch 

#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubleS = s + s;  
        return doubleS.substr(1, doubleS.size() - 2).find(s) != string::npos;
    }
};

int main() {
    Solution sol;
    cout << sol.repeatedSubstringPattern("abab") << endl;  // Expected output: 1 (true)
    cout << sol.repeatedSubstringPattern("aba") << endl;   // Expected output: 0 (false)
    cout << sol.repeatedSubstringPattern("abcabcabcabc") << endl;  // Expected output: 1 (true)
}