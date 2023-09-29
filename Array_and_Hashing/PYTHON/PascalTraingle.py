# 1
# 1 1
# 1 2 1
# 1 3 3 1
# 1 4 6 4 1

def pascalTriangle(level):
    res = []

    for i in range(0,level):
        temp = []
        for j in range(0,i+1): # strange Behaviour of loops in python
            if i == j:
                temp.append(1)
            elif j == 0:
                temp.append(1)
            else :
                temp.append(res[i-1][j-1] + res[i-1][j])
        res.append(temp)        
    return res


print(pascalTriangle(5))                    

