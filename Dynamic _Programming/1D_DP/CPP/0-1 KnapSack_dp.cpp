#include<iostream>
#include<string.h>
using namespace std;


int w[1000];
int c[1000];
int W;
int dp[1000][1000] = {0};
int size_item;

int max(int x, int y){
    return (x>y)?x:y;
}

int solve(int i, int bag, int curr_max, int &maxi){
    // base case
    if(i > size_item+1) return curr_max;
    
    if(bag > W) return -1e9;

    maxi = max(curr_max,maxi);

    if(bag == W) return dp[i][bag] = maxi;
    
    cout<<dp[i][bag]<<"\n";

    if(dp[i][bag] != 0) return dp[i][bag];

    return dp[i][bag] = max(solve(i+1,bag+w[i],curr_max+c[i],maxi), solve(i+1,bag,curr_max,maxi)); 
}


int main(){
   
   int t;
   cin>>t;
   for(int i = 1 ; i <= t ; i++){
       cin>>size_item;
       for(int i = 1; i <= size_item ; i++) cin>>w[i];
       for(int i = 1; i <= size_item ; i++) cin>>c[i];
       memset(dp,0,sizeof dp);
       int bag = 0;
       cin>>W;
       int maxi = -1e9;
       cout<<"Case #"<<i<<":"<<solve(1,0,0,maxi)<<endl;
   }

}
/*
3
3
10 20 30
60 100 120
50
3
4 5 1
1 2 3
4
3
4 5 3
10 30 3
10



*/