class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int col = maze.size();
        int row = maze[0].size();
        queue<pair<pair<int, int>, int>> bfsQueue;
        bfsQueue.push({{entrance[0], entrance[1]}, 0});
        vector<vector<int>> visitedMaze(col, vector<int>(row, 0));
        visitedMaze[entrance[0]][entrance[1]] = 1;

        int minSteps = INT_MAX;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right

        while (!bfsQueue.empty()) {
            auto currNode = bfsQueue.front();
            bfsQueue.pop();
            int x = currNode.first.first;
            int y = currNode.first.second;
            int steps = currNode.second;

            // Check if current position is an exit (and not the entrance)
            if ((x != entrance[0] || y != entrance[1]) && 
                (x == 0 || y == 0 || x == col - 1 || y == row - 1)) {
                minSteps = min(minSteps, steps);
                continue; // We found an exit, but let's continue to check other paths
            }

            for (auto& direction : directions) {
                int nextX = x + direction[0];
                int nextY = y + direction[1];

                if (nextX < 0 || nextX >= col || nextY < 0 || nextY >= row || maze[nextX][nextY] == '+') {
                    continue;
                }

                if (!visitedMaze[nextX][nextY]) {
                    visitedMaze[nextX][nextY] = 1;
                    bfsQueue.push({{nextX, nextY}, steps + 1});
                }
            }
        }

        return minSteps == INT_MAX ? -1 : minSteps; // Return -1 if no exit is found
    }
};