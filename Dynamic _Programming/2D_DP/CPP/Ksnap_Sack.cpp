#include<bits/stdc++.h>
using namespace std;

int main(){
    int capacity = 10;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {5, 8, 6, 10};
    int n = weights.size();
    
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));  // Corrected capacity size here
    
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= capacity ; j++){
            if(weights[i-1] <= j){
                dp[i][j] = max(values[i-1]+ dp[i-1][j - weights[i-1]],dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][capacity]<<"\n";
    return 0;
}