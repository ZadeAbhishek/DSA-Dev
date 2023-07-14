/**
 * Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).

*/

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
   static bool compare(Job a, Job b){
        return (a.profit > b.profit);
    }
    
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // greedy approch is used here 
        // why greedy i guess the every job has 1 unit of execution time.
        // sort the array according to max Profit
        // start filling job to array and sum the profit
        
        //vector<int> jobs(n,-1); // -1 represents no job scheduled
        
        sort(arr, arr+n , compare);
        
        int max_Deadline = 0;
        
        for(int i = 0 ; i < n ; i++){
            max_Deadline = max(max_Deadline,arr[i].dead);
        }
        
        vector<int> jobs(max_Deadline+1,-1); // -1 represents no job scheduled
        
        int jobCount = 0 ;
        int maxProfit = 0;
        
        for(int i = 0 ; i < n  ; i++){
            for(int j = arr[i].dead ; j > 0 ; j--){
                
                if(jobs[j] == -1){
                    // availabe 
                    jobs[j] = arr[i].id;
                    jobCount += 1;
                    maxProfit += arr[i].profit;
                    break; // this break is imp
                }
            }
        }
        
        return {jobCount,maxProfit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends