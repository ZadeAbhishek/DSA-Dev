#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
  vector<int> minJumps(array.size(),INT_MAX); 
  minJumps[0] = 0;
  for(int i = 1; i < array.size(); i++){
    for(int j = 0 ; j <= i; j++){
      if(array[j]+j >= i){
        minJumps[i] = min(minJumps[i],minJumps[j]+1);
      }
    }
  }
  return minJumps[minJumps.size()-1];
}



#include <vector>
#include <algorithm>  // Include this for the max function

using namespace std;

int minNumberOfJumps(vector<int> array) {
    // base case
    if (array.size() == 1) return 0;
    
    int maxReach = array[0];  // The farthest index we can reach currently
    int steps = array[0];     // Steps we can still take before needing another jump
    int jumps = 1;            // We need at least one jump to move forward

    for (int i = 1; i < array.size(); i++) {
        if (i == array.size() - 1) {
            return jumps;  // If we've reached the last element, return the number of jumps
        }

        maxReach = max(maxReach, array[i] + i);  // Update maxReach if the current position allows us to reach further
        steps--;  // Decrease the number of steps

        if (steps == 0) {
            jumps++;  // We need to make another jump
            steps = maxReach - i;  // Set steps to the number of indices we can cover from the current index
        }
    }
    
    return jumps;
}