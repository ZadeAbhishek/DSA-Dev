# function init() {
#     let w = [10, 20, 30];
#     let c = [60, 100, 120];
#     let W = 50;
#     let memo = [];
#     for (let i = 0; i < w.length; i++) memo.push(0);
#     let CMax = -99999999;
#     let bag = 0;
#     let CurrCost = 0;

#     let result = dp(w, c, W, memo, CMax, bag, CurrCost);

#     console.log(result);
# }

def ksnap(W,w,c,cmax,bag,Currcost,memo):
    
    if bag > W: return cmax
    
    cmax = max(cmax,Currcost)
   
    for index in range(0,len(w)):
        if memo[index] == False:
            bag += w[index]
            Currcost += c[index]
            memo[index] = True
            cmax = ksnap(W,w,c,cmax,bag,Currcost,memo)
            memo[index] = False
            bag -= w[index]
            Currcost -= c[index]
    
    return cmax  


W = 50
w = [10, 20, 30]
c = [60, 100, 120]
bag = 0
memo = {}
for x in range(0,len(w)): memo[x] = False
cmax = 0
Currcost = 0

cmax = ksnap(W,w,c,cmax,bag,Currcost,memo)

print(cmax)
