class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Basic BFS solution we can apply here
        int islands = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                   islands++;
                   // make land water;
                   stack<pair<int,int>> st;
                   st.push({i,j});
                   vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
                   while(!st.empty()){
                       pair coordinate = st.top();
                       st.pop();
                       grid[coordinate.first][coordinate.second] = '0';
                       for(auto dir : directions){
                        int currI = coordinate.first + dir[0];
                        int currY = coordinate.second + dir[1];
                        if(!(currI < 0 || currI >= grid.size() || currY < 0 || currY >= grid[coordinate.first].size())){
                        if(grid[currI][currY] == '1') st.push({currI,currY});
                        }
                       }
                   }
                }
            }
        }
        return islands;
    }
};