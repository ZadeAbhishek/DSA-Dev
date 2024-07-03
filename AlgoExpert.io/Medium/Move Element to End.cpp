#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
  // pointer approch will help here
  if(array.size() == 1) return array; 
  int i = 0;
  int j = 1;
  while(j < array.size()){
     if(array[j] != toMove){
    swap(array[j],array[i]);
    i++;
    j++;
    }
     else j++;
   }
  return array;
}
