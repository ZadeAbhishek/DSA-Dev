class Solution {
        const int mod = 1e9 + 7;
public:
   
    long long getvalid(int n, vector<long long> &memo){
         if(n == 0) return 1;

         if(memo[n] != -1) return memo[n];

         return memo[n] = getvalid(n-1,memo) * (2 * n - 1) * (n) % mod;
    }


    int countOrders(int n) {
        vector<long long> memo;
        memo.resize(n+1,-1);
        return getvalid(n,memo);
    }
};