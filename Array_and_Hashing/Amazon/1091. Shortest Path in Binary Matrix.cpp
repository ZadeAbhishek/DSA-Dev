// ###bfs
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid.back().back() == 1) return -1; // Start or end blocked
        
        queue<pair<int, pair<int, int>>> st; // Queue to store steps and coordinates
        st.push({1, {0, 0}}); // Start point with initial step count 1
        
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, 
                                          {1, 1}, {-1, -1}, {1, -1}, {-1, 1}}; // 8 directions
        
        while (!st.empty()) {
            auto top = st.front();
            st.pop();
            
            int x = top.second.first;
            int y = top.second.second;
            int steps = top.first;

            // If we reach the bottom-right corner, return the steps
            if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                return steps;
            }

            for (auto direction : directions) {
                int dx = x + direction[0];
                int dy = y + direction[1];

                // Check boundaries and if the cell is unvisited (0)
                if (dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size() && grid[dx][dy] == 0) {
                    st.push({steps + 1, {dx, dy}}); // Push the next step and position
                    grid[dx][dy] = 1; // Mark as visited
                }
            }
        }
        
        return -1; // If no path exists
    }
};