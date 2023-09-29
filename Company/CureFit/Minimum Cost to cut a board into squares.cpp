/*

A board of length m and width n is given, we need to break this board into m*n squares such 
that cost of breaking is minimum. cutting cost for each edge will be given for the board. 
In short, we need to choose such a sequence of cutting such that cost is minimized.

https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/

Minimum Cost to cut a board into squares using a greedy algorithm:

This problem can be solved by greedy approach . To get minimum cost , the idea is to cut the 
edge with highest cost first because we have less number of pieces and after every cut the 
number of pieces increase . As the question 
stated Total_cost = Total_cost + edge_cost * total_pieces.


Input:
M = 6. N = 4
X[] = {2, 1, 3, 1, 4}
Y[] = {4, 1, 2}
Output: 42

*/
#include<iostream>
#include<algorithm>
using namespace std;



int mincostOfBreaking(int vertical[], int horizontal[] , int m , int n){
      
      // this is greedy approch 


      int cost = 0;

      // sort in decesinding so we start with max cost
      sort(vertical,vertical+m,greater<int>());
      sort(horizontal,horizontal+n,greater<int>());

      // varaible to track number of pecies on board initially we have 1
      int horizontalPiece = 1;
      int verticalPiece = 1;

      // loop until any one array is not left
      int i = 0;
      int j = 0;

      while(i < m && j < n){
        if(vertical[i] > horizontal[j]){
            cost += vertical[i]*verticalPiece;
            horizontalPiece++; // increace horizontal piece 
            i++; 
        }

        else{
            cost += horizontal[j]*horizontalPiece;
            verticalPiece++; // increase vertical piece
            j++; 
        }
      }
      

      // add all remaining
      int total = 0;
      while(i < m){
        total += vertical[i++];
      }
      cost += total * verticalPiece;


      total = 0;
      while(j < n){
        total += horizontal[j++];
      }
      cost += total * horizontalPiece;

      return cost; 
}


int main(){

    int m = 5;
    int n = 3;
    int vertical[] = {2, 1, 3, 1, 4}; // vertical cost
    int horizontal[] = {4, 1, 2}; // horizontal cost
    cout<<mincostOfBreaking(vertical,horizontal,m,n)<<"\n";
    return 0;
}