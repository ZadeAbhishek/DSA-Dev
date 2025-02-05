class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int m = grid.size();
        int n = grid[0].size();
        int steps = 0;
        vector<vector<int>> life(m, vector<int>(n, INT_MIN));
        queue<pair<int, int>> q;
        q.push({0,0});
        life[0][0]=k;
        while(!q.empty()){
            int l=q.size();
            while(l--){
                auto curr= q.front();
                q.pop();
                // if reached at destination, return steps
                if(curr.first== m-1 && curr.second==n-1) return steps;
                for(int i=0;i<4;i++){
                    int next_x= curr.first + directions[i][0];
                    int next_y= curr.second + directions[i][1];

                    if(next_x >=0 && next_x<m && next_y>=0 && next_y<n){
                        int remaininglives= life[curr.first][curr.second] - grid[next_x][next_y];
                        if(remaininglives>=0 && life[next_x][next_y]< remaininglives){
                            q.push({next_x,next_y });
                            life[next_x][next_y]= remaininglives;
                        }
                    }

                }

            }
            steps++;

        }
        return -1;

    }
};