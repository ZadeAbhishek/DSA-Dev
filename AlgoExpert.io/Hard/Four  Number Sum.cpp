#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
    unordered_map<int, vector<pair<int, int>>> hash;
    set<vector<int>> result;
    vector<vector<int>> finalResult;

    // Store pairs and their sums in hash
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            int sum = array[i] + array[j];
            hash[sum].emplace_back(array[i], array[j]);
        }
    }

    // Check the combinations
    for (auto &x : hash) {
        int curr = targetSum - x.first;

        // Skip if the sum equals its complementary part to avoid using the same pair
        if (curr == x.first) continue;

        if (hash.count(curr)) {
            for (auto &p1 : x.second) {
                for (auto &p2 : hash[curr]) {
                    // Ensure all elements are distinct
                    if (p1.first != p2.first && p1.first != p2.second &&
                        p1.second != p2.first && p1.second != p2.second) {
                        vector<int> temp = {p1.first, p1.second, p2.first, p2.second};
                        sort(temp.begin(), temp.end());
                        result.insert(temp);
                    }
                }
            }
        }
    }

    for (auto &x : result) {
        finalResult.push_back(x);
    }

    return finalResult;
}