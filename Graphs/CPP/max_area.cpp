#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_prev = 0; // to keep track of max area 
        for(int i = 0 ; i <grid.size();i++){ // outer loop 
            for(int j = 0 ; j<grid[0].size(); j++){ // inner loop
                     if(grid[i][j] == 1){ // check if there is island or not
                    max_prev = max(max_prev,dfs(grid,i,j)); // get max and call dfs 
                }
            }
        }   
        return max_prev; //return max
    }
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size()-1 || grid[i][j] == 0){ // check if out of bound or area is 0
            return 0;
        }
          grid[i][j] = 0; // if 1 make it 0 so this could not be visisted again 
          return 1 + dfs(grid,i+1,j) + dfs(grid,i,j+1) + dfs(grid,i-1,j) + dfs(grid,i,j-1);// return sum
    }
};

int main(){
    vector<vector<int>> matrix = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution* Solve = new Solution();
    int result = Solve->maxAreaOfIsland(matrix); //find shortest path;
    cout<<result;
    return 0;
}