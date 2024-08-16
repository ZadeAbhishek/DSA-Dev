#include <vector>
#include <math.h>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  int arrSize = array.size();
  vector<int> result(arrSize,0);
  int left = 0;
  int right = arrSize - 1;
  for(int i = arrSize - 1 ; i >= 0 ; i--){
    if(abs(array[left]) > abs(array[right])){
      result[i] = pow(array[left],2);
      left++;
    }
    else{
      result[i] = pow(array[right],2);
      right--;
    }
  }
  return result;
}
