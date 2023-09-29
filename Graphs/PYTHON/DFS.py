def insert(edges,u,v):
    edges[u].append(v)
    edges[v].append(u)





def DFS(edges,memo,result,x):
    result.append(x)
    memo[x] = True
    for i in edges[x]:
        if memo[i] == False:
            memo[i] = True
            DFS(edges,memo,result,i)   
    return        



Nodes = 8
edges = [[] for i in range(Nodes+1)]
insert(edges,0,1)
insert(edges,0,2)
insert(edges,1,3)
insert(edges,4,5)
insert(edges,3,5)
insert(edges,6,8)
memo = [False] * (Nodes+1)
result = []
for x in range(len(edges)):
    if memo[x] == False:
        memo[x] = True
        DFS(edges,memo,result,x)
print(result)