def checkPalindrom(s):
    buffer = [0] * 129
    for l in s: buffer[ord(l)] += 1
    for x in buffer: buffer[0] += x & 1
    return ((len(s)+1) - buffer[0]) + (buffer[0] > 1)


print(checkPalindrom("madam"))