def cmt(x):
    return x[2]



arr = [[0,1,2],[2,3,9],[9,2,7],[6,5,1]]
arr.sort(key=cmt)
print(arr)