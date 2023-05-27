#include <iostream>

#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void solve(vector < vector < char >> & board) {
      if (board.size() == 0) {
        return;
      }
      vector < vector < bool >> vis(board.size(), vector < bool > (board[0].size(), false));
      // bfs must be used since we  visting neighbours
      for (auto i = 0; i <= board.size() - 1; i++) {
        for (auto j = 0; j <= board[0].size() - 1; j++) {
          if (board[i][j] == 'O') {
            if (bfs(board, i, j, vis)) {
              board[i][j] = 'X';
            }

          }
        }
      }
    }
  private:
    bool bfs(vector < vector < char >> & b, int i, int j, vector < vector < bool >> vis) {
      //cout<<i<<" "<<j<<endl;
      if (i >= 0 && j >= 0 && i <= b.size() - 1 && j <= b[0].size() - 1 && b[i][j] == 'X') {
        return true;
      }
      if (isEdge(i, j, b) && b[i][j] == 'O') {
        return false;
      }
      if (i >= 0 && j >= 0 && i <= b.size() - 1 && j <= b[0].size() - 1 && vis[i][j] && b[i][j] == 'O') {
        return true;
      }

      // queue<pair<int,int>> q;
      // pair<int,int> temp;
      // temp.first = i;
      // temp.second = j;
      // q.push(temp);
      // while(!q.empty()){
      //pair<int,int> temp_pair = q.front();
      if (i >= 0 && j >= 0 && i <= b.size() - 1 && j <= b[0].size() - 1 && !vis[i][j]) {
        vis[i][j] = true;
        int x = i;
        int y = j;
        //q.pop();
        // direction 0,1 1,0 0,-1 -1,0
        if (bfs(b, x + 1, j, vis) && bfs(b, x - 1, j, vis) && bfs(b, x, j + 1, vis) && bfs(b, x, j - 1, vis)) {

          return true;
        }
        vis[x][y] = false;
      }
      return false;
    }

  bool isEdge(int i, int j, vector < vector < char >> & b) {
    for (int x = 0; x < b.size(); x++) {
      if (i == x && j == 0) {
        return true;
      }
      if (i == x && j == b[0].size() - 1) {
        return true;
      }
    }
    for (int x = 0; x < b[0].size(); x++) {
      if (i == 0 && j == x) {
        return true;
      }
      if (i == b.size() - 1 && j == x) {
        return true;
      }
    }
    return false;
  }

};

int main() {
  //vector<vector<char>> matrix = {{'X'}};
  vector < vector < char >> matrix = {
    {
      'X',
      'O',
      'X',
      'O',
      'X',
      'O'
},
    {
      'O',
      'X',
      'O',
      'X',
      'O',
      'X'
    },
    {
      'X',
      'O',
      'X',
      'O',
      'X',
      'O'
    },
    {
      'O',
      'X',
      'O',
      'X',
      'O',
      'X'
    }
  };
  Solution * Solve = new Solution();
  Solve -> solve(matrix);
  for (auto i = 0; i <= matrix.size() - 1; i++) {
    for (auto j = 0; j <= matrix[0].size() - 1; j++) {

      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}