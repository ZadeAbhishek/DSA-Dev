def uBST(n,dp):
    if n <= 1:
        return 1
    
    if dp[n] != 0:
        return dp[n]
    
    for i in range(1,n+1):
        dp[n] += uBST(i - 1,dp) * uBST(n - i,dp)

    return dp[n]

n = 5
dp = [0] * (n+1)
print(uBST(n,dp))    