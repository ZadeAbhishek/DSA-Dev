class Solution {
    void solve(int &n, int currSum, int currProduct, int &maxProduct){
        // base case
        if(currSum > n) return;

        // main basse
        if(currSum == n) maxProduct = max(maxProduct,currProduct);

        // repeation
        for(int i = 1 ; i < n ; i++){
            solve(n,currSum+i,currProduct*i,maxProduct);
        }
        return;
    }
public:
    int integerBreak(int n) {
        int maxProduct = INT_MIN;
        solve(n,0,1,maxProduct);
        return maxProduct;
    }
};

/*
java solution top down approch
class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 1; i < dp.length; i++) {
            for (int j = 1; j < n; j++) {
                if (i - j >= 0) dp[i] = Math.max(dp[i], j * dp[i - j]);
            }
        }
        return dp[n];
    }
}
*/


/*
Approach
Why 3s? By testing various numbers, it becomes evident that the number 3 plays a significant role in maximizing the product. For example:

4 = 2 + 2 (product = 4)
5 = 2 + 3 (product = 6)
6 = 3 + 3 (product = 9)
7 = 3 + 2 + 2 (product = 12)
8 = 3 + 3 + 2 (product = 18)
9 = 3 + 3 + 3 (product = 27)
Why not 4s? Anytime we have a 4, we can always split it into two 2s, which will give a better or equal product.

Handling Remainders: When n is divided by 3, the remainder can be 0, 1, or 2:

Remainder 0: n is a perfect multiple of 3. We break n entirely into 3s.
Remainder 1: It's better to take a 3 out and add a 4 (which is split as two 2s). This is because the product of three numbers, 3, 1, and n-4, is less than the product of the two numbers, 4 and n-4.
Remainder 2: We simply multiply the leftover 2 with the product of all 3s.
*/

class Solution {
public:
    int integerBreak(int n) {
        if(n == 3) return 2;
        if(n == 2) return 1;

        int count_of_3 = n / 3; // how many there can be added
        int remainder = n % 3; // is it divisible by three

        switch(remainder){
            case 0: return pow(3,count_of_3) * 1;
            case 1: return pow(3,count_of_3-1)*4;
            default: return pow(3,count_of_3)*2;
        }
    }
};