#include <iostream>
#include <vector>

class Solution {
public:
    // DFS backtraking
    void allPathsSourceTarget(std::vector<std::vector<int>>& graph, std::vector<int>& temp, std::vector<std::vector<int>>& result, int curr, std::vector<int>& vis) {
        if (curr == graph.size() - 1) {
            result.push_back(temp);
        } else {
            for (auto iterator : graph[curr]) {
                if (!vis[iterator]) {
                    vis[iterator] = 1;
                    temp.push_back(iterator);
                    allPathsSourceTarget(graph, temp, result, iterator, vis);
                    temp.pop_back();
                    vis[iterator] = 0;
                }
            }
        }
    }

    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<int> vis(graph.size(), 0);
        std::vector<int> temp;
        std::vector<std::vector<int>> result;
        temp.push_back(0);
        allPathsSourceTarget(graph, temp, result, 0, vis);
        return result;
    }
};

void printPaths(std::vector<std::vector<int>>& paths) {
    for (const std::vector<int>& path : paths) {
        for (int node : path) {
            std::cout << node << " -> ";
        }
        std::cout << "\b\b\b   " << std::endl; // Remove the last "->" and add newline
    }
}

int main() {
    Solution solution;
    std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    std::vector<std::vector<int>> paths = solution.allPathsSourceTarget(graph);
    std::cout << "All paths from source to target:" << std::endl;
    printPaths(paths);
    return 0;
}
