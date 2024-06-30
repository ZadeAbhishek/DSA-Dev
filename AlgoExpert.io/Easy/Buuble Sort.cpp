#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
  // Write your code here.
  int pass = array.size();
  while(pass--){
    int i = 0;
    int j = 1;
    while(i < pass){
     if(array[i] > array[j]) swap(array[i],array[j]);
     i++, j++;
    }
  }
  return array;
}
