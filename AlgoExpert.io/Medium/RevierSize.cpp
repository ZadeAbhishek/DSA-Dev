#include <vector>
using namespace std;

void solve(vector<vector<int>> &matrix, int i, int j, int& counter){
  if(i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size() && matrix[i][j]){
     counter++;
     matrix[i][j] = 0;
     solve(matrix,i-1,j,counter);
     solve(matrix,i+1,j,counter);
     solve(matrix,i,j-1,counter);
     solve(matrix,i,j+1,counter);
  }
   return;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
  // only reccursion can solve this problem
  vector<int> result;
  for(int i = 0 ; i < matrix.size() ; i++){
    for(int j = 0 ; j < matrix[i].size(); j++){
       if(matrix[i][j]){
        int counter = 0;
        solve(matrix,i,j,counter);
        result.push_back(counter);
       }
    }
  }
  return result;
}

// optimised approch from chatgpt
#include <vector>
#include <stack>

using namespace std;

void solve(vector<vector<int>>& matrix, int i, int j, int& counter) {
    stack<pair<int, int>> nodes;
    nodes.push({i, j});
    
    while (!nodes.empty()) {
        auto [x, y] = nodes.top();
        nodes.pop();
        
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] == 0) {
            continue;
        }
        
        counter++;
        matrix[x][y] = 0;
        
        nodes.push({x-1, y});
        nodes.push({x+1, y});
        nodes.push({x, y-1});
        nodes.push({x, y+1});
    }
}

vector<int> riverSizes(vector<vector<int>> matrix) {
    vector<int> result;
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                int counter = 0;
                solve(matrix, i, j, counter);
                result.push_back(counter);
            }
        }
    }
    
    return result;
}
