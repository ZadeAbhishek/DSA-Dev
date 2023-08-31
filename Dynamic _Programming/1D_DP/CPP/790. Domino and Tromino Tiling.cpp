class Solution {
public:
    int numTilings(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
          int prev_one = 1, prev_three = 0,prev_two = 1,curr,mod = 1e9 + 7;
          while(--n)
          {
              curr = (((2 * prev_one)% mod) + prev_three) % mod;
              prev_three = prev_two;
              prev_two = prev_one;
              prev_one = curr;

          }
          return curr;
    }
};