using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  // Write your code here.
  int top = 0;
  int bottom = array.size() - 1;
  int right = array[0].size() - 1;
  int left = 0;
  int direction = 0; // we are using mod operation to rotate
  vector<int> answer;
  while(top <= bottom && left <= right){
    if(direction == 0){
     for(auto index = top; index <= right; index++){
        answer.push_back(array[top][index]);
     }
      top += 1;
    }
    if(direction == 1){
     for(auto index = top; index <= bottom ; index++){
       answer.push_back(array[index][right]);
     }
      right -= 1;
    }
    if(direction == 2){
     for(auto index = right; index >= left; index--){
       answer.push_back(array[bottom][index]);
     }
      bottom -= 1;
    }
    if(direction == 3){
     for(auto index = bottom; index >= top; index--){
       answer.push_back(array[index][left]);
     }
      left += 1;
    }
    direction = (direction+1) % 4;
     
  }
  return answer;
}
