#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build the graph as an adjacency list
        vector<vector<int>> graph(n);
        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        vector<vector<int>> result;  // Store critical connections
        vector<int> discovery(n, -1);  // Discovery time of each node
        vector<int> low(n, -1);        // Low-link value of each node
        int time = 0;

        // Start DFS from the first node
        dfs(0, -1, time, graph, discovery, low, result);
        return result;
    }

private:
    void dfs(int node, int parent, int& time, vector<vector<int>>& graph, 
             vector<int>& discovery, vector<int>& low, vector<vector<int>>& result) {
        discovery[node] = low[node] = time++;  // Set discovery and low-link values

        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;  // Skip the edge leading to the parent

            if (discovery[neighbor] == -1) {  // If the neighbor is not visited
                dfs(neighbor, node, time, graph, discovery, low, result);

                // Update low-link value after visiting the neighbor
                low[node] = min(low[node], low[neighbor]);

                // Check if the edge is a bridge
                if (low[neighbor] > discovery[node]) {
                    result.push_back({node, neighbor});
                }
            } else {
                // Update low-link value based on back edge
                low[node] = min(low[node], discovery[neighbor]);
            }
        }
    }
};


int main(){
    vector<vector<int>> graph = {{0,1},{1,2},{2,0},{1,3}};
    Solution* solve = new Solution();
    auto result = solve->criticalConnections(4,graph);
    for(auto x : result) cout<<x[0]<<" "<<x[1]<<endl;
    return 0;
}