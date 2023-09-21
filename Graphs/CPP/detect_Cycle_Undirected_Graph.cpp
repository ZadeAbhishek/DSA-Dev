#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// Done lots of mistake but finally done with this dfs 
// i guess i have to practise more
void insert(vector<int> node[],int u ,int v){
          node[u].push_back(v);
          node[v].push_back(u);      
}

bool bfsCheck_cycle(vector<int> node[],int index,vector<int> &vis){
    queue<pair<int,int>> q; // this queue we are going to store the pair value for curr node and its previous
    q.push({index,-1}); // intialization of  the queue
    vis[index] = 1; // marking curr index to be visited
    while(!q.empty()){ //checking if the queue is empty or not 
        int in = q.front().first;   //get front element index from queue
        int prev = q.front().second; // get prev of front element
        //cout<<in<<" "<<prev<<endl; 
        q.pop(); // for the front element 
        for(auto it:node[in]){  // get all node related to fron element
        if(!vis[it]){ //if visited or not 
            vis[it] = 1; // mark visited
            q.push({it,in}); // push to queue
        }
        else if(prev != it){  // if it is visted then check if its prev or not 
            return true;
        }
        }
    }
    return false;
}


int main(){
    vector<int>vis(8,0); // array to store visited nodes
    vector<int>adj[8]; // array for adjcent nodes
    insert(adj,1,2); 
    insert(adj,2,4);
    insert(adj,4,6);
    insert(adj,6,1);
    insert(adj,7,3);
    insert(adj,3,5);
    bool result;
    for(int i = 1;i<8;i++){ //for loop for all nodes 
     if(!vis[i]){ // check if visited
        
      result = bfsCheck_cycle(adj,i,vis); // call bfs
      if(result){break;} 
     }
    }
    cout<<result<<endl;
    return 0;
}