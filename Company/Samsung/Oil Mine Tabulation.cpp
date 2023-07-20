/*
oil mines dp
 
THIS CODE  IS SUBJECT TO COPYRIGHT.
 
TEST CASES
 
5 10
2 3 5 7 6 2 1 9 8 5
ans = 4
 
4 7
12 3 5 67 54 3 4
ans = 59
 
8 9
1 2 3 4 5 6 7 8 9
ans = 6
 
4 10
9 18 7 6 3 24 1 5 8 9
ans = 11
 
1 4
1 2 3 4
ans = 0
 
5 4
1 2 3 4
ans -1
 
2 15
1 34 5 7 3 21 90 81 32 4 23 42 84 11 29
ans = 1
 
Time complexity = O(n^2*k^2)
space complexity = O(n*k*2)
*/
 
#include<bits/stdc++.h>
using namespace std;
 
int n,c;
int a[100];
int b[100];
int pre[100];
int dp[100][100][2];
 
/* fn to precompute the prefix */
void sum(){
    for(int i=1; i<=n; i++)
       pre[i] = a[i] + pre[i-1];
}
 
int solve(){
    
   for(int j = 1; j<=n; j++){
       for(int k = 1; k<=c && k<=j; k++){
          
          /* Base case */
           if(k == 1){
               dp[j][k][0] =  pre[j];
               dp[j][k][1] =  pre[j];
           }
        
           else{
 
               int temp = INT_MAX;
               for(int l = j; l>k-1; l--){
                   /* magic happens here */
                     
                    int mn = min((pre[j]-pre[l-1]), min(dp[l-1][k-1][0], dp[l-1][k-1][1]));
                    int mx = max((pre[j]-pre[l-1]), max(dp[l-1][k-1][0], dp[l-1][k-1][1]));
                    
                    if(mx-mn < temp){
                        temp = mx - mn;
                        dp[j][k][0] = mn;
                        dp[j][k][1] = mx;
                    }
            
               }
               
                 
           }
          
       }
   }
   //cout<<dp[2][2][0]<<" "<<dp[2][2][1]<<endl;
   return dp[n][c][1] - dp[n][c][0];
}
 
 
int main(){
    
    int t; cin>>t;
    while(t--){
 
        cin>>c;
        cin>>n;
        
        for(int i = 1; i<=n; i++)cin>>b[i];
        
        /* this is done to iterate for every window size of a circular array 
           basically adding element to end of array                         */
        for(int i = n+1; i<=2*n; i++)b[i] = b[i-n];
        
        int ans = INT_MAX;
        for(int i = 1; i<=n+1; i++){
                int j = i+n-1;
                
                memset(dp,0,sizeof(dp));
                memset(pre, 0, sizeof(pre));
                
                /* this is done so that we don't have to map the index 
                 due to this everytime the indexing will be from 1-n */
                int temp  = 1;
                for(int k = i; k<=j; k++){
                    a[temp] = b[k];
                    temp++;
                }
                
                 sum();
                 
                 ans = min(ans, solve());
            
        }
       if(c>n)ans = -1;
       cout<<ans<<endl;
    }
}
