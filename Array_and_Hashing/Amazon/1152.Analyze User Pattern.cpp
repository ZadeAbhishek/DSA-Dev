#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

// ##LongInterview Question
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        
        // There is need to understand this code because this what interviews will expect from u

        // hashmap where key is username and value is array of pair (timeStamp and Website)
    
        unordered_map<string, vector<pair<int, string>>> userVisits;
        for (int i = 0; i < username.size(); ++i) {
            userVisits[username[i]].push_back({timestamp[i], website[i]});
        }
        
        // One all pairs are added in Hashmap we are sorting the values according to timestamp
        for (auto& user : userVisits) {
            sort(user.second.begin(), user.second.end());
        }
        
        // we are again creating HashTable with key as Vector<string> (websites) and value as count int
        map<vector<string>, int> patternCount;

        for (auto& user : userVisits) {
            set<vector<string>> patterns;
            vector<string> visits;

            // Get all website for each user we dont need to worry about sorting as we have done it early
            for (auto& visit : user.second) {
                visits.push_back(visit.second);
            }
            
            // Get all pattern in sequencial ways
            for (int i = 0; i < visits.size() - 2; ++i) {
                for (int j = i + 1; j < visits.size() - 1; ++j) {
                    for (int k = j + 1; k < visits.size(); ++k) {
                        patterns.insert({visits[i], visits[j], visits[k]});
                    }
                }
            }
            
            // check the frequency of pattern
            for (const auto& pattern : patterns) {
                patternCount[pattern]++;
            }
        }
        

        vector<string> result;
        int maxCount = 0;

        // Here are checking max count also we are checking if the a string have same count 
        // Get lexographically order 
        for (const auto& entry : patternCount) {
            if (entry.second > maxCount || (entry.second == maxCount && entry.first < result)) {
                maxCount = entry.second;
                result = entry.first;
            }
        }

        return result;
    }
};

bool testSolution(vector<string> username, vector<int> timestamp, vector<string> website, vector<string> expected) {
    Solution solution;
    vector<string> result = solution.mostVisitedPattern(username, timestamp, website);
    if (result == expected) {
        cout << "Test passed." << endl;
        return true;
    } else {
        cout << "Test failed." << endl;
        cout << "Expected: ";
        for (const auto& s : expected) cout << s << " ";
        cout << "\nGot: ";
        for (const auto& s : result) cout << s << " ";
        cout << endl;
        return false;
    }
}

int main() {
    // Test Case 1: Example given in the problem
    vector<string> username1 = {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"};
    vector<int> timestamp1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<string> website1 = {"home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"};
    vector<string> expected1 = {"home", "about", "career"};
    testSolution(username1, timestamp1, website1, expected1);

    // Test Case 2: Another user visits a different sequence
    vector<string> username2 = {"alice", "alice", "alice", "bob", "bob", "bob", "bob", "bob"};
    vector<int> timestamp2 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<string> website2 = {"home", "about", "career", "home", "cart", "maps", "about", "career"};
    vector<string> expected2 = {"about", "career", "home"};
    testSolution(username2, timestamp2, website2, expected2);

    // Test Case 3: Multiple sequences with the same count
    vector<string> username3 = {"charlie", "charlie", "charlie", "dave", "dave", "dave", "dave"};
    vector<int> timestamp3 = {1, 2, 3, 4, 5, 6, 7};
    vector<string> website3 = {"a", "b", "c", "a", "b", "d", "c"};
    vector<string> expected3 = {"a", "b", "c"};
    testSolution(username3, timestamp3, website3, expected3);

    // Test Case 4: Lexicographical ordering needed
    vector<string> username4 = {"eve", "eve", "eve", "frank", "frank", "frank"};
    vector<int> timestamp4 = {1, 2, 3, 4, 5, 6};
    vector<string> website4 = {"x", "y", "z", "y", "z", "x"};
    vector<string> expected4 = {"x", "y", "z"};
    testSolution(username4, timestamp4, website4, expected4);

    // Test Case 5: Edge case with only one user
    vector<string> username5 = {"grace", "grace", "grace"};
    vector<int> timestamp5 = {1, 2, 3};
    vector<string> website5 = {"alpha", "beta", "gamma"};
    vector<string> expected5 = {"alpha", "beta", "gamma"};
    testSolution(username5, timestamp5, website5, expected5);

    return 0;
}