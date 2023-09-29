uhash = {}
dhash = {}
chash = {}
board = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
print(uhash.get(1))
def nQueen(col):
    if col == len(board): return True
        
    for i in range(0,len(board)):
        c = chash.get(i) == None or not chash[i]
        u = uhash.get((i-col) + (len(board) - 1)) == None or not uhash[(i-col) + (len(board) - 1)]
        d = dhash.get(i+col) == None or not dhash[i+col]
        if  c and u and d:
            chash[i] = True
            uhash[(i-col) + (len(board) - 1)] = True
            dhash[i+col] = True
            board[col][i] = 1
            if(nQueen(col+1)): return True
            chash[i] = False
            uhash[(i-col) + (len(board) - 1)] = False
            dhash[i+col] = False
            board[col][i] = 0

    
    return False   

nQueen(0)
print(board)     