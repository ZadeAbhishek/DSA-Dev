/**
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job. 
 * Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
*/

// brute force solution 

class Solution {
public:
    
    int maxSchedule(int index , vector<vector<int>> jobs, vector<int> startTime){
        // base case 
        if(index >= jobs.size()) return 0;
        
        // get lower bound of the index 
        int currIndex = lower_bound(startTime.begin(),startTime.end(),jobs[index][1]) - startTime.begin();

        // two Choices to make
        int take = jobs[index][2] + maxSchedule(currIndex,jobs,startTime);
        int notTake = maxSchedule(index+1,jobs,startTime);

        return max(take,notTake);

    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // dp problem 
        vector<vector<int>> jobs;
        for(auto i = 0 ; i < startTime.size() ; i++) jobs.push_back({startTime[i],endTime[i],profit[i]});
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());

        return maxSchedule(0,jobs,startTime);
    }
};

//memoization 
class Solution {
public:
    
    int maxSchedule(int index , vector<vector<int>> &jobs, vector<int> &startTime, vector<int> &memo){
        // base case 
        if(index >= jobs.size()) return 0;

        // memoization
        if(memo[index] != -1) return memo[index];
        
        // get lower bound of the index 
        int NextIndex = lower_bound(startTime.begin(),startTime.end(),jobs[index][1]) - startTime.begin();

        // two Choices to make
        int take = jobs[index][2] + maxSchedule(NextIndex,jobs,startTime,memo);
        int notTake = maxSchedule(index+1,jobs,startTime,memo);

        return memo[index] = max(take,notTake);

    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // dp problem 
        vector<vector<int>> jobs;
        for(auto i = 0 ; i < startTime.size() ; i++) jobs.push_back({startTime[i],endTime[i],profit[i]});
        vector<int> memo(jobs.size()+1,-1); // -1 represents no avaiable
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());

        return maxSchedule(0,jobs,startTime,memo);
    }
};


//tabulation

class Solution {
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // dp problem 
        vector<vector<int>> jobs;
        for(auto i = 0 ; i < startTime.size() ; i++) jobs.push_back({startTime[i],endTime[i],profit[i]});
        vector<int> memo(jobs.size()+2,0); // -1 represents no avaiable
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());

        for(int index = jobs.size()-1 ; index >= 0 ; index--){
             // get lower bound of the index 
               int NextIndex = lower_bound(startTime.begin(),startTime.end(),jobs[index][1]) - startTime.begin();

              // two Choices to make
               int take = jobs[index][2] + memo[NextIndex];
               int notTake = memo[index+1];

               memo[index] = max(take,notTake);

        }

        return memo[0];
    }
};