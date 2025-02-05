#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hash;
        // Store every character's last index in the hashmap
        for (auto i = 0; i < s.size(); i++) {
            hash[s[i]] = i;
        }
        int currentWindowIndex = 0;
        int start = 0;
        vector<int> ans;
        for (auto i = 0; i < s.size(); i++) {
            currentWindowIndex = max(hash[s[i]], currentWindowIndex);
            if (i == currentWindowIndex) {
                ans.push_back(currentWindowIndex - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

void runTestCases() {
    Solution solution;

    vector<string> testCases = {
        "ababcbacadefegdehijhklij", // Expected Output: {9, 7, 8}
        "eccbbbbdec",              // Expected Output: {10}
        "abcab",                   // Expected Output: {3, 2}
        "a",                       // Expected Output: {1}
        "aaaa",                    // Expected Output: {4}
        "abacdefghi",              // Expected Output: {2, 1, 1, 1, 1, 1, 1, 1}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        string s = testCases[i];
        cout << "Test Case " << i + 1 << ": Input: \"" << s << "\"" << endl;
        vector<int> result = solution.partitionLabels(s);
        cout << "Output: {";
        for (size_t j = 0; j < result.size(); ++j) {
            cout << result[j];
            if (j < result.size() - 1) cout << ", ";
        }
        cout << "}" << endl;
        cout << "--------------------------------" << endl;
    }
}

int main() {
    runTestCases();
    return 0;
}