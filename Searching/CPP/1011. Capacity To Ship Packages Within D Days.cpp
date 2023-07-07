
/*
https://www.youtube.com/watch?v=ER_oLmdc-nw&ab_channel=NeetCodeIO
*/

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

// TC n lon W