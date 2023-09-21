/*
D daigonal i = (row + col)
    0 1 2 3 4
  .......... 
0 . 0 1 2 3 4
1 . 1 2 3 4 5
2 . 2 3 4 5 6
3 . 3 4 5 6 7

u Diagonal i = (row - col) + (n-1)

    0 1 2 3 4
  .......... 
0 . 3 4 5 6 7
1 . 2 3 4 5 6
2 . 1 2 3 4 5 
3 . 0 1 2 3 4

*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int,bool> DiagonalD;
unordered_map<int,bool> DaigonalU;
unordered_map<int,bool> column;

void operator<< (ostream &Cout,vector<vector<vector<int>>> res){
     for(auto x : res){
        for(auto y : x){
            for(auto z : y){
                cout<<z<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}


bool check(int col, int row,int arrLenght){
    if(column.count(row) && column[row]==true) return false;
    if(DaigonalU.count((row-col)+(arrLenght - 1)) && DaigonalU[(row-col)+(arrLenght - 1)]==true) return false;
    if(DiagonalD.count(col+row) && DiagonalD[col+row]==true) return false;
    return true;
}

bool nQueen(vector<vector<int>> &arr,int col,vector<vector<vector<int>>> &res){
    // base case 
    if(col == arr.size()){
        res.push_back(arr);
        return true;
    }
    for(auto i = 0 ; i < arr.size() ; i++){
        if(check(col,i,arr.size())){
           
            
            DiagonalD[col+i]=true;  

            DaigonalU[(i-col)+((arr.size()) - 1)]=true;

            column[i] = true;

            arr[col][i] = 1;

            if(nQueen(arr,col+1,res)) return true;

            arr[col][i] = 0;

            DaigonalU[(i-col)+((arr.size()) - 1)] = false;

            DiagonalD[col+i] = false;
            
            column[i] = false;

        }
    }
    return false;

}


int main(){
  vector<vector<int>> arr = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
  vector<vector<vector<int>>> res;
  cout<<nQueen(arr,0,res)<<"\n";
  cout<<res;
}
