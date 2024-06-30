#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> arr) {
  // Write your code here.
  int temp_index = 0;
  for (int i = 1; i < arr.size(); i++) { // Corrected array size syntax
    temp_index = i;
    while (temp_index > 0 && arr[temp_index] < arr[temp_index - 1]) { // Corrected order of conditions
      swap(arr[temp_index], arr[temp_index - 1]);
      temp_index--;
    }
  }
  return arr;
}
