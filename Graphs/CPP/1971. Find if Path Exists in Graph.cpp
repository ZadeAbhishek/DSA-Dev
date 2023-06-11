class Solution {
public:
    bool dfs(vector<vector<int>>& parent,int s, int d, vector<int>& vis){
    if(s == d) return true;
    stack<int> dfs_stack;
    vector<int> temp = parent[d];
    vis[d] = 1;
    for(auto x : temp) dfs_stack.push(x);
    while(! dfs_stack.empty())
    {
        int n = dfs_stack.top();
        if(s == n) return true;
        dfs_stack.pop();
        if(!vis[n]){
        vis[n] = 1;
        vector<int> curr = parent[n];
        for(auto x : curr) dfs_stack.push(x);
    }

    }
    return false;
    
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
     // union find would work efficientyy 
     // idea is if edges belong to same set there is path return true

    vector<vector<int>> parent(n);
    vector<int> vis(n,0);
    for(auto it : edges) parent[it[1]].push_back(it[0]),parent[it[0]].push_back(it[1]);
     
    return dfs(parent,source,destination,vis);

    }
};