#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // Create an adjacency list representation of the graph
        vector<vector<int>> adj(n + 1);
        for (auto it : dislikes) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> colored(n + 1, -1);
        vector<int> visited(n + 1, 0);
        stack<int> visit_list;

        for (int i = 1; i <= n; i++) {
            if (colored[i] == -1) {
                colored[i] = 1;
                visit_list.push(i);

                while (!visit_list.empty()) {
                    int curr = visit_list.top();
                    visit_list.pop();
                    int curr_color = colored[curr];

                    for (auto it : adj[curr]) {
                        if (colored[it] == -1) {
                            colored[it] = 1 - curr_color;
                            visit_list.push(it);
                        } else {
                            if (colored[it] == curr_color) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    int n = 4;
    vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};

    bool canPartition = solution.possibleBipartition(n, dislikes);

    if (canPartition) {
        cout << "It's possible to bipartition the group." << endl;
    } else {
        cout << "It's not possible to bipartition the group." << endl;
    }

    return 0;
}
