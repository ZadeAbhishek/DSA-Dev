/* tarjan's algorithm  */
/* Source : https://www.youtube.com/watch?v=CiDPT1xMKI0&t=703s&ab_channel=CodeHelp-byBabbar */

  
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Depth-First Search function to find critical connections
    void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<vector<int>>& result, int parent, vector<int>& distance, int curr, vector<int>& low, int& timer) {
        vis[curr] = 1;
        distance[curr] = low[curr] = timer++;

        for (int neighbor : adj[curr]) {
            if (neighbor == parent)
                continue;

            if (vis[neighbor] == 0) {
                // Recursively explore the unvisited neighbor
                dfs(adj, vis, result, curr, distance, neighbor, low, timer);

                // Update the low value for the current node
                low[curr] = min(low[curr], low[neighbor]);

                // Check if this edge is a critical connection
                if (low[neighbor] > distance[curr]) {
                    result.push_back({curr, neighbor});
                }
            } else {
                // Update the low value for the current node using the distance of the visited neighbor
                low[curr] = min(low[curr], distance[neighbor]);
            }
        }
    }

    // Function to find critical connections using Tarjan's algorithm
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create an adjacency list
        vector<vector<int>> adj(n);
        for (auto& x : connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        // Initialize distance, low, and visited vectors
        vector<int> distance(n, -1);
        vector<int> low(n, -1);
        vector<int> vis(n, 0);

        int parent = -1;
        int timer = 0;
        vector<vector<int>> result;

        // Perform DFS for each unvisited node
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(adj, vis, result, parent, distance, i, low, timer);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example input: Number of nodes and list of connections
    int n = 7;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}};

    // Call the criticalConnections function to find critical connections
    vector<vector<int>> criticalConnections = solution.criticalConnections(n, connections);

    // Display the critical connections
    cout << "Critical Connections:" << endl;
    for (const vector<int>& conn : criticalConnections) {
        cout << conn[0] << " - " << conn[1] << endl;
    }

    return 0;
}

/*
The time complexity of the provided code for finding critical connections using Tarjan's 
algorithm can be analyzed as follows:

1. **Building the Adjacency List**: Constructing the adjacency list takes O(E) time, where E 
     is the number of edges in the graph. This is because you iterate through each edge and 
     add its vertices to the adjacency list.

2. **DFS Traversal**: The main work of the algorithm is done during the depth-first 
     traversal of the graph. The DFS function is called once for each node, and within 
     each call, you process each edge only once. Therefore, the overall time complexity of 
     the DFS traversal is O(V + E), where V is the number of vertices and E is the number 
     of edges.

   Within the DFS function, the operations performed are generally constant time or based 
   on the size of the adjacency list for the current node. So, the complexity of the DFS 
   function itself is typically considered O(degree), where "degree" is the maximum number 
   of edges from a single vertex. In the worst case, where the graph is a complete graph, 
   the degree is V - 1, making it O(V) for each DFS call.

3. **Overall Complexity**: Combining the two main components, the total time complexity 
     of the algorithm is O(V + E + V), which simplifies to O(V + E). Since E can be at most 
     V^2 (in a complete graph), the dominant term here is E. Hence, the final time 
     complexity is often approximated as O(E), which is essentially linear with respect to 
     the number of edges.

In summary, the time complexity of the algorithm is linear with respect to the number of 
edges in the graph. This makes it efficient for sparse graphs, where the number of edges 
is much smaller than the number of vertices. However, in dense graphs, where the number of 
edges approaches V^2, the complexity might become less efficient.

*/
