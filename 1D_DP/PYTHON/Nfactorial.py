def nfac(n):
    if(n == 0 or n == 1): return 1
    return n * nfac(n-1)


x = nfac(3)
print(x)
