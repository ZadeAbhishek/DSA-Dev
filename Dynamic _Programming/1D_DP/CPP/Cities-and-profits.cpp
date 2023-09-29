/*
There is arrays with cities and profit on each city. Person can travel from city i to city j if i<j and profit of j is multiple of profit at i. return maximum profit person can achieve.
e.g. cities= [1,2,3,4,5] profit=[3,4,6,8,10]
ans = 12
*/

#include<bits/stdc++.h>
using namespace std;

int getProfit(vector<int> cities,vector<int> profits,int profit, int &maxProfit){
    
    for(auto i = 0 ; i < size(cities); i++){
          profit = profits[i];
        for(auto j = i+1 ; j < size(cities); j++){
              if(cities[i] > cities[j]) continue;

              if(profits[j]%profits[i] != 0)continue;

              profit += profits[j]; 
        }
        maxProfit = max(maxProfit,profit);
    }

    return maxProfit;
}

int main(){
    vector<int> cities = {1,2,3,4,5};
    vector<int> profits = {3,4,6,8,6};
    vector<int> memo(size(cities),0);
    int profit = 0;
    int maxProfit = INT_MIN;
    getProfit(cities,profits,profit,maxProfit);
    cout<<maxProfit<<endl;
}