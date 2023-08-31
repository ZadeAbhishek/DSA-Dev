#include<bits/stdc++.h>
using namespace std;

void operator<<(ostream &out, vector<vector<char>> b){
    for(auto &x : b){
        for(auto &y : x) cout<<y<<" ";
        cout<<"\n";
    }
}

class Solution {
public:

   bool dfs(vector<vector<char>>& board,int i ,int j, int &col, int &row, char mark){
      
        bool valid = true;

       // check out of bound
       if(i < 0 || j < 0 || i > col-1 || j > row-1) return false;


       else if(board[i][j] == 'X' or board[i][j] == mark) return true;

       else{

       // iterate
       vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
       
       board[i][j] = mark;

       for(auto &x : dir){
           int currX = i + x[0];
           int currY = j + x[1];
           valid = dfs(board,currX,currY,col,row,mark) && valid;

       }

       }
       
    //    if(!valid) board[i][j] = 'O';

       return valid;
   }


    void solve(vector<vector<char>>& board) {
        // dfs should work here
        int col = board.size();
        int row = board[0].size();
        for(int i = 0 ; i < col ; i++){
            for(int j = 0 ; j < row ; j++){
                // check for 'O'
                if(board[i][j] == 'O'){
                    // dfs
                    if(dfs(board,i,j,col,row,'1')){
                    dfs(board,i,j,col,row,'X');
                    }
                }
            }
        }

        for(auto &y : board){
           for(auto &x : y) x = (x == '1')?'O':x;
        } 
        return;
    }
};


/*
[["O","O","O"],["O","O","O"],["O","O","O"]]

*/

int main(){
    vector<vector<char>> grid = {{'X','X','X','X','X'},{'X','O','O','X','X'},{'X','X','O','X','X'},{'X','X','X','X','X'},{'X','O','X','X','X'}};
    Solution s;
    cout<<grid;
    s.solve(grid);
    cout<<grid;
}