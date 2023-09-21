/**
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<bool> col, diag, anti_diag;
public:
    int totalNQueens(int n) {
	col.resize(n);
	diag.resize(2*n-1);
	anti_diag.resize(2*n-1);	
	return solve(0);
}
   
int solve(int row) {
	int n = col.size(), count = 0;
    if(row == n) return 1;
	for(int column = 0; column < n; column++)           
		if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){ 
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;
			count += solve(row + 1); 
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false; 
		}                                
	return count;
}
};


int main(){
	Solution s;
	cout<<s.totalNQueens(10)<<"\n";
}