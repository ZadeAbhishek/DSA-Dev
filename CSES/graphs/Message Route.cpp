/*
Time limit: 1.00 s
Memory limit: 512 MB



Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
Input
The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5

*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int computer = 0;
//     int connections = 0;
//     cin>>computer>>connections;
//     vector<vector<int>> hash(computer+1);
//     vector<int> vis(computer+1,0);
//     for(int i = 1 ; i <= connections; i++){
//         int source = 0;
//         int destination = 0;
//         cin>>source>>destination;
//         hash[source].push_back(destination);
//         hash[destination].push_back(source);
//     }
//     int destination = computer; // last computer
//     queue<pair<int,vector<string>>> bfsQueue;
//     string Finalpath = "IMPOSSIBLE";
//     bfsQueue.push({1,{"1"}}); // start node
//     vis[1] = 1;
//     while(!bfsQueue.empty()){
//         int currNode = bfsQueue.front().first;
//         vector<string> currPath = bfsQueue.front().second;
//         bfsQueue.pop();
//         if(currNode == destination){
//             cout<<currPath.size()<<endl;
//             for(auto &x : currPath) cout<<x<<" ";
//             cout<<endl;
//             return 0;
//         }
//         for(auto &next : hash[currNode]){
//             if(!vis[next]){
//                 vis[next] = 1;
//                 string temp = to_string(next);
//                 currPath.push_back(temp);
//                 bfsQueue.push({next,currPath});
//             }
//         }
//     }
//     cout<<Finalpath<<endl;
//     return 0;

// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int computers = 0;
    int connections = 0;
    cin >> computers >> connections;

    vector<vector<int>> graph(computers + 1); // Adjacency list for the graph
    vector<int> visited(computers + 1, 0);   // Visited array to track visited nodes
    vector<int> parent(computers + 1, -1);   // To store the parent of each node for path reconstruction

    // Reading edges and building the graph
    for (int i = 0; i < connections; i++) {
        int source = 0, destination = 0;
        cin >> source >> destination;
        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }

    int destination = computers; // Maija's computer is the last computer
    queue<int> bfsQueue;         // Queue for BFS
    bfsQueue.push(1);            // Start BFS from Uolevi's computer (node 1)
    visited[1] = 1;              // Mark the start node as visited

    // BFS traversal
    while (!bfsQueue.empty()) {
        int currNode = bfsQueue.front();
        bfsQueue.pop();

        for (int next : graph[currNode]) {
            if (!visited[next]) {
                visited[next] = 1;
                parent[next] = currNode; // Track the parent to reconstruct the path
                bfsQueue.push(next);

                // Stop BFS if we reach the destination
                if (next == destination) {
                    break;
                }
            }
        }
    }

    // Check if we reached Maija's computer
    if (!visited[destination]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int node = destination; node != -1; node = parent[node]) {
            path.push_back(node); // Reconstruct the path
        }
        reverse(path.begin(), path.end()); // Reverse to get the correct order

        cout << path.size() << endl; // Minimum number of computers on the route
        for (int node : path) {
            cout << node << " "; // Print the path
        }
        cout << endl;
    }

    return 0;
}   