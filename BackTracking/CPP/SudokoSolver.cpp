#include<iostream>
#include<vector>

void operator<<(std::ostream &Cout,std::vector<std::vector<char>> board){
    for(auto x : board){
        for(auto y : x){
            std::cout<<y<<" ";
        }
        std::cout<<"\n";
    }
}


bool check(int i , int j , int nums , std::vector<std::vector<char>> &board){

    // check row
    for(auto x = 0 ; x < 9 ; x++){
        if(board[i][x] == char(nums+48)) return false;
    }
    
    // check col
    for(auto x = 0 ; x < 9 ; x++){
        if(board[x][j] == char(nums+48)) return false;
    }
     
    //check current square 3x3
    for(auto x = 0 ; x < 9 ; x++){
        int row = (3 * (i/3)) + x/3;
        int col = (3 * (j/3)) + x%3;
        if(board[row][col] == char(nums+48)) return false;
    }

    return true; 

    
}


bool solver(std::vector<std::vector<char>> &board){
    for(auto i = 0 ; i < 9 ; i++){
        for(auto j = 0 ; j < 9 ; j++){
            if(board[i][j] == '.'){ 
        for(int num = 1 ; num < 10 ; num++){           
            if(check(i,j,num,board)){
            board[i][j] =  char(48+num);
            int res = solver(board);
            if(res) return true;
            else board[i][j] = '.';
          }
        }
        return false;
    }
}
    }
    return true;
}


int main (){
std::vector<std::vector<char>>  board ={
 {'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}     
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};

solver(board);
std::cout<<board;

}