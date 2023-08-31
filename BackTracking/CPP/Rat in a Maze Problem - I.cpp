#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to traverse the matrix and find paths
    void traverse(vector<vector<int>>& m, int n, vector<string>& result, string& temp, int i, int j, vector<vector<bool>>& vis) {
        // Base case: Check if the current position is out of bounds or has a value of 0
        if (i < 0 || j < 0 || i > n - 1 || j > n - 1 || m[i][j] == 0) {
            return;
        }

        // Check if we've reached the bottom-right corner of the matrix
        if (i == n - 1 && j == n - 1) {
            string x = temp;
            result.push_back(x);
            return;
        }

        // If the current position is not visited, explore in all possible directions
        if (!vis[i][j]) {
            vis[i][j] = true;

            // Move Down
            temp.push_back('D');
            traverse(m, n, result, temp, i + 1, j, vis);
            temp.pop_back();

            // Move Right
            temp.push_back('R');
            traverse(m, n, result, temp, i, j + 1, vis);
            temp.pop_back();

            // Move Left
            temp.push_back('L');
            traverse(m, n, result, temp, i, j - 1, vis);
            temp.pop_back();

            // Move Up
            temp.push_back('U');
            traverse(m, n, result, temp, i - 1, j, vis);
            temp.pop_back();

            // Reset the visited status for backtracking
            vis[i][j] = false;
        }
        
        return;
    }

    // Function to find paths in the matrix
    vector<string> findPath(vector<vector<int>>& m, int n) {
        // Base cases: Check if the starting or ending position has a value of 0
        if (m[n - 1][n - 1] == 0 || m[0][0] == 0) {
            return {};
        }

        vector<string> result;
        string temp = "";

        // Create a visited matrix to track visited positions
        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));

        // Start traversal from the top-left corner
        traverse(m, n, result, temp, 0, 0, vis);

        // Sort the paths in lexicographical order
        sort(result.begin(), result.end());

        return result;
    }
};

int main() {
    // Example input: matrix and its size
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                   {1, 1, 0, 1},
                                   {0, 1, 0, 0},
                                   {1, 1, 1, 1}};
    int size = 4;

    // Create an instance of the Solution class
    Solution solution;

    // Call the findPath function to find paths in the matrix
    vector<string> paths = solution.findPath(matrix, size);

    // Display the paths
    if (paths.empty()) {
        cout << "No paths found." << endl;
    } else {
        cout << "Paths found:" << endl;
        for (const string& path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
