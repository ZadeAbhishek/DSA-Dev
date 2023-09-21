
/*
https://www.youtube.com/watch?v=ER_oLmdc-nw&ab_channel=NeetCodeIO
*/
#include<bits/stdc++.h>
using namespace std;

// same as Split Array Largest Sum 410. 

class Solution {
public:
       bool capacity(int cap,vector<int>& weights,int days){
            int shipsCapacity = cap;
            int shipCount = 1;
            for(auto x : weights){
                if(shipsCapacity - x < 0) shipsCapacity = cap,shipCount++;
                shipsCapacity -= x;
            }
            return shipCount <= days;
        }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // calcualte max elemnt in vector arr
        int high = accumulate(weights.begin(), weights.end(), 0); // gives sum of array
        int minShip = INT_MAX;

        while(low <= high){
            int cap = (low + high)/2;
            if(capacity(cap,weights,days)){
                minShip = min(minShip,cap);
                high = cap - 1;
            }
            else low = cap + 1;
        }
        return minShip;
    }
}; 

int main() {
    Solution solution;

    // Test Case 1
    std::vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    int result1 = solution.shipWithinDays(weights1, days1);
    std::cout << "Test Case 1: Minimum capacity needed to ship within " << days1 << " days is " << result1 << std::endl;

    // Test Case 2
    std::vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    int result2 = solution.shipWithinDays(weights2, days2);
    std::cout << "Test Case 2: Minimum capacity needed to ship within " << days2 << " days is " << result2 << std::endl;

    // Test Case 3
    std::vector<int> weights3 = {1, 2, 3, 1, 1};
    int days3 = 4;
    int result3 = solution.shipWithinDays(weights3, days3);
    std::cout << "Test Case 3: Minimum capacity needed to ship within " << days3 << " days is " << result3 << std::endl;

    return 0;
}

// TC n lon W