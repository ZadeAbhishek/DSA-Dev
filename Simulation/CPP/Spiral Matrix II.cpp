class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
     vector<vector<int>> matrix(n,vector<int>(n,0));
     int top = 0,right = n-1,bottom = n-1,left = 0;
     int count = 1;
     int direction = 0; 
     while(top <= bottom && left <= right)
        {
            
            if(direction == 0){
            for(auto index = top ; index <= right ; index++) matrix[top][index] = count++;
            top += 1;
            } 
            if(direction == 1){  
            for(auto index = top ; index <= bottom ; index++) matrix[index][right] = count++;
            right -= 1;
            }
            if(direction == 2){
            for(auto index = right ; index >= left; index--) matrix[bottom][index] = count++;
            bottom -= 1;
            }
            if(direction == 3){
            for(auto index = bottom ; index >= top ; index--) matrix[index][left] = count++;
            left += 1;
            }
            direction = (direction+1) % 4;
        }
        return matrix;
    }
};