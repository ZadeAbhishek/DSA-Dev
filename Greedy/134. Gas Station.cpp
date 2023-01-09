class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // assuming all gas are in accending order
        int tank = 0;
        
        int j = 0;

        int total = 0;
        
        for(auto i = 0 ; i < size(gas) ; i++)
        {
             tank += gas[i] - cost[i];
             if(tank < 0) j = i + 1,tank = 0;
             total += (gas[i] - cost[i]);    
        }
        return (total < 0)? -1 : j;
    }
};