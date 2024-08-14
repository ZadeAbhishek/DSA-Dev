/*
Problem Statement

	•	You have n computer games, each game has a size denoted by gameSize[i] where 1 ≤ i ≤ n.
	•	You need to distribute these games among k children using pen drives.
	•	Each pen drive has the same storage capacity.
	•	Each child can receive a maximum of 2 games, and every child must receive at least one game.

Objective

You need to determine the minimum storage capacity required for each pen drive such that all games can be distributed according to the rules.

Example (as per the question)

	•	n = 4
	•	gameSize = [9, 2, 4, 6]
	•	k = 3

To distribute these games:

	1.	The first pen drive must be able to hold the largest game, which is 9 units.
	2.	The second pen drive will hold games of size 2 and 4 (which sums up to 6 units).
	3.	The third pen drive will hold the game of size 6.

Thus, the minimum storage capacity required for each pen drive is 9 units.
*/

#include <vector>
#include <climits> // for INT_MAX , INT_MIN
#include <iostream>
using namespace std;

int calculateMinSize(vector<int> gameSize , int n , int k){
   // we have to send min size of the Pendrive for k students
   int start = INT_MIN;
   int end = 0;
   for(int i = 0 ; i < n ; i++){
      start = max(start,gameSize[i]);
      end += gameSize[i]; 
   }

   int minPendriveSize = end;

   while(start <= end){
      int mid = start + ((end - start) / 2);
      // here we have to check if we can complete k students with size of mid
      int tempSize = mid;
      int currentK = 1;
      bool canDistribute = true;
      for(int i = 0 ; i < n ; i++){
         if(gameSize[i] > tempSize){
            currentK++;
            tempSize = mid;
         }
            tempSize -= gameSize[i];
            if(currentK > k) {
                canDistribute = false;
                break;
            }
      }
      if(canDistribute) {
          minPendriveSize = mid;
          end = mid - 1;
      }
      else start = mid + 1;
   }

   return minPendriveSize;

}

int main() {
    vector<int> gameSize1 = {9, 2, 4, 6};
    int k1 = 3;
    cout << "Minimum pen drive size for Test Case 1: " << calculateMinSize(gameSize1, gameSize1.size(), k1) << endl;

    vector<int> gameSize2 = {1};
    int k2 = 1;
    cout << "Minimum pen drive size for Test Case 2: " << calculateMinSize(gameSize2, gameSize2.size(), k2) << endl;

    vector<int> gameSize3 = {5, 5};
    int k3 = 2;
    cout << "Minimum pen drive size for Test Case 3: " << calculateMinSize(gameSize3, gameSize3.size(), k3) << endl;

    vector<int> gameSize4 = {2, 2, 2, 2};
    int k4 = 2;
    cout << "Minimum pen drive size for Test Case 4: " << calculateMinSize(gameSize4, gameSize4.size(), k4) << endl;

    vector<int> gameSize5 = {4, 8, 2, 10, 7, 1};
    int k5 = 4;
    cout << "Minimum pen drive size for Test Case 5: " << calculateMinSize(gameSize5, gameSize5.size(), k5) << endl;

    return 0;
}