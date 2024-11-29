class Solution {
public:
 // ##bfs ##zigzag
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n+1, false);
        queue<pair<int,int>> q;
        q.push({1,0}); // steps moves
        visited[1] = true;

        while(!q.empty()){
            auto [pos,moves] = q.front();
            q.pop();

            if(pos == n * n) return moves;
            
            // dice simulation
            for(int i = 1; i <= 6; i++){
               int nextPos = pos + i;
               if(nextPos > n * n) break;

               int r = (nextPos - 1) / n;
               int c = (nextPos - 1) % n;
               if(r % 2 == 1) c = n - 1 - c;
               r = n - 1 - r;

               if(board[r][c] != -1) nextPos = board[r][c];

               if(!visited[nextPos]){
                 visited[nextPos] = true;
                 q.push({nextPos,moves + 1});
               }
            }
        }
        return -1;
    }
};