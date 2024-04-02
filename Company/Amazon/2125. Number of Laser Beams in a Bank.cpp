#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevOnes = 0;
        int currentOnes = 0;
        int totalLaser = 0;
        for(auto &currRow : bank){
            int rowSize = currRow.size();
            int index = 0;
            while(rowSize) currentOnes += currRow[index] == '1'?1:0,index++,rowSize--;
            if(currentOnes != 0){ // Don't update prevOnes 
            totalLaser += (prevOnes * currentOnes);
            prevOnes = currentOnes;
            currentOnes = 0;
            }
        }
        return totalLaser;
    }
};

int main() {
    // Test the Solution class
    Solution solution;
    vector<string> bank = {"011001","000000","010100","001000"};

    cout << "Number of beams: " << solution.numberOfBeams(bank) << endl;

    return 0;
}
