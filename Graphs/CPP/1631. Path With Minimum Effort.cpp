
// tle marenga
class Solution {
    void solve(vector<vector<int>>& heights,int x, int y , int currEffort, int &minEfforts,vector<vector<int>> &vis){
                
        // edges case
        

        // base case 
        if(x == heights.size()-1 && y == heights[x].size()-1){
               minEfforts = min(minEfforts,currEffort);
               return;
        }

        // recurrsive case
        vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

        for(auto &dir : directions){
            
            int currX = x+dir[0];
            int currY = y+dir[1];
            
            if(currX < 0 || currX >= heights.size() || currY < 0 || currY >= heights[currX].size()) continue;
            if(vis[currX][currY] == 1)continue;
            vis[currX][currY] = 1;
            solve(heights,currX,currY,max(currEffort,abs(heights[currX][currY] - heights[x][y])),minEfforts,vis);
            vis[currX][currY] = 0;
        }

        return;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int minEfforts = INT_MAX;
        vector<vector<int>> vis(heights.size(),vector<int>(heights[0].size(),0));
        vis[0][0] = 1;
        solve(heights,0,0,0,minEfforts,vis);
        return minEfforts;
    }
};


// dikestra algorithm

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Initialize a variable to store the minimum effort required
        int minEfforts = INT_MAX;

        // Create a priority queue to store pairs of (effort, coordinates)
        // The priority queue is min-heap, so it always returns the minimum effort first
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;

        // Create a 2D vector 'vis' to keep track of minimum effort for each cell
        vector<vector<int>> vis(heights.size(), vector<int>(heights[0].size(), INT_MAX));

        // Get the number of rows and columns in the 'heights' grid
        int col = heights.size() - 1;
        int row = heights[0].size() - 1;

        // Push the starting point (0,0) into the priority queue with an effort of 0
        que.push({0, {0, 0}});

        // Define the possible directions to move in (right, down, left, up)
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        // Start a loop until the priority queue is empty
        while (!que.empty()) {
            // Get the current pair with the minimum effort
            auto curr = que.top();
            que.pop();
            
            // Extract the coordinates (x, y) from the pair
            auto coor = curr.second;
            int x = coor.first;
            int y = coor.second;

            // If we have reached the destination (bottom-right corner), return the current effort
            if (x == col && y == row) return curr.first;

            // Iterate through the possible directions
            for (auto &d : dir) {
                int currX = x + d[0];
                int currY = y + d[1];

                // Check if the new coordinates are within bounds
                if (currX < 0 || currX > col || currY < 0 || currY > row) continue;

                // Calculate the effort required to move to the new cell
                int temp = abs(heights[currX][currY] - heights[x][y]);
                int currEfforts = max(curr.first, temp);

                // If the current effort is less than the minimum effort recorded for this cell,
                // update the minimum effort for this cell and add it to the priority queue
                if (currEfforts < vis[currX][currY]) {
                    vis[currX][currY] = currEfforts;
                    que.push({currEfforts, {currX, currY}});
                }
            }
        }

        // If the loop finishes and no path is found, return 0
        return 0;
    }
};
