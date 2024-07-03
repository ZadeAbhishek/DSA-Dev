using namespace std;

bool isMonotonic(vector<int> array) {
  // Write your code here.
  bool decreasing = true;
  bool increasing = true;
  for(auto i = 1 ; i < array.size() ; i++){
     if(array[i-1] > array[i]) decreasing = false;
     if(array[i-1] < array[i]) increasing = false;
     if(!increasing && !decreasing) return false;
   
  }
  return true;
}
