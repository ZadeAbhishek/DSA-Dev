
#include <bits/stdc++.h>
using namespace std;

template<class T>
 
 void operator<< (ostream& Cout,vector<T> result){
    for(auto i : result) Cout<<i<<" ";
    Cout<<"\n";
 } 


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0,right = size(matrix[0])-1,bottom = size(matrix)-1,left = 0;

       int direction = 0; 

        while(top <= bottom && left <= right)
        {
            
            if(direction == 0){
            for(auto index = top ; index <= right ; index++) result.push_back(matrix[top][index]);
            top += 1;
            } 
            if(direction == 1){  
            for(auto index = top ; index <= bottom ; index++) result.push_back(matrix[index][right]);
            right -= 1;
            }
            if(direction == 2){
            for(auto index = right ; index >= left; index--) result.push_back(matrix[bottom][index]);
            bottom -= 1;
            }
            if(direction == 3){
            for(auto index = bottom ; index >= top ; index--) result.push_back(matrix[index][left]);
            left += 1;
            }
            direction = (direction+1) % 4;
        }
        return result;
    }
};


int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution* solve = new Solution();
    cout<<solve->spiralOrder(matrix);
}