int solve(vector<vector<int>> &grid, int i, int j, int &maxi){
        //base 
        if(i >= grid.size() || j >= grid[0].size()) return 0;

        //main case
        // get value of daigona right and bottom
        int right = solve(grid,i,j+1,maxi);
        int diagonal = solve(grid,i+1,j+1,maxi);
        int bottom = solve(grid,i+1,j,maxi);
        cout<<right<<" "<<diagonal<<" "<<bottom<<"\n";
        if(grid[i][j] == 1){
           int currMin = 1 + min(right,min(diagonal,bottom));
           maxi = max(maxi,currMin);
           return currMin;
        }
        else return 0;
    }

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        // 1 1 1
        // 1 0 1
        // 1 1 1
        int maxi = INT_MIN;
        solve(grid,0,0,maxi);
        return maxi;
