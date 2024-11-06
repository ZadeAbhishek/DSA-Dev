#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
// ##Priority Queue ##BFS
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Priority queue (max-heap) to keep track of the maximum minimum path
        priority_queue<pair<int, pair<int, int>>> pq; // {minimum value, {row, col}}
        
        // Directions array for moving up, down, left, right
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Visited array to avoid revisiting cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Start from the top-left corner
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        int min_path_value = grid[0][0];
        
        // BFS using max-heap to ensure we always expand the maximum minimum path
        while (!pq.empty()) {
            auto [current_min, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            // Update the minimum value in the path
            min_path_value = min(min_path_value, current_min);
            
            // If we've reached the bottom-right cell, return the result
            if (r == rows - 1 && c == cols - 1) return min_path_value;
            
            // Visit all neighbors
            for (auto& d : directions) {
                int new_r = r + d[0];
                int new_c = c + d[1];
                
                // Check bounds and if the cell is already visited
                if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && !visited[new_r][new_c]) {
                    visited[new_r][new_c] = true;
                    pq.push({grid[new_r][new_c], {new_r, new_c}});
                }
            }
        }
        
        return -1; // If there's no valid path (shouldn't happen in a valid grid)
    }
};

// Driver code
int main() {
    Solution solution;

    // Test case: grid with some values
    vector<vector<int>> grid = {
        {5, 2, 5},
        {1, 2, 6},
        {7, 4, 6}
    };

    int result = solution.maximumMinimumPath(grid);
    cout << "The maximum minimum path value is: " << result << endl;

    return 0;
}