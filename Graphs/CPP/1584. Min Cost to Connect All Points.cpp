#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Define the edge structure
struct edge {
    int s;  // Source
    int d;  // Destination
    int w;  // Weight

    // Constructor
    edge(int S, int D, int W) {
        s = S;
        d = D;
        w = W;
    }
};

// Function to calculate Manhattan distance between two points
int mHD(std::vector<int>& p1, std::vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

// Union-Find data structure class
class setUnion {
    std::vector<int> parent;
    std::vector<int> size;

public:
    setUnion(int);
    bool union_edge(int, int);
    int find(int);
};

// Constructor for setUnion
setUnion::setUnion(int size) {
    parent.resize(size);  // Initialize the size of the vectors
    this->size.resize(size);
    for (int i = 0; i < size; i++) {
        this->parent[i] = i;
        this->size[i] = 1;
    }
}

// Union operation for setUnion
bool setUnion::union_edge(int source, int destination) {
    int sourceParent = find(source);
    int destinationParent = find(destination);

    if (sourceParent == destinationParent) return false;

    // Union by rank
    if (this->size[sourceParent] >= this->size[destinationParent])
        parent[destinationParent] = sourceParent, size[sourceParent] += size[destinationParent];
    else
        parent[sourceParent] = destinationParent, size[destinationParent] += size[sourceParent];

    return true;
}

// Find operation for setUnion
int setUnion::find(int point) {
    if (this->parent[point] == point)
        return point;
    else
        return this->find(parent[point]);
}

// Comparator for sorting edges in ascending order of weight
bool cmt(edge& x, edge& y) {
    return x.w < y.w;
}

// Class for Solution using Kruskal's algorithm
class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        std::vector<edge> edges;
        int dis = 0;

        // Generate all possible edges and their weights
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                edges.push_back(edge(i, j, mHD(points[i], points[j])));
            }
        }

        // Sort edges by weight in ascending order
        std::sort(edges.begin(), edges.end(), cmt);

        // Create a setUnion object
        setUnion set(points.size());

        // Iterate through sorted edges and add to the minimum spanning tree if they don't form a cycle
        for (auto& curr : edges) {
            if (set.union_edge(curr.s, curr.d)) {
                dis += curr.w;
            }
        }

        return dis;
    }
};

// Comparator for sorting edges in descending order of weight
bool cmtpq(edge& x, edge& y) {
    return x.w > y.w;
}

// Class for Solution2 using Kruskal's algorithm with priority queue
class Solution2 {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        // Priority queue to sort edges by weight in descending order
        std::priority_queue<edge, std::vector<edge>, decltype(&cmtpq)> pq(&cmtpq);
        int dis = 0;

        // Generate all possible edges and their weights
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                pq.push(edge(i, j, mHD(points[i], points[j])));
            }
        }

        // Create a setUnion object
        setUnion set(points.size());

        // Iterate through priority queue of sorted edges and add to the minimum spanning tree if they don't form a cycle
        while (!pq.empty()) {
            edge curr = pq.top();
            pq.pop();

            if (set.union_edge(curr.s, curr.d)) {
                dis += curr.w;
            }
        }

        return dis;
    }
};

int main() {
    // Sample points as input
    std::vector<std::vector<int>> points = {{0, 0}, {1, 2}, {3, 1}, {2, 3}};

    // Create instances of Solution and Solution2
    Solution solution;
    Solution2 solution2;

    // Calculate the minimum cost using the first solution
    int minCost1 = solution.minCostConnectPoints(points);

    // Calculate the minimum cost using the second solution
    int minCost2 = solution2.minCostConnectPoints(points);

    // Print the results
    std::cout << "Minimum cost using Solution: " << minCost1 << std::endl;
    std::cout << "Minimum cost using Solution2: " << minCost2 << std::endl;

    return 0;
}
