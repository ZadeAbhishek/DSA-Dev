#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        vector<vector<int>> tab(s.size(), vector<int>(s.size(), 0));
        string res;
        int start = 0;
        int max = INT_MIN;

        for (auto diff = 0; diff < s.size(); diff++) {
            for (auto i = 0, j = diff; j < s.size(); i++, j++) {
                if (diff <= 1) {
                    if (diff == 0) tab[i][j] = 1;
                    if (diff == 1) tab[i][j] = (s[i] == s[j]) ? 2 : 0;
                } else {
                    if (s[i] == s[j] && tab[i + 1][j - 1]) tab[i][j] = tab[i + 1][j - 1] + 1;
                    else if (s[i] == s[j] && !tab[i + 1][j - 1]) tab[i][j] = tab[i + 1][j - 1];
                    else tab[i][j] = 0;
                }

                if (tab[i][j]) {
                    if ((j - i + 1) > max) {
                        start = i;
                        max = (j - i + 1);
                    }
                }
            }
        }

        if (max != INT_MIN) res = s.substr(start, max);

        return res;
    }
};

// Pointer approach to find the longest palindrome in a string
class solutionPointer {
    int start = 0;
    int end = 0;
    int len = 0;
    int n = 0;

    // Helper function to check for palindromes centered at st and en
    void checkPalindrome(string& s, int st, int en) {
        while (st >= 0 && en < n && s[st] == s[en]) {
            if (en - st + 1 > len) {
                len = en - st + 1;
                start = st;
                end = en;
            }
            st--;
            en++;
        }
    }

public:
    string longestPalindrome(string s) {
        n = s.size();

        for (int i = 1; i < n; i++) {
            // Check for odd length palindromes
            checkPalindrome(s, i - 1, i + 1);

            // Check for even length palindromes
            checkPalindrome(s, i - 1, i);
        }

        // Return the longest palindrome substring
        return s.substr(start, (end - start + 1));
    }
};


// Brute force approach
class SolutionBruteForce {
private:
    bool check(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) {
                    if (j - i + 1 > max_len) {
                        max_len = j - i + 1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
};

int main() {
    Solution solution;
    solutionPointer solutionPointer;
    SolutionBruteForce solutionBruteForce;

    string input = "babad";

    cout << "Longest Palindrome (Dynamic Programming): " << solution.longestPalindrome(input) << endl;
    cout << "Longest Palindrome (Pointer Approach): " << solutionPointer.longestPalindrome(input) << endl;
    cout << "Longest Palindrome (Brute Force Approach): " << solutionBruteForce.longestPalindrome(input) << endl;

    return 0;
}
