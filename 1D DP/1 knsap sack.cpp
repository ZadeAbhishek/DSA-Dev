#include<bits/stdc++.h>
using namespace std;

int temp = INT_MAX;

void dp(int W, vector<int> w , int* cost, int bag, int maxCost,vector<int> &buff)
{

    if(bag > W) return;
    
    cout<<bag<<" "<<maxCost<<"\n";
    if(bag == W)
    {
        if(temp>=maxCost) temp = maxCost;
        return;
    }

    for(auto i = 0 ; i < size(w) ; i++)
    {
        if(buff[i] == 1) continue;
        buff[i] = 1;
        bag += w[i];
        maxCost += cost[i]; 
        dp(W,w,cost,bag,maxCost,buff);
        buff[i] = 0;
        maxCost -= cost[i];
        bag -= w[i];
    } 
}


void solve(int W, vector<int> w , int* cost)
{
    int bag = 0;
    int maxCost = 0;
    vector<int> buff(size(w),0);
    dp(W,w,cost,bag,maxCost,buff);
}


int main ()
{
    int W = 10;
    vector<int> w = {1,3,4,5};
    int cost[] = {20,30,10,50};
    solve(W,w,cost);
    cout<<temp;
    return 0;
}