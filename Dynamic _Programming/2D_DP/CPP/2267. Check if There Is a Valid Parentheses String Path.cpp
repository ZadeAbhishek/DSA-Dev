#include<bits/stdc++.h>
using namespace std;


// backtracking
class Solution {

   bool traverse(vector<vector<char>>& grid, int i , int j , int balance, int &col, int &row){
       // base case 
       if(balance < 0) return false;

       if(i < 0 || j < 0 || i > col-1 || j > row -1) return false;

       if(grid[i][j] == '(') balance++;
       else if(grid[i][j] == ')') balance--; 
       
       if(i == col - 1 && j == row -1) return (balance == 0);

       bool right = traverse(grid,i,j+1,balance,col,row);

       bool left = traverse(grid,i+1,j,balance,col,row);

       return right || left;
   }


public:
    bool hasValidPath(vector<vector<char>>& grid) {

        // base case 
        if(grid[0][0] == ')') return false;
        int col = grid.size();
        int row = grid[0].size();
        return traverse(grid,0,0,0,col,row);
    }
};


// dfs + dynamic + backtracking
class Solution {

   bool traverse(vector<vector<char>>& grid, int i , int j , int balance, int &col, int &row, vector<vector<vector<int>>> &dp){
       // base case 
       if(i >= col || j >= row) return false;

       if(grid[i][j] == '(') balance++;
       else if(grid[i][j] == ')') balance--; 

       if(balance < 0) return false;
       
       if(i == col - 1 && j == row -1) return (balance == 0);

       if(dp[i][j][balance] != -1) return dp[i][j][balance];

       bool right = traverse(grid,i,j+1,balance,col,row,dp);

       bool left = traverse(grid,i+1,j,balance,col,row,dp);

       return dp[i][j][balance] = right | left;
   }


public:
    bool hasValidPath(vector<vector<char>>& grid) {

        // base case 
        if(grid[0][0] == ')') return false;
        int col = grid.size();
        int row = grid[0].size();
        vector<vector<vector<int> > > dp(100, vector<vector<int> >(100, vector<int>(205, -1)));
        return traverse(grid,0,0,0,col,row,dp);
    }
};

// dfs + dp + backtracking
class Solution {
    public:
int visited[100][100][101] = {};
bool hasValidPath(vector<vector<char>>& grid, int i = 0, int j = 0, int bal = 0) {
    int m = grid.size(), n = grid[0].size();
    bal += grid[i][j] == '(' ? 1 : -1;
    if (bal < 0 || bal > (m + n) / 2 || visited[i][j][bal])
        return false;
    visited[i][j][bal] = true;
    if (i == m - 1 && j == n - 1 && bal == 0)
        return true;
    if (i < m - 1 && hasValidPath(grid, i + 1, j, bal))
        return true;
    if (j < n - 1 && hasValidPath(grid, i, j + 1, bal))
        return true;
    return false;
}
};

int main(){}