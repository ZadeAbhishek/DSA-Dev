/*
Time limit: 1.00 s
Memory limit: 512 MB



There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.
Input
The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,\dots,n.
Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.
Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.
Output
Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
 */


// Try making Adjency list bidiretional

// We need to use bipartile graph logic here where we need to make connections
// This can be done using BFS and DFS
// if current Graphs is not colored. Color it and make alternate of it 
// if colored check the if alternated if not return impossible

#include<bits/stdc++.h>
using namespace std;

int main() {
    int people, friendShip;
    cin >> people >> friendShip;
    
    vector<vector<int>> graph(people + 1); // 1-based index
    vector<int> colours(people + 1, -1);   // -1 indicates uncolored nodes

    // Build the undirected graph
    for (int i = 0; i < friendShip; i++) {
        int source, destination;
        cin >> source >> destination;
        graph[source].push_back(destination);
        graph[destination].push_back(source); // undirected edge
    }

    // Check all nodes (for disconnected graphs)
    for (int i = 1; i <= people; i++) {
        if (colours[i] == -1) { // Unvisited node
            colours[i] = 1; // Assign first color
            stack<int> dfsStack;
            dfsStack.push(i);

            while (!dfsStack.empty()) {
                int currNode = dfsStack.top();
                dfsStack.pop();
                int currColour = colours[currNode];

                for (auto x : graph[currNode]) {
                    int nodeColour = colours[x];
                    if (nodeColour == -1) {
                        // Assign alternate color
                        colours[x] = (currColour == 1 ? 2 : 1);
                        dfsStack.push(x);
                    } else if (nodeColour == currColour) {
                        // Conflict found
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    // Print the assigned colors
    for (int i = 1; i <= people; i++) {
        cout << colours[i] << " ";
    }
    cout << endl;
    return 0;
}