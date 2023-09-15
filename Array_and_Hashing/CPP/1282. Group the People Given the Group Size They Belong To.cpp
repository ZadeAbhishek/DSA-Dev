#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // Create an unordered map to store groups based on group size.
        // The key is the size of the group, and the value is a vector of group members.
        unordered_map<int, vector<int>> hash;

        int n = groupSizes.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // Check if the group size is already in the map.
            if (hash.count(groupSizes[i])) {
                // If the group is full, add it to the answer and create a new group.
                if (hash[groupSizes[i]].size() == groupSizes[i]) {
                    ans.push_back(hash[groupSizes[i]]);
                    hash[groupSizes[i]] = {i};
                } else {
                    // Add the current person to the existing group.
                    hash[groupSizes[i]].push_back(i);
                }
            } else {
                // If the group size is not in the map, create a new group with the current person.
                hash[groupSizes[i]] = {i};
            }
        }

        // Add the remaining groups to the answer.
        for (auto& x : hash) {
            ans.push_back(x.second);
        }

        return ans;
    }
};

// above one is optimised 

class Solution2 {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hash;
        int n = groupSizes.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int size = groupSizes[i];
            
            if (hash[size].size() == size) {
                ans.push_back(hash[size]); // Move the group to the answer.
                hash[size] = {}; // Clear the group for reuse.
            }
            
            hash[size].push_back(i);
        }

        for (auto &x : hash) {
                ans.push_back(x.second); // Move the remaining groups to the answer.
        }

        return ans;
    }
};

// Driver function to test the solution.
int main() {
    Solution solution;
    vector<int> groupSizes = {3, 3, 3, 3, 4, 4, 4, 6, 6, 6};
    vector<vector<int>> result = solution.groupThePeople(groupSizes);

    // Print the grouped people.
    for (const vector<int>& group : result) {
        for (int person : group) {
            cout << person << " ";
        }
        cout << endl;
    }

    return 0;
}
