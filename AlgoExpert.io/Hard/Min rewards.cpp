#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
  vector<int> memo(scores.size(),1);
  for(int i = 1 ; i < scores.size(); i++){
     int ci = scores.size() - i; // this will start from last

     // left --> right 
     if(scores[i] > scores[i-1]){
      int temp = memo[i-1] + 1;
       memo[i] = max(memo[i],temp);
     }

    // right --> left
    if(scores[ci] < scores[ci - 1]){
       int temp = memo[ci] + 1;
       memo[ci-1] = max(memo[ci-1],temp);
    }
  }
   int total = 0;
   for(auto x : memo){
     total += x;
   }
  return total;
}


// more optimised solution by chatgpt sc : O(1)
#include <vector>
#include <algorithm> // For max function
using namespace std;

int minRewards(vector<int> scores) {
    int n = scores.size();
    
    // Edge case for a single score
    if (n == 1) return 1;

    // First pass: left to right
    int total = 1;  // Start with 1 reward for the first element
    int currentReward = 1;

    for (int i = 1; i < n; i++) {
        if (scores[i] > scores[i - 1]) {
            currentReward++;
        } else {
            currentReward = 1;
        }
        total += currentReward;
    }

    // Second pass: right to left
    currentReward = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (scores[i] > scores[i + 1]) {
            currentReward++;
        } else {
            currentReward = 1;
        }

        // Here, we subtract the reward previously added for scores[i]
        // and then add the maximum of the current reward or the previously computed one.
        total += max(currentReward, 1) - 1;
    }

    return total;
}