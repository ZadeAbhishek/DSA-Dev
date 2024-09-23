#include <iostream>
#include <vector>
using namespace std;


// just there is obstacles
class Solution {
public:
    int paths = 0;
    int upo(vector<vector<int>>& og, int x , int y, vector<vector<int>> &memo){

        if(x < 0 || x > og.size()-1 || y < 0 || y > og[0].size()-1 || og[x][y]) return 0;

            if(x == og.size()-1 && y == og[0].size()-1 &&  og[x][y]) return 0;
            
            if(x == og.size()-1 && y == og[0].size()-1 && !og[x][y]) return 1;
            
            if(memo[x][y]) return memo[x][y];

           return memo[x][y] = upo(og,x+1,y,memo) + upo(og,x,y+1,memo);
        

    }   
     

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // start coordinates 
        int x = 0;
        int y = 0;
        // memo at end
        vector<vector<int>> memo(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,0));
       // upo(obstacleGrid,x,y,memo);
        return upo(obstacleGrid,x,y,memo);; 
    }
};

int main() {
    Solution solution;

    // Test Case 1: No obstacles
    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Test Case 1: " << solution.uniquePathsWithObstacles(grid1) << endl; 
    // Expected output: 6

    // Test Case 2: One obstacle in the middle
    vector<vector<int>> grid2 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Test Case 2: " << solution.uniquePathsWithObstacles(grid2) << endl; 
    // Expected output: 2

    // Test Case 3: Obstacle at the starting point
    vector<vector<int>> grid3 = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Test Case 3: " << solution.uniquePathsWithObstacles(grid3) << endl; 
    // Expected output: 0

    // Test Case 4: Obstacle at the destination
    vector<vector<int>> grid4 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    cout << "Test Case 4: " << solution.uniquePathsWithObstacles(grid4) << endl; 
    // Expected output: 0

    // Test Case 5: A larger grid with some obstacles
    vector<vector<int>> grid5 = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}
    };
    cout << "Test Case 5: " << solution.uniquePathsWithObstacles(grid5) << endl; 
    // Expected output: 3

    return 0;
}
