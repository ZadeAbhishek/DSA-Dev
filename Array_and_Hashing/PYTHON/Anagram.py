# ord('a') will give 97 ord() will give char into ASCII code
# chr('97') vise versa

def anagram(x,y):
    buffer = [0] * 128
    for c in x: 
        buffer[ord(c)] += 1 
    for c in y: 
        buffer[ord(c)] -= 1

    for x in buffer:
        if x != 0:
            return False

    return True        


x = "aba"
y = "abaccc"
print(anagram(x,y))
