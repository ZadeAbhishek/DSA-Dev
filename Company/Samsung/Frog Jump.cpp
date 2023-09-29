/*

// source https://github.com/s-kachroo/SamsungPractice/blob/master/frog%20jump.cpp#L67

Given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump). 
A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only) 
with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump).
*/

// classic example of bfs travel
// so horitzontal means x direction which is free and vetical means y direction (paid)

#include<iostream>
using namespace std;

#define qsize 1000

// global variable
int area[105][105];
int visitedArea[105][105];
int dis[105][105];
int size , sourceX , sourceY , destinationX , destinationY;

//struct for point
struct node
{
   int x;
   int y;
};

// queue
int front = -1;
int back = -1;

node queue[qsize];

// direction matrix
int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

// check validity
int isVald(int x, int y){
     if(x < 0 || y < 0 || x > size-1 || y > size-1) return false;
     return true;
}

void bfs(){
    // push source element in queue
    queue[back].x = sourceX;
    queue[back].y = sourceY;
    
    back = (back + 1) % qsize; // we are doing mod to prevent outof bound

    visitedArea[sourceX][sourceY] = 1;
    dis[sourceX][sourceY] = 0;

    while(front < back){
        // pop elements from queue
        int currX = queue[front].x;
        int currY = queue[front].y;
        front = (front + 1)%qsize;

        for(int i = 0 ; i < 4 ; i++){
            // check all direction
            int newX = currX+directions[i][0];
            int newY = currY+directions[i][1];
            if((isVald(newX,newY)) && area[newX][newY] == 1 && visitedArea[newX][newY] == 0){
                visitedArea[newX][newY] = 1;
                if(i == 0 || i == 1 ){
                // we are not adding any cost/distance to distance matrix as here we are movinh horizontal direction
                    dis[newX][newY] = dis[currX][currY];
                }
                else{
                 // we are adding cost here
                   dis[newX][newY] = 1 + dis[currX][currY];   
                }

                queue[back].x = newX;
                queue[back].y = newY;
                back = (back + 1) % qsize;
            }
        }
    }
    cout<<dis[destinationX][destinationY]<<"\n";
}

int main(){
    int totalTestcase;
    cin>>totalTestcase;
    while(totalTestcase--){
        cin>>sourceX>>sourceY>>destinationX>>destinationY;
        cin>>size;
        front = 0;
        back = 0;
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                cin>>area[i][j];
                dis[i][j] = 0;
                visitedArea[i][j] = 0;
            }
        }
        bfs();
        return 0;
    }
}
