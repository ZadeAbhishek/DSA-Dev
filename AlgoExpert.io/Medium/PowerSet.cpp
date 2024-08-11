#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
  // Write your code here.
  vector<vector<int>> result;
  vector<int> temp;
  for(int i = 0 ; i < pow(2,array.size()); i++){
    temp.clear();
    for(int j = 0 ; j < array.size() ; j++){
      if(i & (1<<j)) temp.push_back(array[j]);
    }
    result.push_back(temp);
  }
  return result;
}