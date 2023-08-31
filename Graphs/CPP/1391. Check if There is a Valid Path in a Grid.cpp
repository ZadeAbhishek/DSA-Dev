#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> grid;
    vector<vector<int>> vis;
    queue<pair<int,int>> que;

    bool left(int x, int y){
        int curr = grid[x][y];
        if(curr == 1 || curr == 3 || curr == 5) return true;
        return false;
    }
    bool right(int x, int y){
        int curr = grid[x][y];
        if(curr == 1 || curr == 4 || curr == 6) return true;
        return false;
    }
    bool top(int x, int y){
        int curr = grid[x][y];
        if(curr == 2 || curr == 6 || curr == 5) return true;
        return false;
    }
    bool bottom(int x, int y){
        int curr = grid[x][y];
        if(curr == 2 || curr == 3 || curr == 4) return true;
        return false;
    }

    bool isValid(int x, int y){
        if(x < 0 || y < 0 || x > grid.size() || y > grid[0].size()) return false;
        return true;
    }

    void pushLeft(int currX, int currY){
         if(isValid(currX,currY+1) && left(currX,currY+1) && vis[currX][currY+1] == 0){
                    vis[currX][currY+1] = 1;
                    que.push({currX,currY+1});
            }
            return;
    }
    void pushRight(int currX, int currY){
         if(isValid(currX,currY-1) && right(currX,currY-1) && vis[currX][currY-1] == 0){
                    vis[currX][currY-1] = 1;
                    que.push({currX,currY-1});
            }
            return;
    }
    void pushTop(int currX, int currY){
         if(isValid(currX+1,currY) && top(currX+1,currY) && vis[currX+1][currY] == 0){
                    vis[currX+1][currY] = 1;
                    que.push({currX+1,currY});
            }
            return;
    }
    void pushBottom(int currX, int currY){
         if(isValid(currX-1,currY) && bottom(currX-1,currY) && vis[currX-1][currY] == 0){
                    vis[currX-1][currY] = 1;
                    que.push({currX-1,currY});
        }
            return;
    }



    bool traverse(int x, int y){

        // base case
        
        que.push({x,y});
        vis[x][y] = 1;
        while(!que.empty()){
            auto currX = que.front().first;
            auto currY = que.front().second;
            que.pop();
            if(currX == grid.size()-1 && currY == grid[0].size()-1) return true;
            int currPipe = grid[currX][currY];
            switch(currPipe){
                case 1:
                pushLeft(currX,currY);
                pushRight(currX,currY);
                break;

                case 2:
                pushTop(currX,currY);
                pushBottom(currX,currY);
                break;

                case 3:
                pushTop(currX,currY);
                pushTop(currX,currY);
                break;

                case 4:
                pushTop(currX,currY);
                pushLeft(currX,currY);
                break;

                case 5:
                pushBottom(currX,currY);
                pushRight(currX,currY);
                break;

                case 6:
                pushBottom(currX,currY);
                pushLeft(currX,currY);
                break;

                default:
                break;
            
            }

        }

        return false;
       
        
    }           
public:
    bool hasValidPath(vector<vector<int>>& g) {
        grid = g;
        vis.resize(g.size(),vector<int>(g[0].size(),0));
        // pipes direction check
        return traverse(0,0);

    }
};


class Solution2 {
    vector<vector<int>> grid;
    queue<pair<int,int>> que;
    
    // check if the left side is present or not
    bool left(int x, int y){
        int curr = grid[x][y];
        if(curr == 1 || curr == 3 || curr == 5) return true;
        return false;
    }

    // check if the right side is present or not
    bool right(int x, int y){
        int curr = grid[x][y];
        if(curr == 1 || curr == 4 || curr == 6) return true;
        return false;
    }

    // check if the top side is present or not
    bool top(int x, int y){
        int curr = grid[x][y];
        if(curr == 2 || curr == 6 || curr == 5) return true;
        return false;
    }

    // check if the bottom side is present or not
    bool bottom(int x, int y){
        int curr = grid[x][y];
        if(curr == 2 || curr == 3 || curr == 4) return true;
        return false;
    }
    

    // check validity of coordinates
    bool isValid(int x, int y){
        if(x < 0 || y < 0 || x > grid.size()-1 || y > grid[0].size()-1) return false;
        return true;
    }
    
    // check if right side has left or not
    void pushLeft(int currX, int currY){
         if(isValid(currX,currY+1) && left(currX,currY+1) && grid[currX][currY+1] != 0){
                    que.push({currX,currY+1});
            }
            return;
    }

    // check if left side have right or not
    void pushRight(int currX, int currY){
         if(isValid(currX,currY-1) && right(currX,currY-1) && grid[currX][currY-1] != 0){
                    que.push({currX,currY-1});
            }
            return;
    }

    // check if bottom has top or not
    void pushTop(int currX, int currY){
         if(isValid(currX+1,currY) && top(currX+1,currY) && grid[currX+1][currY] != 0){
                    que.push({currX+1,currY});
            }
            return;
    }

    // check if top has bottom or not
    void pushBottom(int currX, int currY){
         if(isValid(currX-1,currY) && bottom(currX-1,currY) && grid[currX-1][currY] != 0){
                    que.push({currX-1,currY});
        }
            return;
    }



    bool traverse(int x, int y){
        
        // push starting coordinate in queue
        que.push({x,y}); 

        while(!que.empty()){
            
            // get current Coordinates
            auto currX = que.front().first;
            auto currY = que.front().second;
            que.pop();

            // base case if we reached end return true
            if(currX == grid.size()-1 && currY == grid[0].size()-1) return true;
            
            // get current pipe/number of pipe
            int currPipe = grid[currX][currY];

            // mark visited
            grid[currX][currY] = 0;
            
            /*
            Depend upon current pipe we will check its neighbour
            for example if currPipe is 1 we check right side of curr has
            left or not or left side of current has right or not
            */
            switch(currPipe){
                case 1:
                pushLeft(currX,currY); // check right has left or not
                pushRight(currX,currY); // check left has right or not
                break;

                case 2:
                pushTop(currX,currY);  // check bottom has top or not
                pushBottom(currX,currY); // check top has bottom or not
                break;

                case 3:
                pushTop(currX,currY);
                pushTop(currX,currY);
                break;

                case 4:
                pushTop(currX,currY);
                pushLeft(currX,currY);
                break;

                case 5:
                pushBottom(currX,currY);
                pushRight(currX,currY);
                break;

                case 6:
                pushBottom(currX,currY);
                pushLeft(currX,currY);
                break;

                default:
                break;
            
            }

        }

        return false;
    }

    public:
    bool hasValidPath(vector<vector<int>>& g) {
        grid = g;
        // pipes direction check
        return traverse(0,0);

    }
};    

int main(){
    vector<vector<int>> grid = {{2,4,3},{6,5,2}};
    Solution2 s;
    cout<<s.hasValidPath(grid)<<"\n";
}