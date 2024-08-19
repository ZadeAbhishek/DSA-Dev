#include <vector>

using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array) {
  int height = array.size() - 1;
  int width = array[0].size() - 1;
  int row = 0;
  int col = 0;
  vector<int> result;
  bool isDown = true;
  while(row >= 0 && row <= height && col >= 0 && col <= width){
    result.push_back(array[row][col]);
    if(isDown){
      if(col == 0 || row == height){
        isDown = false;
        if(row == height){
          col += 1;
        }
        else{
          row += 1;
        }
      }
      else{
        row += 1;
        col -= 1;
      }
    }
    else{
      if(row == 0 || col == width){
        isDown = true;
        if(col == width){
          row += 1;
        }
        else{
          col += 1;
        }
      }
      else
      {
        row -= 1;
        col += 1;
      }
    }
  }
  return result;
}
