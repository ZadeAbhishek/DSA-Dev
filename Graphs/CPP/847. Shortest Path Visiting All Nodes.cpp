/*
    1. Call BFS from every node
    2. Mask is the how many nodes we are visited.
    3. When we visited all the nodes then we will return distance(dist)
    4. How mask will keep track that how many node is visited ?
    Ans :-   i) Let's n = 5 (number of nodes)
             ii) allVisitedMask = 11111; When all node will be visted then musk will be allVisitedMask
                 1 = 1 = (2^1)-1
                 11 = 3 = (2^2)-1
                 111 = 7 = (2^3)-1
                 So, for n nodes allVisitedMask = 1111...111 (n-times) = (2^n)-1 = (1<<n)-1;
             iii) Initially,
                mask of 0-th node is 00001 = 2^0 = 1<<0 
                mask of 1-th node is 00010 = 2^1 = 1<<1
                mask of 2-nd node is 00100 = 2^2 = 1<<2
                mask of 3-rd node is 01000 = 2^3 = 1<<3
                mask of 4-th node is 10000 = 2^4 = 1<<4
                Then, mask of i-th node is 1<<i or 2^i
             iv) Suppose we can visit 0-th node to 1-th and 2-nd node than after visiting the mask wiil be
                 00011 and 00101 respectively.
                 
                 How this can be maintain ?
                 Ans :- mask of 0-th | mask of 1-th = 00001 | 00010 = 00011
                        mask of 0-th | mask of 2-th = 00001 | 00100 = 00101
                        So, if we visit j-th node from i-th node then mask will be updated to =
                        mask till i-th node | mask of j-th node
             v) When cuurent mask of current node will be allVisitedMask then we will stop and will
                sure thar all nodes are visited then we will check the comp. curr dist with ans.
             vi) We will keep track of already visited path using currNode and currMask
             
             2 --- 1 ---- 0
             |\    |
             | \   |
             |  \  |
             |   \ |
             3    4
             
             Start visiting the nodes from every node -::
             
             0 : (0) -> (0,1) -> (1,0){don't visit (1,0) again reson is bellow}
             1 : (1) -> (1,0),(1,4),(1,)
             2 : (2) -> (2,1),(2,4),(2,3)
             3 : (3) -> (3,2)
             4 : (4) -> (4,1),(4,2)
             
             0 : (0) -> (0,1) -> (1,0){don't visit (1,0) again reson is bellow}
             Ans : You are visiting (1,0) in setps=2 but (1,0) path is already visited by staring node (1) in
                   steps = 1 . So, revisiting (1,0) will increas the steps but we want minimum steps that's
                   why we will not visit the same path that are already visited with smaller steps.
                   
             --> We will keep tarck the visited path using set<pair<currNode,currMask>>
             
             
*/

class Solution {
    struct edge{
        int currNode;
        int currMask;
        int currDistance = 0;
        edge(int N, int M, int D){
            currNode = N;
            currMask = M;
            currDistance = D;
        }
    };

struct visitedEdge {
    int currNode;
    int currMask;
    
    visitedEdge(int N, int M) : currNode(N), currMask(M) {}
    
    // Define comparison operator for sorting in the set
    bool operator<(const visitedEdge& other) const {
        if (currNode != other.currNode) {
            return currNode < other.currNode;
        }
        return currMask < other.currMask;
    }
};
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisited = (1 << n) - 1; // 11111 << depend on visited side
        queue<edge> que; // que to store node in BfS traverse
        set<visitedEdge> visited; // uniquly check if the node is visited or not
        for(int i = 0 ; i < n ; i++){
            // insert all initial nodes to start with
            que.push(edge(i,(1 << i),0));
            visited.insert(visitedEdge(i,(1 << i)));
        }
        while(!que.empty()){
            edge curr = que.front();
            que.pop();
            int currNode = curr.currNode;
            int currMask = curr.currMask;
            int currDistance = curr.currDistance;
            // check if we reached the end
            if(currMask == allVisited) return currDistance;
            // traverse all 
            for(auto &nextNode : graph[currNode]){
                int nextMask = currMask | (1 << nextNode);
                // check if this combination is present in set
                if(visited.count(visitedEdge(nextNode,nextMask)) == 0){
                    que.push(edge(nextNode,nextMask,currDistance+1));
                    visited.insert(visitedEdge(nextNode,nextMask));
                }
            }

        }  

        return 0;
    }
};

// more efficient
class Solution {
    struct edge {
        int currNode;
        int currMask;
        int currDistance = 0;
        edge(int N, int M, int D) : currNode(N), currMask(M), currDistance(D) {}
    };

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisited = (1 << n) - 1; // 11111 << depends on visited side
        queue<edge> que; // queue to store nodes in BFS traverse
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false)); // efficiently track visited nodes

        for (int i = 0; i < n; i++) {
            // Insert all initial nodes to start with
            que.push(edge(i, (1 << i), 0));
            visited[i][1 << i] = true;
        }

        while (!que.empty()) {
            edge curr = que.front();
            que.pop();
            int currNode = curr.currNode;
            int currMask = curr.currMask;
            int currDistance = curr.currDistance;
            
            // Check if we reached the end
            if (currMask == allVisited) return currDistance;

            // Traverse neighbors
            for (int nextNode : graph[currNode]) {
                int nextMask = currMask | (1 << nextNode);
                
                // Check if this combination is not visited
                if (!visited[nextNode][nextMask]) {
                    que.push(edge(nextNode, nextMask, currDistance + 1));
                    visited[nextNode][nextMask] = true;
                }
            }
        }

        return 0;
    }
};
