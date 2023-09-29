/**
 * Question:
 * There is one spaceship. X and Y co-ordinate of the source of spaceship and destination spaceship
 * is given. There is N number of wormholes; each wormhole has 5 values. First 2 values are 
 * starting co-ordinate of the wormhole and after that value no. 3 and 4 represent ending 
 * co-ordinate of the wormhole and last 5th value is represents a cost to pass through this 
 * wormhole. Now, these warmholes are bi-directional. Now the to go from (x1,y1) to (x2,y2) is 
 * abs(x1-x2)+abs(y1-y2). The main problem here is to find the minimum distance to reach spaceship 
 * from source to destination co-ordinate using any number of warm-hole. It is ok if you won't 
 * uses any warmhole.
 * 
*/

// can not use stl

#include<iostream>
using namespace std;

// global variables 
int wormHole[100][5]; // keep track of worm holes
int visitedWormHoles[100]; //keep track of all visited wormhole;
int minDistance;
int wormHoleSize;

// function to calcate distace
int distance(int sx, int sy, int dx, int dy){
    // s = sorce d = destination x and y corrdinates
    int deltaX = sx>dx?(sx-dx):(dx-sx);
    int deltaY = sy>dy?(sy-dy):(dy-sy);
     return (deltaX + deltaY); // this return total distance between two coordiante
}

//function to calcuate min interger
int min(int x ,int y){
    return x>y?y:x;
}


// This is dfs approch  from codeChef so not conforn if it will work or not
void traverse(int sx, int sy, int dx , int dy , int currDistance){
    // calucate the distace of curent coordiante
    minDistance = min(minDistance,distance(sx,sy,dx,dy)+currDistance);

    //check if we can travese through the current coordiante to wormhole
    for(int hole = 0 ; hole < wormHoleSize ; hole++){
        //check if wormhole is visited or not
        if(visitedWormHoles[hole] == 0){
            //make visted
            visitedWormHoles[hole] = 1;

            // sorce ----> wormHole starting
            int tempDistance = distance(sx,sy,wormHole[hole][0],wormHole[hole][1])+wormHole[hole][4]+currDistance;
            // cal for wormHole distination to curr destination also add distance of warmHole
            traverse(wormHole[hole][2],wormHole[hole][3],dx,dy,tempDistance);

            //source ----> wormhole ending kind of reverse traveling
            tempDistance = distance(sx,sy,wormHole[hole][2],wormHole[hole][3])+wormHole[hole][4]+currDistance;
            traverse(wormHole[hole][0],wormHole[hole][1],dx,dy,tempDistance);

            //mark unvisited
            visitedWormHoles[hole] = 0;


        }
    }
    return;
}




int main(){
    int totalTestCase;
    cin>>totalTestCase;
    while(totalTestCase > 0){
        int sourceX,sourceY,destinationx,destinationY;
        cin>>sourceX>>sourceY>>destinationx>>destinationY;
        cin>>wormHoleSize;
        for(int i = 0 ; i < wormHoleSize ; i++){
            visitedWormHoles[i] = 0;
            for(int j = 0 ; j < 5 ; j++){
                cin>>wormHole[i][j];
            }
        }
        minDistance = 1e9;
        traverse(sourceX,sourceY,destinationx,destinationY,0);
        cout<<minDistance<<endl;

        totalTestCase--;
    }
}



/*
Test case
1
0 0
100 100
3
2 2 120 120 2
4 5 120 100 3
6 8 150 140 4

o/p 32


case 2
1
0 0
100 100
3
1 2 120 120 2
4 5 140 100 3
6 8 102 102 4

o/p 22

*/