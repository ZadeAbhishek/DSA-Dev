# let arr = [1, 2, 3, 4, 5, 2]

def duplicateElement(arr):
    # first approch is using hashmap
    hash = {}
    for x in arr:
        if hash.get(x,'none') == 'none':
            hash[x] = 1
        else: return True

    return False

def duplicateElement_fast(arr):
    # using fast and slow method
    fast = 0
    slow = 0
    count = 0
    while count != len(arr)-1:
        slow = arr[slow]
        if fast >= len(arr)-1: 
            return False
        fast = arr[arr[fast]]
        if(fast == slow and count != len(arr)-1):
            return True
        count += 1    
    return False        
                    




arr = [1, 2, 3, 4, 5, 6 ,7 ,8 ,9 ,10,11,12,12,14,15,16,17,18]

print(duplicateElement_fast(arr))
