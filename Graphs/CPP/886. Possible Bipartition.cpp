class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        // union find data stucture can be used here to solve more faster 
        // some twike is done here dfs is used
        vector<vector<int>> adj(n+1);
        for(auto it : dislikes) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> colored(n+1,-1);
        vector<int> visted(n+1,0);
        stack<int> vis_list;
        for(auto i = 1 ; i <= n; i++){
        if(colored[i] == -1){
            colored[i] = 1;
            vis_list.push(i);
        
      
        while(!vis_list.empty())
        {
            int curr = vis_list.top();
            vis_list.pop();
            int curr_color = colored[curr];
            for(auto it : adj[curr]){
                 if(colored[it] == -1){
                 colored[it] = 1-curr_color;
                 vis_list.push(it);
                 }
                 else {
                     if(colored[it] == curr_color) return false;
                 }
                 }
            }
        }
            
        }
        return true;
    }
};