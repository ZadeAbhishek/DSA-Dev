// kahn's algorithm for topological sort 
#include <iostream>

#include<bits/stdc++.h>

using namespace std;

// Done lots of mistake but finally done with this dfs 
// i guess i have to practise more
void insert(vector < int > node[], int u, int v) {
  node[u].push_back(v);
  // node[v].push_back(u);      
}

class Solution {
  public:
    vector < int > topoLogicalSort(vector < int > node[], int size) {
      // step 1 we need to calculate in degree of each node
      int node_size = size;
      vector < int > inDegree(size, 0);
      for (auto index = 0; index < size; index++) {
        for (auto secIndex: node[index]) {
          inDegree[secIndex] += 1;
        }
      }

      // step add all elment with indegree 0 to queue
      queue < int > q;
      for (auto index = 0; index < size; index++) {
        if (inDegree[index] == 0) {
          q.push(index);
        }
      }

      // step 3 traverse all nodes 
      int index = 0;
      vector < int > order_map(size, 0);
      while (!q.empty()) {
        int current = q.front();
        q.pop();
        order_map[index++] = current;
        for (auto secIndex: node[current]) {
          inDegree[secIndex] -= 1;
          if (inDegree[secIndex] == 0) {
            q.push(secIndex);
          }
        }

      }
      if (index != size) {
        return {};
      }
      return order_map;
    }
};

int main() {
  vector < int > vis(8, 0); // array to store visited nodes
  vector < int > adj[8]; // array for adjcent nodes
  insert(adj, 0, 1);
  insert(adj, 1, 2);
  insert(adj, 1, 6);
  insert(adj, 2, 4);
  insert(adj, 4, 6);
  insert(adj, 6, 7);
  insert(adj, 7, 3);
  insert(adj, 3, 5);
  Solution * solve = new Solution();
  vector < int > result = solve -> topoLogicalSort(adj, 8);
  for (auto index = 0; index < result.size(); index++) {
    cout << result[index] << " ";
  }
  cout << endl;
}