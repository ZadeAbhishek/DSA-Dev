#include<iostream>
using namespace std;

/*
                       0 1 0 2 0 --> Non highlighted part
                       0 2 2 2 1
                       0 2 1 1 1
                       1 0 1 0 0
                       0 0 1 2 2
                       1 1 0 0 1
                       x x S x x  -->highlighted yellow

1: This cell has a coin.
2: This cell has an enemy.
0: It contains nothing.                       
*/

// start index [N][2]
int board[1000][5],N;
int ans;

void solve(int board[][5], int x, int y, int currCoins, int burstLevel, bool busrtBoom){
    
    // if out of bound
    if(x < 0 || y < 0 || y >= 5) return;

    // if no coin
    if(board[x][y] == 0) return;
    
    // Now there are two case if coin take it or there is boom 
    if(board[x][y] == 1){
        // if equal to one add this to ans and move
        ans = max(ans,currCoins+1);
        solve(board,x-1,1,currCoins+1,burstLevel,busrtBoom);
        solve(board,x-1,2,currCoins+1,burstLevel,busrtBoom);
        solve(board,x-1,3,currCoins+1,burstLevel,busrtBoom);
        return; // return it we dont need to check futher
    }

    if(board[x][y] == 2){
        //if the boom is busrt we cannot use it another time
        //if the boom is busrt booms upto level 5 will be burst 
        // tow case if boom is burst we and still busrtlevel is not zero we can move
        
        if(busrtBoom == false){
             busrtBoom = true;
             solve(board,x-1,1,currCoins,burstLevel-1,busrtBoom);
             solve(board,x-1,2,currCoins,burstLevel-1,busrtBoom);
             solve(board,x-1,3,currCoins,burstLevel-1,busrtBoom);
        }

        
        if(busrtBoom == true && burstLevel > 0){
                 solve(board,x-1,1,currCoins,burstLevel-1,busrtBoom);
                 solve(board,x-1,2,currCoins,burstLevel-1,busrtBoom);
                 solve(board,x-1,3,currCoins,burstLevel-1,busrtBoom);
        }

        if(busrtBoom == true && burstLevel <= 0) return;

    }

    
}


int main(){
int noTestCase;
cin>>noTestCase;
while(noTestCase--){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin>>board[i][j];
        }
    }
    // we can go in three direction starting with [N][2] 
    solve(board,N-1,1,0,5,false);
    solve(board,N-1,2,0,5,false);
    solve(board,N-1,3,0,5,false);

    cout<<ans<<"\n";
}

}

/*
1
6
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1


1
8
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1
2 2 2 2 2
0 0 1 0 0

x x S x x  -->highlighted yellow

*/