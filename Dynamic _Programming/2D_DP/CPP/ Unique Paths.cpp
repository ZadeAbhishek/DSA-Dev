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

class Solution {
    
public:
    int uniquePaths(int m, int n) {
         vector<vector<int>> memo(m+2,vector<int>(n+2,0));
         memo[m][n] = 1;
         for(int x = m ; x > 0 ; x--){
             for(int y = n; y > 0 ; y--){
                memo[x][y] += memo[x+1][y] + memo[x][y+1];
             }
         }
         
         return memo[1][1];
    }
};


// explnation https://leetcode.com/problems/unique-paths/solutions/1581998/c-python-5-simple-solutions-w-explanation-optimization-from-brute-force-to-dp-to-math/

class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};