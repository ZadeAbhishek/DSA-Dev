#include <iostream>
#include <vector>
#include <string>
#include <queue>

class Solution {
public:
    int minDeletions(std::string s) {
        // Create a hashmap for character frequencies
        std::vector<int> hash(128, 0);

        // Store character count
        for (auto &c : s) hash[c]++;

        // Max-heap
        std::priority_queue<int> MaxHeap;

        // Push all elements into the heap
        for (auto &x : hash)
            if (x != 0) MaxHeap.push(x);

        int deletions = 0;
        int prev = MaxHeap.top();
        MaxHeap.pop();
        while (!MaxHeap.empty()) {
            int curr = MaxHeap.top();
            MaxHeap.pop();
            if (curr == prev && (curr != 0 && prev != 0)) {
                deletions++;
                prev--;
                MaxHeap.push(prev);
            }

            prev = curr;
        }

        return deletions;
    }
};

int main() {
    Solution solution;
    std::string input = "aabbbcc";
    int result = solution.minDeletions(input);
    std::cout << "Minimum deletions required: " << result << std::endl;
    return 0;
}