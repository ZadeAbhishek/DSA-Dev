#include <vector>
using namespace std;

// ##matrix ##simulation
class Solution {
public:
    int minTimeToBeautifulCanvas(int n, int m, int k, vector<vector<int>>& paint) {
        // Initialize a grid to track painted cells
        vector<vector<bool>> painted(n, vector<bool>(m, false));

        // Directions to find the starting corner of possible k x k squares
        vector<pair<int, int>> directions = {{0, 0}, {1 - k, 0}, {0, 1 - k}, {1 - k, 1 - k}};

        // Process each paint operation
        for (int minute = 0; minute < paint.size(); ++minute) {
            int x = paint[minute][0] - 1; // Convert to 0-based index
            int y = paint[minute][1] - 1;

            // Mark the cell as painted
            painted[x][y] = true;

            // Check all potential k x k squares that could end at (x, y)
            for (auto [dx, dy] : directions) {
                int start_x = x + dx;
                int start_y = y + dy;

                // Ensure the k x k square is within bounds
                if (start_x < 0 || start_y < 0 || start_x + k > n || start_y + k > m) continue;

                // Check if all cells in the k x k square are painted
                bool is_fully_painted = true;
                for (int i = 0; i < k; ++i) {
                    for (int j = 0; j < k; ++j) {
                        if (!painted[start_x + i][start_y + j]) {
                            is_fully_painted = false;
                            break;
                        }
                    }
                    if (!is_fully_painted) break;
                }

                // If we found a fully painted k x k square, return the current minute + 1
                if (is_fully_painted) return minute + 1;
            }
        }

        // If no fully painted k x k square is found, return -1
        return -1;
    }
};