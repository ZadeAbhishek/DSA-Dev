#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    // Depth-First Search (DFS) function to check if there is a path from 's' to 'd' in the graph.
    bool dfs(std::vector<std::vector<int>>& parent, int s, int d, std::vector<int>& vis) {
        // If we have reached the destination 'd', return true because a path exists.
        if (s == d) return true;
        
        std::stack<int> dfs_stack;
        std::vector<int> temp = parent[d]; // Get the neighbors of the current node 'd'.
        vis[d] = 1; // Mark 'd' as visited.
        
        // Push the neighbors of 'd' onto the stack for traversal.
        for (auto x : temp) dfs_stack.push(x);
        
        while (!dfs_stack.empty()) {
            int n = dfs_stack.top();
            
            // If we have reached the source 's', return true because a path exists.
            if (s == n) return true;
            
            dfs_stack.pop();
            
            // If the neighbor 'n' has not been visited yet, mark it as visited and push its neighbors onto the stack.
            if (!vis[n]) {
                vis[n] = 1;
                std::vector<int> curr = parent[n]; // Get the neighbors of 'n'.
                
                // Push the neighbors of 'n' onto the stack for traversal.
                for (auto x : curr) dfs_stack.push(x);
            }
        }
        
        // If we haven't found a path from 's' to 'd', return false.
        return false;
    }

    // Function to determine if there is a valid path from 'source' to 'destination' in the graph.
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        // Create an adjacency list representation of the graph.
        std::vector<std::vector<int>> parent(n);
        
        // Initialize a vector to keep track of visited nodes.
        std::vector<int> vis(n, 0);
        
        // Populate the adjacency list.
        for (auto it : edges) {
            parent[it[1]].push_back(it[0]); // Add an edge from it[1] to it[0].
            parent[it[0]].push_back(it[1]); // Add an edge from it[0] to it[1].
        }
        
        // Use the DFS function to check if a path exists from 'source' to 'destination'.
        return dfs(parent, source, destination, vis);
    }
};

int main() {
    Solution solution;
    int n = 3; // Number of nodes in the graph.
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}}; // Edge connections in the graph.
    int source = 0; // Source node for the path.
    int destination = 2; // Destination node for the path.

    // Check if there is a valid path from 'source' to 'destination' in the graph.
    bool isValidPath = solution.validPath(n, edges, source, destination);

    // Output the result.
    if (isValidPath) {
        std::cout << "There is a valid path from source to destination." << std::endl;
    } else {
        std::cout << "There is no valid path from source to destination." << std::endl;
    }

    return 0;
}
