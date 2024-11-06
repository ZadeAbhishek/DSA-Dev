//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// ##DFS ##RelativePositions
class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, string& path, char dir) {
        // Mark the cell as visited
        grid[i][j] = 0;
        
        // Record the direction of movement to the path
        path += dir;

        // Define directions: right, down, left, up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<char> directionChars = {'R', 'D', 'L', 'U'};
        
        for (int d = 0; d < 4; d++) {
            int nextI = i + directions[d].first;
            int nextJ = j + directions[d].second;
            
            if (nextI >= 0 && nextJ >= 0 && nextI < grid.size() && nextJ < grid[0].size() && grid[nextI][nextJ] == 1) {
                dfs(grid, nextI, nextJ, path, directionChars[d]);
            }
        }
        
        // Backtrack to mark the end of this path segment
        path += 'B'; // B for Backtracking
    }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<string> uniqueShapes;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) { // Found a new island
                    string path;
                    dfs(grid, i, j, path, 'S'); // 'S' denotes the start of a new island
                    uniqueShapes.insert(path);
                }
            }
        }
        
        // The number of unique shapes is the count of distinct islands
        return uniqueShapes.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends