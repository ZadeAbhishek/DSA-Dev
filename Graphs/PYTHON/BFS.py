from collections import deque

def insert(edges,u,v):
    edges[u].append(v)
    edges[v].append(u)

def BFS(edges):
    vis = [False] * len(edges)
    bfs = []
    for e in range(len(edges)):
        queue = deque()
        if(vis[e] == False):
            vis[e] = True
            queue.append(e)
        while(len(queue)!=0):
            curr = queue.popleft()
            bfs.append(curr)
            for x in edges[curr]:
                if(vis[x] == False):
                    vis[x] = True
                    queue.append(x)
    return bfs 

Nodes = 8
edges = [[] for i in range(Nodes+1)]
insert(edges,0,1)
insert(edges,0,2)
insert(edges,1,3)
insert(edges,4,5)
insert(edges,3,5)
insert(edges,6,8)
result = BFS(edges)
print(result)

