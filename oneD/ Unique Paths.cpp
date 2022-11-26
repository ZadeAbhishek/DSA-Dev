class Solution {
    
public:
    int uniquePaths(int m, int n, int x, int y, vector<vector<int>>& memo) {
        // x and y represent the coordianted 
        
        if(!(x < 0 || x > m - 1 || y < 0 || y > n - 1)){
             
            
            if(x == m - 1 && y == n - 1) return 1;
            
            if(memo[x][y]) return memo[x][y];
            
            return  memo[x][y] = uniquePaths(m,n,x+1,y,memo) + uniquePaths(m,n,x,y+1,memo);
        }
       return 0;
    }
    
    int uniquePaths(int m, int n) {
         vector<vector<int>> memo(m,vector<int>(n,0));
         return uniquePaths(m,n,0,0,memo);
    }
};