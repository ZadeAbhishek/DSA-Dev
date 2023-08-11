#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    class Set_Union {
    public:
        vector<int> parent;
        vector<int> size;
        int set_size;
    };

    // Initializes the set-union data structure
    void set_union_init(Set_Union*& set, int n) {
        for (auto i = 0; i < n + 1; i++) {
            set->parent.push_back(i);
            set->size.push_back(1);
        }
        set->set_size = n;
    }

    // Finds the parent/root of a set using path compression
    int find(Set_Union*& set, int x) {
        if (set->parent[x] == x) {
            return x;
        } else {
            return find(set, set->parent[x]);
        }
    }

    // Unites two sets using union-by-rank
    bool union_sets(Set_Union*& set, int v1, int v2) {
        int x1 = find(set, v1);
        int x2 = find(set, v2);
        
        if (x1 == x2) {
            return true;  // Already connected
        }
        
        if (set->size[x1] >= set->size[x2]) {
            set->size[x1] += set->size[x2];
            set->parent[x2] = x1;
        } else {
            set->size[x2] += set->size[x1];
            set->parent[x1] = x2;
        }
        
        return false;  // Not connected before
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Set_Union* set = new Set_Union();

        // Initialize the set-union data structure with the number of nodes
        set_union_init(set, edges.size());

        vector<int> result;

        // Iterate through the edges and find redundant connection
        for (auto i = 0; i < edges.size(); i++) {
            if (union_sets(set, edges[i][0], edges[i][1])) {
                result.push_back(edges[i][0]);
                result.push_back(edges[i][1]);
                return result;
            }
        }

        return result;  // No redundant connection found
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};  // Edges in the graph
    Solution* solve = new Solution();
    vector<int> result = solve->findRedundantConnection(edges);
    
    // Display result based on whether a redundant connection was found
    if (result.size() == 2) {
        cout << "Redundant connection: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No redundant connection found." << endl;
    }

    return 0;
}
