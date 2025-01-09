#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  // Write your code here.
  int start = 0;
  int end = array.size() - 1;
  while(start <= end){
   int mid  = start + (end - start)/2;
   if(array[mid] == target) return mid;
   if(target > array[mid]) start = mid + 1;
   else end = mid - 1;
  }
  return -1;
}
