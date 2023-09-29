#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// Done lots of mistake but finally done with this dfs 
// i guess i have to practise more
void insert(vector<int> node[],int u ,int v){
          node[u].push_back(v);
          node[v].push_back(u);      
}
void dfs(vector<int> node[],int n,int index,vector<int> &vis){
     cout<<index; // print the visited
      vis[index] = 1; // make curr node to be visited
      for(auto it: node[index]){ // range for loop 
        if(!vis[it]){   // if adjecents are visited 
        dfs(node,n,it,vis); //call Dfd with not visited nodes
      }
      }  
     return;
}

int main(){
    vector<int>vis(8,0); // array to store visited nodes
    vector<int>adj[8]; // array for adjcent nodes
    insert(adj,1,2); 
    insert(adj,2,4);
    insert(adj,4,6);
    insert(adj,6,7);
    insert(adj,7,2);
    // insert(adj,3,7);
    for(int i = 1;i<8;i++){ //for loop for all nodes 
     if(!vis[i]){ // check if visited
        
       dfs(adj,8,i,vis); // call Dfs
     }
    }
    return 0;
}