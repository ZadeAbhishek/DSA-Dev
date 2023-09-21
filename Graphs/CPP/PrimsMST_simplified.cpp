#include<bits/stdc++.h>
using namespace std;

void operator<< (ostream &Cout, vector<vector<int>> r){
    for(auto x : r){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}

// bool cmt(pair<int,int> x , pair<int,int> y){
//      return x.second < y.second;
// }

struct cmt{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)
    {
        return a.second > b.second;
    }
};

int primsMst(vector<vector<int>> graph, int start){
    vector<bool> vis(graph.size(),false);
    int minDistance = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmt> q;
    vector<vector<int>> res;
    q.push({start,0});
    while(!q.empty()){
        pair<int,int> temp = q.top();
        q.pop();
        int curr = temp.first;
        res.push_back({curr,temp.second});
        if(!vis[curr]){
        vis[curr] = true;
        minDistance += temp.second;
        for(auto i = 1; i < graph[curr].size(); i++) if(graph[curr][i] > 0) q.push({i,graph[curr][i]});
        }

    }
   // cout<<res;
    return minDistance;
    
}

int main(){
 vector<vector<int>> graph = {{0,0,0,0,0,0,0},{0,0,2,0,1,4,0},{0,2,0,3,3,0,7},{0,0,3,0,5,0,8},{0,1,3,5,0,9,0},{0,4,0,0,9,0,0},{0,0,7,8,0,0,0}};
 cout<<primsMst(graph,5);

}