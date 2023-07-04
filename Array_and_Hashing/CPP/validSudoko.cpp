#include <iostream>

#include <vector>

#include<unordered_map>

#include<string>

#include<bits/stdc++.h>

#include <queue>

using namespace std;

class Solution {
  public: bool isValidSudoku(vector < vector < char >> & board) {
    //Implement HashMap for all three condition 

    unordered_set < char > row;
    unordered_set < char > col;
    unordered_set < char > box; //HP for Box

    // for loop to check about row
    for (auto i = 0; i < 9; i++) {
      for (auto j = 0; j < 9; j++) {
        //cout<<board[i][j]<<endl;  
        //check if dot if present Escape
        if (board[i][j] == '.') {
          continue;
        }
        // check if the char is present in row
        auto it = row.find(board[i][j]);
        if (it != row.end()) {
          return false;
        }
        //if not present add to hashmap
        else {
          row.insert(board[i][j]);
        }
      }
      row.clear();
    }

    for (auto i = 0; i < 9; i++) {
      for (auto j = 0; j < 9; j++) {
        //check if dot if present Escape
        if (board[j][i] == '.') {
          continue;
        }
        // check if the char is present in row 
        if (col.count(board[j][i])) {
          return false;
        } else {
          col.insert(board[j][i]);
        }
      }
      col.clear();
    }
    for (auto resi = 0; resi < 9; resi += 3) {
      for (auto resj = 0; resj < 9; resj += 3) {
        for (auto i = resi; i < resi + 3; i++) {
          for (auto j = resj; j < resj + 3; j++) {
            //cout<<board[i][j]<<endl;  
            //check if dot if present Escape
            if (board[i][j] == '.') {
              continue;
            }
            // check if the char is present in row
            auto it = box.find(board[i][j]);
            if (it != box.end()) {
              return false;
            }
            //if not present add to hashmap
            else {
              box.insert(board[i][j]);
            }
          }
        }
        box.clear();
      }

    }

    return true;
  }
};


int main (){
     vector<vector<char>>  board ={
 {'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}     
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};
   
    Solution* solve = new Solution();    
    bool result = solve->isValidSudoku(board);
    cout<<result;
    cout<<endl;
}