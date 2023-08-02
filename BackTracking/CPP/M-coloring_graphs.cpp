#include<bits/stdc++.h>
using namespace std;
 bool isValid(int CurrNode, int currColor ,bool graph[101][101], int m, int n, int color[]){
        for(int i = 0 ;  i < n ; i++){
            if(CurrNode != i && graph[i][CurrNode] == 1 && color[i] == currColor) return false;
        }
        return true;
    }
    
    bool solve_M_colors(int CurrNode ,bool graph[101][101], int m, int n, int color[]){
        //base case 
        if(CurrNode == n) return true;
        
        //main case
        for(int index = 1 ; index <= m ; index++){
            if(isValid(CurrNode,index,graph,m,n,color)){ 
                color[CurrNode] = index;
                if(solve_M_colors(CurrNode+1,graph,m,n,color)) return true;
                color[CurrNode] = 0;
            }        
        }
        return false;
    }




    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        return solve_M_colors(0,graph,m,n,color);
    }

int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);

}