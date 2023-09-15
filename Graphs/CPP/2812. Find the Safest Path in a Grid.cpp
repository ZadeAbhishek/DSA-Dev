#include <bits/stdc++.h>
using namespace std;

void operator<<(ostream &out, vector<vector<int>> grid) {
    for (auto &x : grid) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
    return;
}

class Solution {
public:
    int getPath(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return 1;
        if (grid[i][j] == 1 || grid[i][j] == 2) return 0;

        grid[i][j] = 2;

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ans = 0;

        for (auto &x : dir) {
            int currX = i + x[0];
            int currY = j + x[1];
            ans += getPath(grid, currX, currY);
        }

        grid[i][j] = 0;

        return ans;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int safenessFactor = getPath(grid, 0, 0);
        grid[0][0] = 2;
        return safenessFactor;
    }
};

int main() {
    vector<vector<int>> grid = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    Solution s;
    int maxSafenessFactor = s.maximumSafenessFactor(grid);
    cout << "Maximum Safeness Factor: " << maxSafenessFactor << "\n";
    return 0;
}
