#include<bits/stdc++.h>
using namespace std;

int temp = INT_MAX;

int solve(int bag_weight, vector<int> w , vector<int> cost,int max_cost,vector<vector<int>> &vis,int i)
{
   // using dp we have to solve
   if(bag_weight == 0) return max_cost;
   
   if(bag_weight < 0 || i >= size(w)) return 0;
   

   return max(solve(bag_weight-w[i],w,cost,max_cost+cost[i],vis,i+1),solve(bag_weight,w,cost,max_cost,vis,i+1));

}


int main ()
{
    int W = 10;
    vector<int> w = {1,3,4,5};
    vector<int> cost = {20,30,10,50};
    int max_cost = 0;
    vector<vector<int>> vis(size(w)+1,vector<int>(W+1,-1));
    cout<<solve(W,w,cost,max_cost,vis,0);
    return 0;
}