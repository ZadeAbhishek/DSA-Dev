class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // we can solve this using topological Sort
        unordered_map<int, vector<int>> graph;
        vector<int> in_degree(n + 1, 0);
        for (auto& x : relations) {
            graph[x[1]].push_back(x[0]); // Fix the direction of the edges
            in_degree[x[0]]++;
        }
        vector<int> dis = time;
        dis.insert(dis.begin(), 0);
        queue<int> q;

        // push all nodes with indegree 0
        for (int i = 1; i <= n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            for (int next_Course : graph[course]) {
                dis[next_Course] = max(dis[next_Course], dis[course] + time[next_Course - 1]); // Correct the time calculation
                
                in_degree[next_Course]--;
                if (in_degree[next_Course] == 0) {
                    q.push(next_Course);
                }
            }
        }
        return *std::max_element(dis.begin(), dis.end());
    }
};q