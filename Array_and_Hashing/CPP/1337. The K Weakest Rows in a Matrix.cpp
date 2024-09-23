#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> ans(mat[0].size() + 2);
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) count++;
            }
            ans[count].push_back(i);
        }
      
        vector<int> result;

        for (auto &x : ans) {
            for (auto &y : x) {
                result.push_back(y);
                k--;
                if (k == 0) return result;
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> countsAndIndices; // Store pairs of counts and row indices
        int n = mat.size();
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) count++;
            }
            countsAndIndices.push_back({count, i});
        }
      
        sort(countsAndIndices.begin(), countsAndIndices.end()); // Sort by count, breaking ties with row index

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(countsAndIndices[i].second); // Add the row index to the result
        }
        
        return result;
    }
};

// Driver function to test both Solution classes
int main() {
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k = 3;

    Solution1 sol1;
    Solution2 sol2;

    // Test Solution1
    cout << "Result from Solution1: ";
    vector<int> result1 = sol1.kWeakestRows(mat, k);
    for (int i : result1) {
        cout << i << " ";
    }
    cout << endl;

    // Test Solution2
    cout << "Result from Solution2: ";
    vector<int> result2 = sol2.kWeakestRows(mat, k);
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}