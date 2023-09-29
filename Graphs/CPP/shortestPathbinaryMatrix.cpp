#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        // base case since we are not using recuusion only three base case is the 
        if(grid[0][0] == 1){return -1;} // if first element is one ie we cannot go futher
        if(grid[0].size()<1 && grid.size()<1 && grid[0][0] != -1){return 0;} // if grid size is less than one there is not space to move
        if(grid[0].size()<=1 && grid.size()<=1 && grid[0][0] == 0){return 1;}
        //create a visited list for nodes to be visted so reduce redudancy
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));// inirtialized all to false
        vis[0][0] = true; //arking 0,0 to be visited
        int lenght = 0; //lenght init to 0
        queue<pair<pair<int,int>,int>> q; // queues use to store coordinate to be vissted with curr lenght
        q.push({{0,0},lenght+1}); // initilised to start element
        while(!q.empty()){
            int lenght = q.front().second; // get lenght of front element
            pair<int,int> coordinates = q.front().first; // get frist pf pair
            int x = coordinates.first; // get curr x
            int y = coordinates.second; // get curr y
            q.pop(); // pop element
            vector<pair<int,int>> neibghour = {{0,-1},{0,1},{1,0},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}}; // 4 for normal up down left right , four for diagonal movemenmt
            for(pair<int,int> index: neibghour){ // check all neighbours
                int currx = x + index.first; // update x to neighbour x
                int curry = y + index.second; // update y to neighbour y
                if(currx>=0 && curry>=0 && currx<=grid.size()-1 && curry<=grid[0].size()-1 && grid[currx][curry] == 0 && !vis[currx][curry]){
                    // above condition is for to if curr x and y is out of bound of not also check if elment is 0 or 1 and is also visisted or not
                     vis[currx][curry] = true; // mark curr visited true
                    
                    q.push({{currx,curry},lenght+1}); // push to queue
                    
                    if(currx == grid.size()-1 && curry == grid[0].size()-1){ // if reached to end then return lenght+1
                    return lenght+1; 
                   }
                }
                
            }
        }
        return -1; //else return -1 
    }


};
int main(){
    vector<vector<int>> matrix = {{0}};
    Solution* Solve = new Solution();
    int result = Solve->shortestPathBinaryMatrix(matrix); //find shortest path;
    cout<<result;
    return 0;
}