
// out of my world :(
class Solution {
public:

   int mod = 1000000007;
int dp_pascal[101][101] = {}, dp[101] = {};
long comb(int n, int m) {
    return n == 0 || m == 0 ? 1 :
        dp_pascal[n][m] ? dp_pascal[n][m] : 
            dp_pascal[n][m] = (comb(n - 1, m) + comb(n, m - 1)) % mod;
}
int numMusicPlaylists(int N, int L, int K) {
    if (K > N)
        return 0;
    if (dp[N] == 0) {
        for (auto i = 0; i < L; ++i)
            dp[N] = (long)max(1, dp[N]) * (N - min(i, K)) % mod;
        for (long i = 1; i < N; ++i)
            dp[N] = (mod + dp[N] - comb(N - i, i) * numMusicPlaylists(i, L, K) % mod) % mod;
    }
    return dp[N];
}
};