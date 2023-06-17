def swap(a,i,j):
    temp = a[i]
    a[i] = a[j]
    a[j] = temp

def reverseString(temp):
    
    a = list(temp) # We have to convert string arr into list becuase we cannot directly swap  
    i = 0
    j = len(a)-1

    while i <= j:
       swap(a,i,j)
       i += 1
       j -= 1

    temp = ""
    for x in a:
        temp += x

    print(temp)  


reverseString("edaZ kehsihbA ma I")