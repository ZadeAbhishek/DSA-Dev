#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // This can be solved using BFS
    unordered_set<string> hash(wordList.begin(), wordList.end()); // Convert wordList to a set for efficient lookup
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    hash.erase(beginWord); // Erase so we don't get back to the same word

    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        auto curr = c.first;
        auto step = c.second;

        if (curr == endWord) return step;

        for (size_t x = 0; x < curr.size(); x++) {
            auto original = curr;
            for (char y = 'a'; y <= 'z'; y++) {
                curr[x] = y;
                if (hash.find(curr) != hash.end()) {
                    q.push({curr, step + 1});
                    hash.erase(curr);
                }
            }
            curr = original;
        }
    }
    return 0;
}

int main() {
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";

    int result = ladderLength(beginWord, endWord, wordList);
    cout << "The ladder length is: " << result << endl;

    return 0;
}
