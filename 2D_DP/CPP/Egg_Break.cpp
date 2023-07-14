/**
 * You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
*/

// best explanation https://www.youtube.com/watch?v=UvksR0hR9nA&t=1100s&ab_channel=Pepcoding



#include<bits/stdc++.h>
using namespace std;

// we can solve this problem using dp 

int get_Attemps(int eggs , int floors){
    // base case / edges case
    if(eggs == 1) return floors; // if one egg we have to check each floor

    if(floors == 0 || floors == 1) return floors; // if floors are zero or one no matter what we have only 0 or 1 attemp

    int mini = INT_MAX;


        for(int floor = 1 ; floor <= floors ; floor++){
            int survive = get_Attemps(eggs,floors-floor); // go to uper wale floor floors - floor remaining floor
            int not_survive = get_Attemps(eggs-1,floor-1); // curr floor se niche jao
            int maxi = 1 + max(survive,not_survive); // get max add one
            mini = min(maxi,mini);
        }
    
    return mini;

}


int get_Attemps_memo(int eggs , int floors,vector<vector<int>> &dp){
    // base case / edges case
    if(eggs == 1) return floors; // if one egg we have to check each floor

    if(floors == 0 || floors == 1) return floors; // if floors are zero or one no matter what we have only 0 or 1 attemp

    if(dp[eggs][floors] != -1) return dp[eggs][floors];

    int mini = INT_MAX;


        for(int floor = 1 ; floor <= floors ; floor++){
            int survive = get_Attemps_memo(eggs,floors-floor,dp); // go to uper wale floor floors - floor remaining floor
            int not_survive = get_Attemps_memo(eggs-1,floor-1,dp); // curr floor se niche jao
            int maxi = 1 + max(survive,not_survive); // get max add one
            mini = min(maxi,mini);
        }
    
    return dp[eggs][floors] = mini;

}


// diff from above pepCode copyed
int get_Attemps_tabulation(int n , int k){

        int dp[n+1][k+1] = {0};
        
        for(int egg = 1 ; egg <= n ; egg++){
            for(int floor = 1 ; floor <= k ; floor++){
                if(egg == 1) dp[egg][floor] = floor;
                else if(floor == 1) dp[egg][floor] = 1;
                else{
                    // n eggs and k foor
                    int mini = INT_MAX;
                    for(int prevFloor = floor-1, nextFloor = 0; prevFloor >= 0; prevFloor--, nextFloor++){
                        int eggs_Survive = dp[egg][prevFloor];
                        int egg_Break = dp[egg-1][nextFloor];
                        int maxi = max(eggs_Survive,egg_Break);
                        mini = min(mini,maxi);
                    }
                    dp[egg][floor] = mini + 1;
                }
            }
        }
        return dp[n][k];
    }



// driver code
int main(){
    int eggs = 2;
    int floor = 10;
    cout<<get_Attemps(eggs,floor)<<"\n";
    vector<vector<int>> dp(eggs+1,vector<int>(floor+1,-1));
    cout<<get_Attemps_memo(eggs,floor,dp)<<"\n";
    cout<<get_Attemps_tabulation(eggs,floor)<<"\n";
}
