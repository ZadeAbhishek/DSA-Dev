class Solution {
    bool checkSubString(string t, string s) {
        if (s.size() == 0) return true;
        int ptrS = 0;
        int ptrT = 0;
        int n = s.size();
        int m = t.size();
        while (ptrS < n && ptrT < m) {
            if (s[ptrS] == t[ptrT]) ptrS++, ptrT++;
            else ptrT++;
            if (ptrS >= n) return true;
        }
        return false;
    }
    
    int solve(vector<string> &words, string currWord, int CurrSize, int currLength, int &totalWords, unordered_map<string,int> &dp) {
        if (dp.count(currWord)) return dp[currWord];
        int MaxLength = 1; // Initialize MaxLength with 1
        for (int i = 0; i < totalWords; i++) {
            if ((words[i].size() == CurrSize + 1) && checkSubString(words[i], currWord)) {
                int result = solve(words, words[i], CurrSize + 1, currLength + 1, totalWords, dp);
                MaxLength = max(MaxLength, result + 1); // Update MaxLength with the result of the recursive call
            }
        }
        dp[currWord] = MaxLength;
        return MaxLength;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        int MaxLength = 0;
        int totalWords = words.size();
        for (auto &x : words) {
            MaxLength = max(MaxLength, solve(words, x, x.size(), 1, totalWords, dp));
        }
        return MaxLength;
    }
};


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        unordered_map<string, int> dp;
        int maxLength = 0;

        for (const string& word : words) {
            int currentLength = 1;
            for (int i = 0; i < word.length(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(predecessor)) {
                    currentLength = max(currentLength, dp[predecessor] + 1);
                }
            }
            dp[word] = currentLength;
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
