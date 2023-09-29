// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
 
// variables to be used
// in both functions
vector<int> graph[N];
vector<vector<int>> cycles;
 
// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{
 
    // already (completely) visited vertex.
    if (color[u] == 2) {
        return;
    }
 
    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1) {
        vector<int> v;
        cyclenumber++;
           
        int cur = p;
          v.push_back(cur);
 
        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u) {
            cur = par[cur];
              v.push_back(cur);
        }
          cycles.push_back(v);
        return;
    }
    par[u] = p;
 
    // partially visited.
    color[u] = 1;
 
    // simple dfs on graph
    for (int v : graph[u]) {
 
        // if it has not been visited previously
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }
 
    // completely visited.
    color[u] = 2;
}
 
// add the edges to the graph
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
 
// Function to print the cycles
void printCycles(int& cyclenumber)
{
 
    // print all the vertex with same cycle
    for (int i = 0; i < cyclenumber; i++) {
        // Print the i-th cycle
        cout << "Cycle Number " << i + 1 << ": ";
        for (int x : cycles[i])
            cout << x << " ";
        cout << endl;
    }
}
 
// Driver Code
int main()
{
 
    // add edges
    // addEdge(1, 2);
    // addEdge(2, 3);
    // addEdge(3, 4);
    // addEdge(4, 6);
    // addEdge(4, 7);
    // addEdge(5, 6);
    // addEdge(3, 5);
    // addEdge(7, 8);
    // addEdge(6, 10);
    // addEdge(5, 9);
    // addEdge(10, 9);
    // addEdge(10, 11);
    // addEdge(11, 12);
    // addEdge(11, 13);
    // addEdge(12, 13);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(4, 2);
  
 
    // arrays required to color the
    // graph, store the parent of node
    int color[N];
    int par[N];
 
    // store the numbers of cycle
    int cyclenumber = 0;
    int edges = 6;
 
    // call DFS to mark the cycles
    dfs_cycle(1, 0, color, par, cyclenumber);
 
    // function to print the cycles
    printCycles(cyclenumber);
}