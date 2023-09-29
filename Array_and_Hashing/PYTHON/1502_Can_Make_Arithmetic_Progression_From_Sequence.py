# let arr = [-68, -96, -12, -40, 16];
# Aim is to determined if this series is aritmnetic progression or not 

def aRp(arr):
    arr.sort()
    diff = arr[1] - arr[0]
    for x in range(2,len(arr)):
        if(arr[x] - arr[x-1] != diff): return False
        
    return True
   






arr = [-68, -96, -12, -40, 100]
print(aRp(arr))



