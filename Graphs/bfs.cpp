#include <iostream>

#include<bits/stdc++.h>

using namespace std;

void insert(vector < int > node[], int u, int v) {
  node[u].push_back(v);
  node[v].push_back(u);
}

void bfs(vector < int > node[], int len) {
  vector < int > result;
  int vis[len + 1] = {
    0
  };
  int index = 1;
  while (index != len) {
    if (vis[index] == 0) {
      vis[index] = 1;
      queue < int > bfs;
      bfs.push(index);
      while (!bfs.empty()) {
        int in = bfs.front();
        result.push_back( in );
        cout << in ;
        bfs.pop();
        for (auto it: node[ in ]) {
          if (vis[it] == 0) {
            vis[it] = 1;
            bfs.push(it);
          }
        }
      }
    }
    index++;
  }

}

int main() {
  // code for breath first Search
  int lenght;
  cout << "Input lenght of array: ";
  cin >> lenght;
  vector < int > graph[lenght + 1];
  insert(graph, 1, 2);
  insert(graph, 2, 4);
  insert(graph, 5, 4);
  bfs(graph, lenght);

  return 0;
}