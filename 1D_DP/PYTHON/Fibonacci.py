memo = {}

def fib(n):
    if n == 0 or n == 1:
        memo[n] = n
        return n
    if n not in memo:
        memo[n] = fib(n-1) + fib(n-2)
    
    return memo[n]


result = fib(10)
print(result)
print(list(memo.values()))     