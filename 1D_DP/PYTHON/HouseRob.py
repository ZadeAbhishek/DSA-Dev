def rob(arr,index,max_rob):
    if index >= len(arr): return max_rob
    return max(rob(arr,index+1,max_rob) , rob(arr,index+2,max_rob+arr[index]))
 

def rob_itr(arr):
    if(len(arr) == 0): return 0
    if(len(arr) == 1): return arr[0]
    if(len(arr) == 2): max(arr[0],arr[1])
    for i in range(2,len(arr)):
        arr[i] = max(arr[i-1],arr[i-2]+arr[i])  
    return arr[len(arr)-1]    
    

arr = [2,7,9,3,1]
print(rob(arr,0,0))
print(rob_itr(arr))