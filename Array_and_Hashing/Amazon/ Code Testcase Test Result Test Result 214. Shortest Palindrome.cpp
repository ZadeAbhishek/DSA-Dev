#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        cout<<s<<endl;
        const int n = s.size();
        int i = 0;
        for (int j=n-1; j>= 0; j--) {
            while (j>=0 && s[i] == s[j])
                i++, j--;
        }
        if (i==n) // palindrome early stop
            return s;
        string sub = s.substr(i), remain_rev = sub;
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + sub;
    }
};

// Function to run test cases
void runTests() {
    vector<string> testCases = {
        "aacecaaa",      // Already a palindrome       // Needs "abb" at the front
    };

    Solution sol;
    for (const string &s : testCases) {
        cout << "Input: " << s << endl;
        cout << "Shortest Palindrome: " << sol.shortestPalindrome(s) << endl;
        cout << "-----------------------------------------" << endl;
    }
}

int main() {
    runTests();
    return 0;
}