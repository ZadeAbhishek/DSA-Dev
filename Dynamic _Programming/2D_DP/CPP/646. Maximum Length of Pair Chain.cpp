#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Custom comparison function to sort pairs based on the second element.
    static bool comparePairs(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    // Recursive function to find the longest chain.
    void findLongestChainRecursive(vector<vector<int>>& pairs, int& maxLength, int currentLength, vector<int> previousPair, int currentIndex) {
        // Base case: If we've processed all pairs, return.
        if (currentIndex >= pairs.size()) {
            return;
        }

        // Check if the current pair can be added to the chain.
        if (previousPair[1] < pairs[currentIndex][0]) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
            findLongestChainRecursive(pairs, maxLength, currentLength, pairs[currentIndex], currentIndex + 1);
        } else {
            // If not, continue without adding it to the chain.
            findLongestChainRecursive(pairs, maxLength, currentLength, previousPair, currentIndex + 1);
        }
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort the pairs based on the second element in ascending order.
        sort(pairs.begin(), pairs.end(), comparePairs);

        int maxLength = 1;
        int currentLength = 1;

        // Start with the first pair and search for the longest chain recursively.
        findLongestChainRecursive(pairs, maxLength, currentLength, pairs[0], 1);

        return maxLength;
    }
};

class Solution2 {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int cur = INT_MIN, ans = 0;

        // Iterate through the sorted pairs.
        for (const auto& pair : pairs) {
            // If the current pair can be added to the chain, update the current end and increment the chain length.
            if (cur < pair[0]) {
                cur = pair[1];
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};

    int longestChain = solution.findLongestChain(pairs);

    cout << "The longest chain length is: " << longestChain << endl;

    return 0;
}
