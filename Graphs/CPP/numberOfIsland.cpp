#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));//init vis vectors
        int count = 0;
        // this can be solve using bfs only
        // idea is to ierate all elemnt is not visited then increment the count
        // if we use bfs all neighbour which is one that is visited and zeros are not visied we are ignoting the zeros
        for(auto i = 0;i<grid.size();i++){
            for(auto j =0;j<grid[i].size();j++){
                //cout<<vis[i][j]<<endl;
                if((!vis[i][j]) && grid[i][j] == '1'){
                    vis[i][j] = true;
                    queue<pair<int,int>> q; // we are using queue pair to store the coordinate of curr 
                    pair<int,int> p = {i,j};
                    q.push(p);
                    while(!q.empty()){ //unline q in not empty explore the neigbour
                    pair<int,int> temp = q.front(); // get the front element from queue
                    q.pop(); // pop the front element from queue
                    int x = temp.first; // het x for curr element
                    int y = temp.second; // get y second of curr element
                    vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}}; // all four direction uo down left right
                    for(pair<int,int> it:directions){
                        int new_x = x + it.first; // update new x
                        int new_y = y + it.second; // update new y
                        //cout<<new_x<<" "<<new_y<<endl;
                        if( new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[x].size() && grid[new_x][new_y] == '1' && (!vis[new_x][new_y])){
                            vis[new_x][new_y] = true; // mark visited
                            pair<int,int> t = {new_x,new_y}; 
                            q.push(t); // push it to queue
                        }
                    }

                    }
                    count++;
                       
                }
            }
        }
        return count;
    }


    int numIslandsdfs(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));//init vis vectors
        int count = 0;
        // this can be solve using bfs only
        // idea is to ierate all elemnt is not visited then increment the count
        // if we use bfs all neighbour which is one that is visited and zeros are not visied we are ignoting the zeros
        for(auto i = 0;i<grid.size();i++){
            for(auto j =0;j<grid[i].size();j++){
                //cout<<vis[i][j]<<endl;
                if((!vis[i][j]) && grid[i][j] == '1'){
                    vis[i][j] = true;
                    stack<pair<int,int>> q; // we are using queue pair to store the coordinate of curr 
                    pair<int,int> p = {i,j};
                    q.push(p);
                    while(!q.empty()){ //unline q in not empty explore the neigbour
                    pair<int,int> temp = q.top(); // get the front element from queue
                    q.pop(); // pop the front element from queue
                    int x = temp.first; // het x for curr element
                    int y = temp.second; // get y second of curr element
                    vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}}; // all four direction uo down left right
                    for(pair<int,int> it:directions){
                        int new_x = x + it.first; // update new x
                        int new_y = y + it.second; // update new y
                        //cout<<new_x<<" "<<new_y<<endl;
                        if( new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[x].size() && grid[new_x][new_y] == '1' && (!vis[new_x][new_y])){
                            vis[new_x][new_y] = true; // mark visited
                            pair<int,int> t = {new_x,new_y}; 
                            q.push(t); // push it to queue
                        }
                    }

                    }
                    count++;
                       
                }
            }
        }
        return count;
    }
// private:
//      void bfs(vector)    
};

int main (){
   // create Martix 
   vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
   Solution* Solve = new Solution();
   int result = Solve->numIslands(grid);
   cout<<result<<endl;
   result = Solve->numIslandsdfs(grid);
   cout<<result<<endl;
   return 0;
}