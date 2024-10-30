// write this code 3 time in notebook till u learn it
// next day work

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> qu;
        int freshOranges = 0;

        // Collect all rotten oranges and count the fresh ones
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (grid[x][y] == 2) {
                    qu.push({x, y}); // Add rotten oranges to queue
                } else if (grid[x][y] == 1) {
                    freshOranges++;  // Count fresh oranges
                }
            }
        }

        if (freshOranges == 0) return 0; // No fresh oranges to rot, return 0

        int time = 0;
        while (!qu.empty()) {
            int size = qu.size();
            bool rotted = false;
            
            for (int i = 0; i < size; i++) {
                auto [currX, currY] = qu.front();
                qu.pop();

                // Spread to adjacent cells
                for (auto dire : dir) {
                    int nextX = currX + dire[0];
                    int nextY = currY + dire[1];
                    if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols && grid[nextX][nextY] == 1) {
                        grid[nextX][nextY] = 2;  // Mark as rotten
                        qu.push({nextX, nextY});
                        freshOranges--;  // Decrease the count of fresh oranges
                        rotted = true;
                    }
                }
            }
            if (rotted) time++; // Increase time only if new oranges rotted in this round
        }

        // If there are still fresh oranges, return -1
        return freshOranges == 0 ? time : -1;
    }
};