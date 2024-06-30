#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
  // can we use maxHeap
  priority_queue<int> heap;
  for(auto num : array) heap.push(num);
  vector<int> result(3,0);
  int window = 3;
  while(window--){
   result[window] = heap.top();
   heap.pop(); 
  }
  return result;
}
