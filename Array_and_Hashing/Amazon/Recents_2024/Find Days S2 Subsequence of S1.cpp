#include <string>
#include <vector>
using namespace std;

// Helper function to check if s2 is a subsequence of s1
bool isSubsequence(const string& s1, const string& s2) {
    int s2_index = 0;
    for (char ch : s1) {
        if (s2_index < s2.length() && ch == s2[s2_index]) {
            s2_index++;
        }
        if (s2_index == s2.length()) {
            return true;
        }
    }
    return s2_index == s2.length();
}

// Main function to find the number of days s2 is a subsequence of s1
int findDaysS2SubsequenceOfS1(string s1, const string& s2, const vector<int>& start, const vector<int>& end) {
    int days_count = 0;
    
    for (int i = 0; i < start.size(); ++i) {
        // Delete the substring in s1 from start[i] to end[i]
        for (int j = start[i]; j <= end[i]; ++j) {
            s1[j] = '*'; // Mark deleted characters with a special character
        }

        // Construct the modified string by ignoring deleted characters
        string modified_s1;
        for (char ch : s1) {
            if (ch != '*') {
                modified_s1 += ch;
            }
        }

        // Check if s2 is a subsequence of modified_s1
        if (isSubsequence(modified_s1, s2)) {
            days_count++;
        }
    }
    
    return days_count;
}


#include <iostream>
#include <unordered_map>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool delete_range(int start, int end, string& s1, const string& s2, vector<bool>& s1_exists, unordered_map<char, deque<int>>& indices) {
    for (int i = start; i <= end; ++i) {
        if (s1_exists[i]) {
            cout << "Removing " << s1[i] << endl;

            if (s2.find(s1[i]) == string::npos) { // Character not in s2
                cout << "Marking the character deleted which is not in the subsequence" << endl;
                s1_exists[i] = false;
                continue;
            }

            indices[s1[i]].erase(remove(indices[s1[i]].begin(), indices[s1[i]].end(), i), indices[s1[i]].end());
            if (indices[s1[i]].empty()) {
                cout << "No more character present to form subsequence" << endl;
                return false;
            }

            int subsequence_i = s2.find(s1[i]);

            // Check next character in s2
            if (subsequence_i >= 0 && subsequence_i < s2.length() - 1) {
                while (!indices[s2[subsequence_i + 1]].empty() && indices[s2[subsequence_i + 1]].front() < indices[s2[subsequence_i]].front()) {
                    int delete_index = indices[s2[subsequence_i + 1]].front();
                    indices[s2[subsequence_i + 1]].pop_front();
                    cout << delete_index << " can't produce a subsequence, removing it" << endl;
                    s1_exists[delete_index] = false;
                }
                if (indices[s2[subsequence_i + 1]].empty()) {
                    cout << "Next element not there" << endl;
                    return false;
                }
            }

            // Check previous character in s2
            if (subsequence_i > 0) {
                while (!indices[s2[subsequence_i - 1]].empty() && indices[s2[subsequence_i - 1]].front() > indices[s2[subsequence_i]].front()) {
                    int delete_index = indices[s2[subsequence_i - 1]].front();
                    indices[s2[subsequence_i - 1]].pop_front();
                    cout << delete_index << " can't produce a subsequence, removing it" << endl;
                    s1_exists[delete_index] = false;
                }
                if (indices[s2[subsequence_i - 1]].empty()) {
                    cout << "Previous element not there" << endl;
                    return false;
                }
            }

            s1_exists[i] = false;
        } else {
            cout << "Already removed " << s1[i] << endl;
        }
    }

    return true;
}

int findDaysS2SubsequenceOfS1(const string& s1, const string& s2, const vector<int>& start, const vector<int>& end) {
    int n = s1.size();
    vector<bool> s1_exists(n, true); // Track existence of characters in s1

    // Create the map for the subsequence characters in s1
    unordered_map<char, deque<int>> indices;
    for (int i = 0; i < n; ++i) {
        if (s2.find(s1[i]) != string::npos) {
            indices[s1[i]].push_back(i);
        }
    }

    int ans = 0;

    for (int i = 0; i < start.size(); ++i) {
        cout << "Deleting range " << start[i] << " to " << end[i] << endl;
        if (delete_range(start[i], end[i], s1, s2, s1_exists, indices)) {
            cout << "Possible to form subsequence" << endl;
            ans++;
        } else {
            cout << "Can't form subsequence" << endl;
            return ans;
        }
    }

    return ans;
}

// Main function for testing
int main() {
    string s1 = "abcdefghabc";
    string s2 = "abc";
    vector<int> start = {0, 0, 1, 2, 9};
    vector<int> end = {1, 2, 3, 3, 10};

    int result = findDaysS2SubsequenceOfS1(s1, s2, start, end);
    cout << "Number of days s2 is a subsequence of s1: " << result << endl;

    return 0;
}