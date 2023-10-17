class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> graphs(n,vector<int>());
        for(int i = 0 ; i < n ; i++){
            if(leftChild[i] != -1) graphs[i].push_back(leftChild[i]);
            if(rightChild[i] != -1) graphs[i].push_back(rightChild[i]);
        }
        for(int i = 0 ; i < n ; i++){
        vector<int> visited(n,0);
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &next : graphs[curr]){
                if(visited[next] == 0){
                    visited[next] = 1;
                    q.push(next);
                }
                // if cycle is formed
                else return false;
            }
        }
        int count = 0;
        for(auto &check : visited) if(check) count+=check;
        if(count == n) return true;
        else continue;
        }
        
        return false;

    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1) {
                    return false; // More than one incoming edge to a node.
                }
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1) {
                    return false; // More than one incoming edge to a node.
                }
            }
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (root == -1) {
                    root = i;
                } else {
                    return false; // More than one root node found.
                }
            }
        }

        if (root == -1) {
            return false; // No root node found.
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            if (leftChild[node] != -1) {
                if (!visited[leftChild[node]]) {
                    q.push(leftChild[node]);
                } else {
                    return false; // Cycle detected.
                }
            }

            if (rightChild[node] != -1) {
                if (!visited[rightChild[node]]) {
                    q.push(rightChild[node]);
                } else {
                    return false; // Cycle detected.
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false; // Not all nodes are reachable.
            }
        }

        return true;
    }
};
