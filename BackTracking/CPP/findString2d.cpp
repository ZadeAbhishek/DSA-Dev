#include<bits/stdc++.h>
using namespace std;


bool find_String(vector<vector<char>> &board, int i, int j , int currlength, string s, int curr,vector<vector<bool>> &memo){
    // basecase 1
    if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false;
    // memoization
    if(memo[i][j]) return true;  
    // base case 2
    if(board[i][j] == s[curr] && currlength == s.size()) return true;
    
    if(board[i][j] != s[curr]) return false;
    
    // main case
    // send board to up down right and left
    vector<vector<int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
    bool checkValid = false;
    for(auto x : direction){
     bool check = find_String(board,i+x[0],j+x[1],currlength+1,s,curr+1,memo);
     if(check) checkValid = true;
    }    

    return memo[i][j] = checkValid;
}


int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<bool>> memo(board.size()+1,vector<bool>(board[0].size(),false));
    string s = "ABCCED";
    int currLenght = 1;
    bool result = find_String(board,0,0,currLenght,s,0,memo);
    cout<<result<<"\n";
}