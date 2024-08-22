#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
  // This question we can solve in two parts 
  // part 1 Get maxLenght of LCS
  int rows = str1.size();
  int cols = str2.size();
  vector<vector<int>> dp(rows+1,vector<int>(cols+1));
  for(int row = 1 ; row <= rows ; row++){
    for(int col = 1 ; col <= cols ; col++){
      if(str1[row - 1] == str2[col - 1]){
        dp[row][col] = 1 + dp[row-1][col-1];
      }
      else {
        dp[row][col] = max(dp[row-1][col],dp[row][col-1]); 
      }
    }
  }
    int maxLength = dp[rows][cols];
    vector<char> result(maxLength,' ');
    int row = rows;
    int col = cols;
    int index = maxLength - 1;
    while(row > 0 && col > 0){
      if(str1[row-1] == str2[col-1]){
        result[index] = str1[row-1];
        index--;
        row--;
        col--;
      }
      else {
        if(dp[row-1][col] > dp[row][col-1]){
          row--;
        }
        else {
          col--;
        }
      }
    }
  return result;
}
