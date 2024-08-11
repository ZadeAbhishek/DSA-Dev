#include <vector>
using namespace std;


// Comparison:

//	Your current approach: O(n + m) complexity.
//	Binary search on a fully sorted matrix: O(log(n * m)) complexity.
// https://www.algoexpert.io/questions/search-in-sorted-matrix

// time complexity O(n + m)
vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  // Write your code here.
  int n = matrix.size();
  int m = matrix[n - 1].size();
  int i = 0;
  int j = m - 1;
  while(i >= 0 && j >= 0 && i < n && j < m){
    if(matrix[i][j] < target) ++i;
    else if(matrix[i][j] > target) --j;
    else return {i,j};
  }
  return {-1,-1};
}


// O(log(n*m))
// More optimised way using binary search 
#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n * m - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target) {
            return {row, col};
        } else if (matrix[row][col] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return {-1, -1};
}