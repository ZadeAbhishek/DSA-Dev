class Solution {
public:
    int paths = 0;
    int upo(vector<vector<int>>& og, int x , int y, vector<vector<int>> &memo){
        //check boundation
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