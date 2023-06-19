class setUnion:
    def __init__(this):
        this.parent = []
        this.size = []
        this.setSize = None

    def initSet(this,setSize):
        for i in range(setSize+1):
            this.parent.append(i)
            this.size.append(1)

        this.setSize = setSize

    def find(this,x):
        if this.parent[x] == x:
            return x
        return this.find(this.parent[x])

    def union(this,x1,y1):
        x = this.find(x1)
        y = this.find(y1)
        if(x == y): return True

        if this.size[x] >= this.parent[y]:
            this.parent[y] = x
            this.size[x] += this.size[y]
        else:
            this.parent[x] = y
            this.size[y] += this.size[x]

        return False        

if __name__ == '__main__':

    edges = [[1,2],[2,3],[1,3],[3,4],[1,4]]
    set = setUnion()
    set.initSet(4)
    result = []
    for x in edges:
        if set.union(x[0],x[1]):
            result.append([x[0],x[1]])
    
    print(result)

