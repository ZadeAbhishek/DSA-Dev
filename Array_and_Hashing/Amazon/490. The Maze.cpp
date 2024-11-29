#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // We can use BFS
        int startX = start[0];
        int startY = start[1];
        int destX = destination[0];
        int destY = destination[1];

        int rows = maze.size();
        int cols = maze[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up

        queue<pair<int, int>> q;
        q.push({startX, startY});
        visited[startX][startY] = true;

        while (!q.empty()) {
            // Check if the current position is the destination
            auto p = q.front();
            q.pop();
            int currX = p.first;
            int currY = p.second;

            if (currX == destX && currY == destY) {
                return true;
            }

            for (auto& dir : directions) {
                int x = currX;
                int y = currY;

                // Roll in the current direction until hitting a wall
                while (x + dir[0] >= 0 && x + dir[0] < rows &&
                       y + dir[1] >= 0 && y + dir[1] < cols &&
                       maze[x + dir[0]][y + dir[1]] == 0) {
                    x += dir[0];
                    y += dir[1];
                }

                // Add the stopping position to the queue if not visited
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }

        return false;
    }
};

// Driver code
int main() {
    vector<vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };
    vector<int> start = {0, 4};
    vector<int> destination = {4, 4};

    Solution sol;
    if (sol.hasPath(maze, start, destination)) {
        cout << "There is a path from start to destination." << endl;
    } else {
        cout << "No path exists from start to destination." << endl;
    }

    return 0;
}
