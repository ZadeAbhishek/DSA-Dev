// Rotate matrix 90 deg
// 1 2 3      7 4 1
// 4 5 6 -->  8 5 2
// 7 8 9      9 6 3

#include<iostream>
#include<vector>
#include<algorithm> // contain reverse algorthm


void operator<<(std::ostream &Cout,std::vector<std::vector<int>> matrix){
    for(auto x : matrix){
        for(auto y : x) Cout<<y<<" ";
        Cout<<"\n";
    }
}
//TC O(n^2) SC:O(n^2)
void rotateBrute(std::vector<std::vector<int>>& matrix) {
        // BruteForce appoch would be
        // i == j
        // j = size - 1 - i
        std::vector<std::vector<int>> temp(matrix.size(),std::vector<int>(matrix[0].size(),0));
        int size = matrix[0].size()-1;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                temp[j][size-i] = matrix[i][j];
            }
        }

        std::cout<<temp;  
}

// 1 2 3                    1 4 7                   7 4 1
// 4 5 6 --> Transpose -->  2 5 8  --->reverse rows 8 5 2
// 7 8 9                    9 6 3                   9 6 3
//TC O(n^2) SC:O(1)
void rotate(std::vector<std::vector<int>>& matrix) {
    // optimal approch
    // observe diagonals are same but upper traingle coordinate are opposite to each other
    for(int i = 0; i < matrix.size() ; i++){
            for(int j = i+1 ; j < matrix[i].size() ; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    
    std::cout<<matrix;  
    // step 2 revese
    for(auto &row : matrix) std::reverse(row.begin(),row.end()); 

    std::cout<<matrix;  
        
}

int main(){
    std::vector<std::vector<int>> image = {{1,2,3},{4,5,6},{7,8,9}};
    //rotateBrute(image);
    //std::cout<<image;
    rotate(image);

}