

def dailyTem(temprature):
    stack = []
    l = len(temprature)-1
    stack.append([l,temprature[l]])
    temprature[l] = 0
    for x in reversed(range(0,l)):
        if temprature[x] > stack[len(stack)-1][1]:
            while len(stack)!=0 and temprature[x] > stack[len(stack)-1][1]:
                stack.pop()
            if len(stack) == 0:
                stack.append([x,temprature[x]])
                temprature[x] = 0
                continue
            
        tempIndex = stack[len(stack)-1][0]
        stack.append([x,temprature[x]])
        temprature[x] = tempIndex - x
    return temprature    

temp = [73,74,75,71,69,72,76,90]
print(dailyTem(temp))

# Input: temperatures = [73,74,75,71,69,72,76,73]
# Output: [1,1,4,2,1,1,0,0]