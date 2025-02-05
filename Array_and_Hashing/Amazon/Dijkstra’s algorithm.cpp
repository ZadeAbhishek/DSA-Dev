#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int weight;
};

int dijkstra(int src, int V, const vector<vector<Edge>>& adj, vector<int>& dist) {
    const int INF = 1e7;
    dist.assign(V + 1, INF);
    vector<bool> visited(V + 1, false);
    dist[src] = 0;

    using P = pair<int, int>; // (distance, vertex)
    priority_queue<P, vector<P>, greater<P>> pq; // min heap
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
    return 0;
}

int main() {
    int N, M;
    cin >> N >> M;
    const int INF = 1e7;
    
    // Initialize adjacency list for the graph
    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist;
    dijkstra(1, N, adj, dist);

    // Print distances from source 1 to all other vertices
    for (int i = 2; i <= N; ++i) {
        if (i > 2) cout << " ";
        cout << (dist[i] == INF ? 1000000000 : dist[i]);
    }
    return 0;
}