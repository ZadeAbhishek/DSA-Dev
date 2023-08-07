#include<bits/stdc++.h>
using namespace std;

void operator<<(ostream &out, vector<vector<int>> grid){
    for(auto &x : grid){ 
         for(auto &y : x) cout<<y<<" ";
    cout<<"\n";

    }
    return;
}

class Solution {
    int col;
    int row;
public:
    
     int getPath(vector<vector<int>> &grid, int i , int j){
        // base case

        if(i < 0 || j < 0 || i > col-1 || j > col-1) return 0;

        if(i == col-1 && j == row-1) return 1;

        if(grid[i][j] == 1 || grid[i][j] == 2) return 0;

        grid[i][j] = 2;
       
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        int ans = 0;

        for(auto &x : dir){
            

            int currX = i + x[0];
            int currY = j + x[1];
            ans = ans + getPath(grid,currX,currY);
    
        }

        grid[i][j] = 0;

        return ans;
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // use dfs to mark path 
        // 0 = path 1 = thiefs 2 = marked path
        col = grid.size();
        row = grid[0].size();
        cout<<getPath(grid,0,0)<<"\n";
        grid[0][0] = 2;
        cout<<grid;
        cout<<"Path<<:]n";
        return 0;
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,1},{0,0,0},{0,0,0}};
    Solution s;
    cout<<s.maximumSafenessFactor(grid)<<"\n";
    return 0;
}