/*
Time limit: 1.00 s
Memory limit: 512 MB



Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3
*/

#include<bits/stdc++.h>
using namespace std;

string dfs(vector<vector<int>> &graph, int startCity , int currCity, vector<int> &visited, string path){
       if(startCity == currCity) return path;
       for(auto &next : graph[])    
       
}

int main(){
    int cities;
    int roads;
    cin>>cities>>roads;
    vector<vector<int>> graph(cities+1); // considering node starts from 1
    for(int i = 0 ; i < roads; i++){
        int soure,destination;
        cin>>soure>>destination;
        graph[soure].push_back(destination);
        graph[destination].push_back(soure);
    }
    // now we have to run DFS on each cities 
    string result = "IMPOSSIBLE";
    for(int currentCities = 1; currentCities <= cities; currentCities++){
        vector<int> visited(cities+1,0);
        result = dfs(graph,currentCities,0,visited,"");
        if(result != "IMPOSSIBLE") break;
    }
    cout<<result.size()<<endl;
    cout<<result<<endl;
    return 0;
}